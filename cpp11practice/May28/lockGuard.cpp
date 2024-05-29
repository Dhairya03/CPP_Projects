#include <iostream>
#include <mutex>
#include <string_view>
#include <syncstream>
#include <thread>

volatile int g_i = 0;
std::mutex g_i_mutex; // protects g_i

void safe_increment(int iterations)
{
    const std::lock_guard<std::mutex> lock(g_i_mutex);
    while (iterations-- > 0)
        g_i = g_i + 1;
    std::cout << "thread #" << std::this_thread::get_id() << ", g_i: " << g_i << '\n';

    // g_i_mutex is automatically released when lock goes out of scope
}

void unsafe_increment(int iterations)
{
    while (iterations-- > 0)
        g_i = g_i + 1;
    std::cout << "thread #" << std::this_thread::get_id()
              << ", g_i: " << g_i << '\n';
}

int main()
{
    // auto test = [](std::string_view fun_name, auto fun)
    // {
    //     g_i = 0;
    //     std::cout << fun_name << ":\nbefore, g_i: " << g_i << '\n';
    //     {
    //         std::thread t1(fun, 1'000'000);
    //         std::thread t2(fun, 1'000'000);
    //     }
    //     std::cout << "after, g_i: " << g_i << "\n\n";
    // };
    // test("safe_increment", safe_increment);
    // test("unsafe_increment", unsafe_increment);

    std::thread t1(safe_increment, 100000);
    std::thread t2(unsafe_increment, 100000);

    t1.join();
    t2.join();
}