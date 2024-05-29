#include <iostream>
#include <memory>

int main()
{
    // std::string str="hi";
    int *p = nullptr;
    // std::cout << *p << std::endl;
    std::unique_ptr<std::string> p1 = std::make_unique<std::string>("hello");
    std::cout << *p1 << std::endl;
    std::cout << &p1 << std::endl;
    std::cout << &(*p1) << std::endl;

    std::unique_ptr<std::string> p2 = std::move(p1);
    std::cout << &p1 << std::endl;
    std::cout << p1.get() << std::endl;

    std::unique_ptr<int> p3 = std::make_unique<int>(10);

    std::cout << *p2 << std::endl;
    std::cout << &p2 << std::endl;
    std::cout << &(*p2) << std::endl;

    std::shared_ptr<std::string> s1 = std::move(p2);
    std::cout << s1.get() << std::endl;
    std::cout << s1.use_count() << std::endl;

    // std::unique_ptr<std::string>p4=s1;
    // std::cout<<p4.get()<<std::endl;
    
    std::shared_ptr<std::string> s2 = std::move(p2);
    std::cout << s2.get() << std::endl;
    std::cout << s2.use_count() << std::endl;
}