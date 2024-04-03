#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <semaphore.h>
#include "lane.h"
#include "ILane.h"
#include "constants.h"
#include "inputValidator.h"

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
    InputValidator inputValidator;

    ITrafficSignal *signal = new TrafficSignal();
    if (signal != NULL)
    {
        Lane laneOne{signal};
        Lane laneTwo{signal};
        Lane laneThree{signal};
        Lane laneFour{signal};
    }
    else
    {
        std::cout << "No traffic signal found" << std::endl;
    }

    std::cout << "Starting the traffic light" << std::endl;
    laneOne.setLoopStart(true);
    laneTwo.setLoopStart(true);
    laneThree.setLoopStart(true);
    laneFour.setLoopStart(true);

    std::thread LaneOneThread(&Lane::switchLight, &laneOne, std::ref(laneFourToLaneOne), std::ref(laneOneToLaneTwo), 1);
    std::thread LaneTwoThread(&Lane::switchLight, &laneTwo, std::ref(laneOneToLaneTwo), std::ref(laneTwoToLaneThree), 2);
    std::thread LaneThreeThread(&Lane::switchLight, &laneThree, std::ref(laneTwoToLaneThree), std::ref(laneThreeToLaneFour), 3);
    std::thread LaneFourThread(&Lane::switchLight, &laneFour, std::ref(laneThreeToLaneFour), std::ref(laneFourToLaneOne), 4);

    do
    {
        std::cout << "\t | Lane 3 | \t\n------\t\t\t------\nLane 4 \t\t\tLane 2\n------\t\t\t------\n\t | Lane 1 | \t \n";

        std::cout << "Where are you standing?\nChoose your lane number(Enter 1, 2, 3, or 4 only)" << std::endl;
        while (true)
        {
            std::cin >> sourceLane;
            if (inputValidator.isValidInput() && inputValidator.isValidLane(sourceLane))
            {
                break;
            }
            else
            {
                std::cout << "Invalid lane choice.Please try again" << std::endl;
            }
        }

        std::cout << "Where do you want to go?\nChoose the lane number(Enter 1, 2, 3, or 4 only)" << std::endl;
        while (true)
        {
            std::cin >> destinationLane;
            if (inputValidator.isValidInput() && inputValidator.isValidLane(destinationLane))
            {
                break;
            }
            else
            {
                std::cout << "Invalid lane choice.Please try again" << std::endl;
            }
        }

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
            Lane *laneObj = nullptr;
            switch (sourceLane)
            {
            case 1:
                laneObj = &laneOne;
                break;
            case 2:
                laneObj = &laneTwo;
                break;
            case 3:
                laneObj = &laneThree;
                break;
            case 4:
                laneObj = &laneFour;
                break;
            default:
                std::cout << "Invalid lane number" << std::endl;
                break;
            }

            if (laneObj != NULL)
            {
                if (laneObj->getCounter() == 1)
                {
                    std::cout << "You can go ahead" << std::endl;
                }
                else
                {
                    while (laneObj->getCounter() != 1)
                    {
                        std::cout << "You have to wait" << std::endl;
                        std::this_thread::sleep_for(1s);
                    }
                    std::cout << "Now you can go" << std::endl;
                }
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
