#include <iostream>

class ControlBlock
{
    int refCount;

public:
    int getRefCount()
    {
        return refCount;
    }
    void incrementRefCount()
    {
        refCount++;
    }
    void decrementRefCount()
    {
        --refCount;
    }
};

template <typename T>
class Shared_Pointer
{
    T *ptr = nullptr;
    ControlBlock *cb;

public:
    Shared_Pointer()
    {
        cb = new ControlBlock();
        cb->incrementRefCount();
        std::cout << "Pointer created" << std::endl;
    }

    Shared_Pointer(T *new_ptr) : ptr(new_ptr)
    {
        cb = new ControlBlock();
        cb->incrementRefCount();
        std::cout << "Pointer created" << std::endl;
    }

    ~Shared_Pointer()
    {
        cb->decrementRefCount();
        std::cout << "Destructor" << std::endl;

        if (cb->getRefCount() == 0)
        {
            std::cout << "Pointer deleted" << std::endl;
            delete cb;
            delete ptr;
        }
    }

    Shared_Pointer(const Shared_Pointer &other)
    {
        std::cout << "Cop.y constructor" << std::endl;
        ptr = other.ptr;
        cb = other.cb;
        cb->incrementRefCount();
    }

    Shared_Pointer &operator=(const Shared_Pointer &other)
    {
        std::cout << "Copy assignment" << std::endl;
        ptr = other.ptr;
        cb = other.cb;
        cb->incrementRefCount();
        return *this;
    }

    Shared_Pointer(Shared_Pointer &&other)
    {
        std::cout << "move constructor" << std::endl;
        ptr = other.ptr;
        cb = other.cb;
        other.ptr = nullptr;
        cb->incrementRefCount();
    }

    Shared_Pointer &operator=(Shared_Pointer &&other)
    {
        if (this != &other)
        {
            std::cout << "move assignment" << std::endl;
            ptr = other.ptr;
            cb = other.cb;
            other.ptr = nullptr;
            cb->incrementRefCount();
        }
        return *this;
    }

    int use_count()
    {
        return cb->getRefCount();
    }
};

class Base
{
public:
    int value;

    Base(int val) : value(val)
    {
        std::cout << "Base created" << std::endl;
    }

    ~Base()
    {
        std::cout << "Base Destroyed" << std::endl;
    }
};

int main()
{
    Shared_Pointer<Base> sp1(new Base(2));
    std::cout << sp1.use_count() << std::endl;

    Shared_Pointer<Base> sp2 = sp1;
    std::cout << sp1.use_count() << std::endl;
    std::cout << sp2.use_count() << std::endl;

    {
        Shared_Pointer<Base> sp3(std::move(sp1));
        std::cout << sp1.use_count() << std::endl;
        std::cout << sp2.use_count() << std::endl;
        std::cout << sp3.use_count() << std::endl;
    }

    Shared_Pointer<Base> sp4;
    sp4 = sp1;
    std::cout << sp1.use_count() << std::endl;
    std::cout << sp2.use_count() << std::endl;
    // std::cout << sp3.use_count() << std::endl;
    std::cout << sp4.use_count() << std::endl;
    return 0;
}