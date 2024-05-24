#include <iostream>

class Fun
{
public:
    int val;
    Fun(int v) : val(v)
    {
    }

    void operator()(const Fun &f)
    {
        val += f.val;
    }
};

int main()
{
    Fun f1(2);
    std::cout << f1.val << std::endl;

    f1(3);
    std::cout << f1.val << std::endl; // will keep the state of f1 and add to it
    // object act as a function as it overloads ()

    f1(5);
    std::cout << f1.val << std::endl;
}