#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::condition_variable cv;
std::mutex m;
long balance = 0;

void addMoney(int money)
{
    std::lock_guard<std::mutex> lg(m);
    balance += money;
    std::cout << "Amount added current balance: " << balance << std::endl;
    cv.notify_one();
}

void withdrawMoney(int money)
{
    std::unique_lock<std::mutex> ul(m);
    cv.wait(ul, []
            { return (balance != 0) ? true : false; }); // waiting till this balance condition is true by releasing this mutex m //Unlock
    if (balance >= money)
    {
        balance -= money;
        std::cout << "Amount Deducted: " << money << std::endl;
    }
    else
    {
        std::cout << "Amount can't be deducted, current balance is less than " << money << std::endl;
    }
    std::cout << "Current balance is: " << balance << std::endl;
}

int main()
{
    std::thread t1(withdrawMoney, 500); // 600
    std::thread t2(addMoney, 500);

    t1.join();
    t2.join();

    return 0;
}