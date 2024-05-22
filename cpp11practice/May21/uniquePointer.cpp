#include <iostream>

// A simple custom unique_ptr implementation
template <typename T>
class UniquePtr
{
public:
    // Constructor that takes a raw pointer
    explicit UniquePtr(T *ptr = nullptr) : ptr_(ptr) {}

    // Destructor that deletes the managed object
    ~UniquePtr()
    {
        delete ptr_;
    }

    // Delete copy constructor and copy assignment operator
    UniquePtr(const UniquePtr &) = delete;
    UniquePtr &operator=(const UniquePtr &) = delete;

    // Move constructor
    UniquePtr(UniquePtr &&other) noexcept : ptr_(other.ptr_)
    {
        other.ptr_ = nullptr;
    }

    // Move assignment operator
    UniquePtr &operator=(UniquePtr &&other) noexcept
    {
        if (this != &other)
        {
            delete ptr_;       // Clean up the current resource
            ptr_ = other.ptr_; // Transfer ownership
            other.ptr_ = nullptr;
        }
        return *this;
    }

    // Overload dereference operator
    T &operator*() const
    {
        return *ptr_;
    }

    // Overload arrow operator
    T *operator->() const
    {
        return ptr_;
    }

    // Get the raw pointer
    T *get() const
    {
        return ptr_;
    }

    // Release ownership of the managed object
    T *release()
    {
        T *old_ptr = ptr_;
        ptr_ = nullptr;
        return old_ptr;
    }

    // Reset the managed object
    void reset(T *ptr = nullptr)
    {
        delete ptr_;
        ptr_ = ptr;
    }

private:
    T *ptr_;
};

struct Test
{
    int value;
    Test(int v) : value(v)
    {
        std::cout << "Test created: " << value << std::endl;
    }
    ~Test()
    {
        std::cout << "Test destroyed: " << value << std::endl;
    }
};

int main()
{
    // Create a UniquePtr managing a Test object
    UniquePtr<Test> ptr1(new Test(1));
    std::cout << "ptr1->value: " << ptr1->value << std::endl;

    // Transfer ownership to ptr2
    UniquePtr<Test> ptr2 = std::move(ptr1);
    if (!ptr1.get())
    {
        std::cout << "ptr1 is now null" << std::endl;
    }
    std::cout << "ptr2->value: " << ptr2->value << std::endl;

    // Reset ptr2
    ptr2.reset(new Test(2));
    std::cout << "ptr2->value after reset: " << ptr2->value << std::endl;

    // Release the ownership of ptr2
    Test *rawPtr = ptr2.release();
    if (!ptr2.get())
    {
        std::cout << "ptr2 is now null" << std::endl;
    }
    std::cout << rawPtr->value << std::endl;
    delete rawPtr; // Manually delete the object

    return 0;
}
