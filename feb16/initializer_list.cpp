#include <iostream>

struct Person
{
    int age;
    int id;
    char ch;
    double d;
};

int main()
{
    Person p1;
    Person p2 = {1};
    std::cout << p1.age << " " << p1.ch << " " << p1.d << " " << p1.id << std::endl;
    std::cout << p2.age << " " << p2.ch << " " << p2.d << " " << p2.id << std::endl;
    return 0;
}
