#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <semaphore.h>
#include "laneOne.h"
#include "laneTwo.h"
#include "laneThree.h"
#include "laneFour.h"
#include "lane.h"
#include "ILane.h"
#include "constants.h"

using namespace std::chrono;
sem_t laneOneToLaneTwo, laneTwoToLaneThree, laneThreeToLaneFour, laneFourToLaneOne;

int main()
{
    sem_init(&laneOneToLaneTwo, 0, 0);
    sem_init(&laneTwoToLaneThree, 0, 0);
    sem_init(&laneThreeToLaneFour, 0, 0);
    sem_init(&laneFourToLaneOne, 0, 1);

    int numberOfLanes = 4;
    int sourceLane, destinationLane, choice;

    LaneOne laneOne;
    LaneTwo laneTwo;
    LaneThree laneThree;
    LaneFour laneFour;

    std::cout << "Starting the traffic light" << std::endl;
    laneOne.setLoopStart(true);
    laneTwo.setLoopStart(true);
    laneThree.setLoopStart(true);
    laneFour.setLoopStart(true);

    std::thread LaneOneThread(&LaneOne::switchLight, laneOne);
    std::thread LaneTwoThread(&LaneTwo::switchLight, laneTwo);
    std::thread LaneThreeThread(&LaneThree::switchLight, laneThree);
    std::thread LaneFourThread(&LaneFour::switchLight, laneFour);

    do
    {
        std::cout << "\t | Lane 3 | \t\n------\t\t\t------\nLane 4 \t\t\tLane 2\n------\t\t\t------\n\t | Lane 1 | \t \n";

        std::cout << "Where are you standing?\nChoose your lane number(Enter 1, 2, 3, or 4 only)" << std::endl;
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
                if (laneOne.getCounter() == 1)
                {
                    std::cout << "You can go ahead" << std::endl;
                }
                else
                {
                    while (laneOne.getCounter() != 1)
                    {
                        std::cout << "You have to wait" << std::endl;
                        std::this_thread::sleep_for(1s);
                    }
                    std::cout << "Now you can go" << std::endl;
                }
            }
            else if (sourceLane == 2)
            {
                if (laneTwo.getCounter() == 1)
                {
                    std::cout << "You can go ahead" << std::endl;
                }
                else
                {
                    while (laneOne.getCounter() != 1)
                    {
                        std::cout << "You have to wait" << std::endl;
                        std::this_thread::sleep_for(1s);
                    }
                    std::cout << "Now you can go" << std::endl;
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

    std::cout << "Turning Off traffic light" << std::endl;

    laneOne.setLoopStart(false);
    laneTwo.setLoopStart(false);
    laneThree.setLoopStart(false);
    laneFour.setLoopStart(false);

    if (LaneOneThread.joinable())
        LaneOneThread.join();
    if (LaneTwoThread.joinable())
        LaneTwoThread.join();
    if (LaneThreeThread.joinable())
        LaneThreeThread.join();
    if (LaneFourThread.joinable())
        LaneFourThread.join();

    std::cout << "Exited Successfully" << std::endl;
    return 0;
}
