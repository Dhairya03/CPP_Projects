#include <iostream>

class ControlBlock
{
public:
    int shared_count;
    int weak_count;

    ControlBlock() : shared_count(1), weak_count(0) {}
};

// template <typename T>
// class Shared_pointer
// {
// private:
//     T *ptr;
//     ControlBlock *ctrl_block;

// public:
//     Shared_pointer(T *p = nullptr) : ptr(p), ctrl_block(nullptr)
//     {
//         if (ptr)
//         {
//             ctrl_block = new ControlBlock();
//         }
//     }

//     ~Shared_pointer()
//     {
//         release();
//     }

//     Shared_pointer(const Shared_pointer &other) : ptr(other.ptr), ctrl_block(other.ctrl_block)
//     {
//         if (ctrl_block)
//         {
//             ++ctrl_block->shared_count;
//         }
//     }

//     Shared_pointer &operator=(const Shared_pointer &other)
//     {
//         if (this != &other)
//         {
//             release();
//             ptr = other.ptr;
//             ctrl_block = other.ctrl_block;
//             if (ctrl_block)
//             {
//                 ++ctrl_block->shared_count;
//             }
//         }
//         return *this;
//     }

//     T &operator*() const { return *ptr; }
//     T *operator->() const { return ptr; }
//     T *get() const { return ptr; }

//     void release()
//     {
//         if (ctrl_block)
//         {
//             if (--ctrl_block->shared_count == 0)
//             {
//                 delete ptr;
//                 if (ctrl_block->weak_count == 0)
//                 {
//                     delete ctrl_block;
//                 }
//             }
//             ptr = nullptr;
//             ctrl_block = nullptr;
//         }
//     }

//     ControlBlock *get_control_block() const { return ctrl_block; }
// };

template <typename T>
class Weak_pointer;

template <typename T>
class Shared_pointer
{
private:
    T *ptr;
    ControlBlock *ctrl_block;

public:
    explicit Shared_pointer(T *p = nullptr) : ptr(p), ctrl_block(nullptr)
    {
        if (ptr)
        {
            ctrl_block = new ControlBlock();
        }
    }

    ~Shared_pointer()
    {
        release();
    }

    Shared_pointer(const Shared_pointer &other) : ptr(other.ptr), ctrl_block(other.ctrl_block)
    {
        if (ctrl_block)
        {
            ++ctrl_block->shared_count;
        }
    }

    Shared_pointer &operator=(const Shared_pointer &other)
    {
        if (this != &other)
        {
            release();
            ptr = other.ptr;
            ctrl_block = other.ctrl_block;
            if (ctrl_block)
            {
                ++ctrl_block->shared_count;
            }
        }
        return *this;
    }

    T &operator*() const { return *ptr; }
    T *operator->() const { return ptr; }
    T *get() const { return ptr; }

    void release()
    {
        if (ctrl_block)
        {
            if (--ctrl_block->shared_count == 0)
            {
                delete ptr;
                if (ctrl_block->weak_count == 0)
                {
                    delete ctrl_block;
                }
            }
            ptr = nullptr;
            ctrl_block = nullptr;
        }
    }

    ControlBlock *get_control_block() const { return ctrl_block; }

    // Check if the shared pointer is managing an object
    explicit operator bool() const
    {
        return ptr != nullptr;
    }

    // Constructor to create Shared_pointer from Weak_pointer
    template <typename U>
    explicit Shared_pointer(const Weak_pointer<U> &weak_ptr);
};

template <typename T>
class Weak_pointer
{
private:
    T *ptr;
    ControlBlock *ctrl_block;

public:
    Weak_pointer() : ptr(nullptr), ctrl_block(nullptr) {}

    Weak_pointer(const Shared_pointer<T> &shared_ptr) : ptr(shared_ptr.get()), ctrl_block(shared_ptr.get_control_block())
    {
        if (ctrl_block)
        {
            ++ctrl_block->weak_count;
        }
    }

    Weak_pointer(const Weak_pointer &other) : ptr(other.ptr), ctrl_block(other.ctrl_block)
    {
        if (ctrl_block)
        {
            ++ctrl_block->weak_count;
        }
    }

    Weak_pointer &operator=(const Weak_pointer &other)
    {
        if (this != &other)
        {
            release();
            ptr = other.ptr;
            ctrl_block = other.ctrl_block;
            if (ctrl_block)
            {
                ++ctrl_block->weak_count;
            }
        }
        return *this;
    }

    ~Weak_pointer()
    {
        release();
    }

    Shared_pointer<T> lock() const
    {
        if (ctrl_block && ctrl_block->shared_count > 0)
        {
            return Shared_pointer<T>(*this);
        }
        return Shared_pointer<T>();
    }

    void release()
    {
        if (ctrl_block)
        {
            if (--ctrl_block->weak_count == 0 && ctrl_block->shared_count == 0)
            {
                delete ctrl_block;
            }
            ptr = nullptr;
            ctrl_block = nullptr;
        }
    }
};

template <typename T>
template <typename U>
Shared_pointer<T>::Shared_pointer(const Weak_pointer<U> &weak_ptr)
    : ptr(weak_ptr.ptr), ctrl_block(weak_ptr.ctrl_block)
{
    if (ctrl_block && ctrl_block->shared_count > 0)
    {
        ++ctrl_block->shared_count;
    }
    else
    {
        ptr = nullptr;
        ctrl_block = nullptr;
    }
}

class MyClass
{
public:
    MyClass() { std::cout << "MyClass constructed\n"; }
    ~MyClass() { std::cout << "MyClass destructed\n"; }
};

int main()
{
    Shared_pointer<MyClass> sp(new MyClass());
    Weak_pointer<MyClass> wp(sp);

    {
        Shared_pointer<MyClass> sp2 = sp; // Increase shared count
    } // sp2 goes out of scope, decrease shared count

    if (auto locked = wp.lock())
    {
        std::cout << "Locked shared pointer\n";
    }
    else
    {
        std::cout << "Failed to lock\n";
    }

    sp.release(); // Shared count reaches 0, object destroyed

    if (auto locked = wp.lock())
    {
        std::cout << "Locked shared pointer\n";
    }
    else
    {
        std::cout << "Failed to lock\n";
    }

    return 0;
}

// int main()
// {
//     Shared_pointer<int> sp(new int(42));
//     Weak_pointer<int> wp(sp);

//     if (auto locked = wp.lock())
//     {
//         std::cout << "Locked value: " << *locked << std::endl;
//     }
//     else
//     {
//         std::cout << "Failed to lock" << std::endl;
//     }

//     sp.release();

//     if (auto locked = wp.lock())
//     {
//         std::cout << "Locked value: " << *locked << std::endl;
//     }
//     else
//     {
//         std::cout << "Failed to lock" << std::endl;
//     }

//     return 0;
// }
