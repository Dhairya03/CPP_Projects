#include <iostream>

class Entity
{
public:
    float x, y;
    //Entity()=delete;
    // void Init(){
    //     x=1;y=1;

    // }
    Entity(){
        x=0;
        y=0;
    }

    void print()
    {
        std::cout << x << " " << y << std::endl;
    }
};

int main()
{
    Entity e;
   // e.Init();
    std::cout << e.x << std::endl;
    e.print();
    return 0;
}