#include <iostream>

enum Direction
{
    Up,
    Down
};
// enum Direction2
// {
//     Up,     //name can not be same with direction
//     Down
// };

enum Color
{
    Red,
    Green
};

int main()
{
    // int Up = 3;
    // Direction2 d2 = Up;
    
    Direction d1 = Up; // invalid conversion from ‘int’ to ‘Direction’ //no variable can be same as enum

    Color c1 = Red;

    int a = 0;

    if (d1 == a) //(d1==c1)  can be compared with any integer variable or another enum
    {
        std::cout << "Red is Up" << std::endl; // shows the output after comaprison
    }
    else
    {
        std::cout << "Green is Down" << std::endl;
    }
    std::cout << d1 << Up << c1 << Red << std::endl;
}