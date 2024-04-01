#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

condition_variable cv;
mutex m;

int val = 0;

void add(int num)
{
    lock_guard<mutex> lock(m);
    val += num;
    cout << "After addition: " << val << endl;
    cv.notify_one();
}

void sub(int num)
{
    unique_lock<mutex> ulock(m);
    cv.wait(ulock,
            []
            { return (val != 0) ? true : false; });
    if (val >= num)
    {
        val -= num;
        cout << "After subtraction: " << val << endl;
    }
    else
    {
        cout << "Cannot Subtract now!" << endl;
    }
    cout << "Total number Now: " << val << endl;
}

int main()
{
    
    thread t2(sub, 600);
    //if I dont initialize thread t1 then sub will always wait for add and thus get stuck there.
    // thread t1(add, 900);
    // t1.join();
    //calling a function also works as they can release the resource
    add(100);
    t2.join();
    return 0;
}
