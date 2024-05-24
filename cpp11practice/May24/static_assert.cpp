#include <iostream>
using namespace std;

template <class T, int Size>
class Vector
{

    // it needs a constant expression in the condition
    static_assert(Size > 3, "Vector size is too small!"); // this will produce an assertion if consition is false
    // static_assert(1/0, "will prodce an error as it is not a constant expression");

    T m_values[Size];
};

int main()
{
    Vector<int, 4> four;
    Vector<short, 2> two; // This will fail so produce an assertion at compile time

    return 0;
}
