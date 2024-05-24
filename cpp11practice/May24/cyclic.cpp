#include <iostream>
#include <memory>

class B;

class A
{
    // std::shared_ptr<B> sP1; // use weak_ptr instead to avoid CD
    std::weak_ptr<B> wp1;

public:
    A() { std::cout << "A()" << std::endl; }
    ~A() { std::cout << "~A()" << std::endl; }

    void setShared(std::shared_ptr<B> &p)
    {
        wp1 = p;
    }
};

class B
{
    std::shared_ptr<A> sP1;

public:
    B() { std::cout << "B()" << std::endl; }
    ~B() { std::cout << "~B()" << std::endl; }

    void setShared(std::shared_ptr<A> &p)
    {
        sP1 = p;
    }
};

int main()
{
    std::shared_ptr<A> aPtr(new A);
    std::shared_ptr<B> bPtr(new B);
    {
        aPtr->setShared(bPtr);
        std::cout << aPtr.use_count() << std::endl;
        std::cout << bPtr.use_count() << std::endl;

        bPtr->setShared(aPtr);
        std::cout << aPtr.use_count() << std::endl;
        std::cout << bPtr.use_count() << std::endl;

        std::shared_ptr<A> newPtr(aPtr);
        std::cout << aPtr.use_count() << std::endl;
        std::cout << bPtr.use_count() << std::endl;
    }
    std::cout << aPtr.use_count() << std::endl;
    std::cout << bPtr.use_count() << std::endl;

    return 0;
}