// #include <iostream>

// class Sample
// {
// public:
//     int *p;
//     int q;

//     Sample() : p(nullptr), q(0)
//     {
//     }

//     Sample(int a)
//     {
//         p = new int(a);
//     }

//     Sample(const Sample &other)
//     {

//         p = other.p;
//         q = other.q;
//     }

//     Sample &operator=(const Sample &other)
//     {
//         if (this != &other)
//         {
//             p = new int;
//             *p = *(other.p);
//             // p = other.p;
//             q = other.q;
//         }
//         return *this;
//     }

//     ~Sample()
//     {
//         delete p;
//     }
// };

// int main()
// {
//     Sample s(2);
//     Sample s2;
//     s.q = 2;
//     std::cout << "q= " << s.q << std::endl;
//     std::cout << *(s.p) << std::endl;
//     s2 = s;
//     std::cout << *(s2.p) << std::endl;

//     return 0;
// }

#include <iostream>

class Base

{

public:

    // void print()

    // {

    //     std::cout << "base" << std::endl;

    // }

    virtual void print()

    {

        std::cout << "base" << std::endl;

    }

    // virtual void print()=0;

    // virtual void print();

};

class Dervied1 : public Base

{

public:

    void print()

    {

        std::cout << "Derived one " << std::endl;

    }

};

class Derived2 : public Base

{

public:

    void print()

    {

        std::cout << "Derived two" << std::endl;

    }

};

int main()

{

    Base *b;

    b->print();

    Dervied1 d1;

    Derived2 d2;

    b->print();

    // b=&d1;

    // b->print();

    // b=&d2;

    // b->print();

    return 0;

}