#include <iostream>
using namespace std;

struct Add
{
    int a;

    Add(int a)
        : a(a)
    {
    }

    int operator()(int b) { return a + b; }
};

int main()
{
    Add add(5);
    int c = add(6);
    cout << c;
    return 0;
}
