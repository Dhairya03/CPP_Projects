#include <iostream>

enum class Direction
{
    Up,
    Down
};

enum class Direction2
{
    Up,
    Down
};

int main()
{
    Direction d1 = Direction::Up;
    Direction2 d2 = Direction2::Down;             // need to specify which enum is used therfore can have same names.
    std::cout << (int)d1 << (int)d2 << std::endl; // need to typecast as << is not overloaded for a enum

    if ((int)d1 ==(int) d2) //nned to typecasted to comapre two enums otherwise error 
    {
        std::cout << "Enums are qual" << std::endl;
    }
    else
    {
        std::cout << "nums are not equal" << std::endl;
    }
    return 0;
}