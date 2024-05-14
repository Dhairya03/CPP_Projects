#include <iostream>

void print(const std::string &name)
{
    std::cout << name << std::endl;
}

int main()
{
    std::string firstName = "Abc";
    std::string lastName = "xdfdfgbg";
    std::string fullName = firstName + lastName;
    print(fullName);
    print(firstName + lastName);
    return 0;
}