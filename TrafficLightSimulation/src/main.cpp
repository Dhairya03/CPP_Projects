#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <semaphore>
#include "laneOne.h"
#include "laneTwo.h"
#include "laneThree.h"
#include "laneFour.h"
#include "lane.h"
#include "constants.h"
// std::binary_semaphore
//     mainToLaneOne{0},
//     laneOneToLaneTwo{0},
//     laneTwoToLaneThree{0},
//     laneThreeToLaneFour{0},
//     laneFourToMain{0};

int main()
{
    int numberOfLanes = 4;
    int sourceLane, destinationLane, choice;
    LaneOne laneOne;
    LaneTwo laneTwo;
    LaneThree laneThree;
    LaneFour laneFour;
    std::cout << "Starting the traffic light" << std::endl;

    std::thread LaneOneThread(&LaneOne::switchLight, laneOne);
    std::thread LaneTwoThread(&LaneTwo::switchLight, laneTwo);
    std::thread LaneThreeThread(&LaneThree::switchLight, laneThree);
    std::thread LaneFourThread(&LaneFour::switchLight, laneFour);

    do
    {
        std::cout << "\t | Lane 3 | \t\n------\t\t\t------\nLane 4 \t\t\tLane 2\n------\t\t\t------\n\t | Lane 1 | \t \n";

        std::cout << "Where are you standing?\nChoose your lane number(Enter 1,2,3 or 4 only)" << std::endl;
        std::cin >> sourceLane;

        std::cout << "Where do you want to go?\nChoose the lane number(Enter 1, 2, 3, or 4 only)" << std::endl;
        std::cin >> destinationLane;

        if (sourceLane == destinationLane)
        {
            std::cout << "You can take a U turn" << std::endl;
        }
        else if (sourceLane - (destinationLane % numberOfLanes) == 1)
        {
            std::cout << "You can take a left turn" << std::endl;
        }
        else
        {
            if (sourceLane == 1)
            {
                std::cout<<laneOne.getCounter();
                if (laneOne.getCounter() == 1)
                {
                    std::cout << "You can go ahead" << std::endl;
                }
                else
                {
                    std::cout << "You have to wait" << std::endl;
                }
            }
            else if (sourceLane == 2)
            {
                std::cout << laneTwo.getCounter();
                if (laneTwo.getCounter() == 1)
                {
                    std::cout << "You can go ahead" << std::endl;
                }
                else
                {
                    std::cout << "You have to wait" << std::endl;
                }
            }
            else if (sourceLane == 3)
            {
                if (laneThree.getCounter() == 1)
                {
                    std::cout << "You can go ahead" << std::endl;
                }
                else
                {
                    std::cout << "You have to wait" << std::endl;
                }
            }
            else if (sourceLane == 4)
            {
                if (laneFour.getCounter() == 1)
                {
                    std::cout << "You can go ahead" << std::endl;
                }
                else
                {
                    std::cout << "You have to wait" << std::endl;
                }
            }
            else
            {
                std::cout << "Invalid lane number" << std::endl;
            }
        }

        std::cout << "Want to continue\nEnter 1 to continue.\nEnter -1 to quit" << std::endl;
        std::cin >> choice;
    } while (choice != -1);
    std::cout << "TurningOff traffic light" << std::endl;
    if (LaneOneThread.joinable())
        LaneOneThread.join();
    if (LaneTwoThread.joinable())
        LaneTwoThread.join();
    if (LaneThreeThread.joinable())
        LaneThreeThread.join();
    if (LaneFourThread.joinable())
        LaneFourThread.join();

    return 0;
}
