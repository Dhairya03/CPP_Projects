#include <iostream>
using namespace std;

class Base // final this deniotes that this class cannot be inheroited further
{
public:
    virtual void fun() // final since final is used it cannot be overriden
    {
        cout << "fun() in Base";
    }
};
class Derived : public Base
{
    void fun() // override written to notify that this funtion is from a base calss and increases readbility
    {
        cout << "fun() in Derived\n";
    }
};

int main()
{
    Derived d;
    Base &b = d;
    b.fun();
    return 0;
}
