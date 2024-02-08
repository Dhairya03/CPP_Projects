#include <iostream>

class Player
{
public:
    int x, y;
    int speed;
    void move(int xa,int ya){
        x+=xa*speed;
        y+=ya*speed;
    }
};

// void move(Player &player, int xa, int ya)
// {
//     player.x += xa * player.speed;
//     player.y += ya * player.speed;
// }

int main()
{
    Player player;
    std::cin >> player.x;
    std::cout << player.x;
    std::cin >> player.y;
    std::cout << player.y;
    std::cin >> player.speed;
    //move(player, 5, 4);
    player.move(5,4);
    std::cout << player.x;
    std::cout << player.y;
}