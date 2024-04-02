#include <iostream>
#include <thread>

void fun(int x)
{
    while (x-- > 0)
    {
        std::cout << x << std::endl;
    }
}

// 1. Funtion Pointer
/*int main()
{
    std::thread t1(fun, 11); // function without parameters are function pointers //here fun is function pointer

    t1.join();
    // if I don't make join then error is comimg
    // terminate called without an active exception
    // Aborted (core dumped)

    return 0;
}*/

// 2. Lambda Function
/*int main()
{
    // we can directly inject lambda at thread creation time.
    auto fun = [](int x)
    {
        while (x-- > 0)
        {
            std::cout << x << std::endl;
        }
    }; // fun is lambda function

    std::thread t(fun, 10);
    t.join();
    return 0;
}*/

// 3. Functors (Function Object)
/*class Base
{
public:
    void operator()(int x)
    {
        while (x-- > 0)
        {
            std::cout << x << std::endl;
        }
    }
};

int main()
{
    std::thread t((Base()), 10);
    t.join();

    return 0;
}*/

// 4. Non-static member function
/*class Base
{
public:
    void run(int x)
    {
        while (x-- > 0)
        {
            std::cout << x << std::endl;
        }
    }
};

int main()
{
    Base b;
    std::thread t(&Base::run, &b, 10);

    t.join();
    return 0;
}*/

// 5. Static member function
class Base
{
public:
    static void run(int x)
    {
        while (x-- > 0)
        {
            std::cout << x << std::endl;
        }
    }
};

int main()
{
    std::thread t(&Base::run, 10);

    t.join();
    return 0;
}