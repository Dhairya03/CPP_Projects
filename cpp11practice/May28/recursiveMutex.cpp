#include <iostream>
#include <mutex>
#include <thread>

std::recursive_mutex m1; // without recursive mutex deadlock occurs as the function tries to lock the resource that is already occupied by its parent function
int fun1(int n)
{
    std::lock_guard<std::recursive_mutex> guard(m1); // it is used because it itself unlocks the lock
    // manually locking and unlokcing is error prone and xthe function return by itself befoire unlocking the resource

    // m1.lock();
    std::cout << "fun1 " << n << std::endl;
    if (n == 0)
    {
        // m1.unlock();
        return 1;
    }

    return fun1(n - 1);
}

int fun2(int n)
{
    std::lock_guard<std::recursive_mutex> guard(m1);

    // m1.lock();
    std::cout << "fun2 " << n << std::endl;
    if (n == 0)
    {
        // m1.unlock();

        return 1;
    }

    return fun2(n - 2);
}

int main()
{
    std::thread t1(fun1, 10);
    std::thread t2(fun2, 100);

    std::cout << "Main " << std::endl;

    t1.join();
    t2.join();
    return 0;
}