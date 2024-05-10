#include <iostream>
#include <thread>
#include <mutex>
#include "Request.h"
#include "ElevatorSystem.h"
#include "IElevator.h"
#include "Elevator.h"
#include "IRequest.h"
#include <fstream>
#include <chrono>
using namespace std::chrono;

void readRequestFromFile(std::mutex &mutex, IRequest *request, const std::string &filename, ElevatorSystem &system, int &isLiftStopped)
{
    std::fstream file;
    file.open(filename, std::ios::out | std::ios::trunc);
    file.close();
    file.open(filename);
    if (!file.is_open())
    {
        std::cout << "Error opening file: " << filename << "\n";
        return;
    }
    while (true)
    {
        char ch;
        while (file >> std::noskipws >> ch)
        {
            if (ch == 'q')
            {
                std::cout << "Elevator System is Stopped" << std::endl;
                break;
            }
            else if (!(ch == 48 || ch == 49 || ch == '\n'))
            {
                std::cout << "Invalid Request for the elevator" << std::endl;
                break;
            }
            else if (ch != '\n')
            {
                request->setFloor();
                if (ch == 48)
                    request->setDirection(Up);
                else if (ch == 49)
                    request->setDirection(Down);
                mutex.lock();
                std::cout << "Request recieved is " << request->getDirection() << ", " << request->getFloor() << std::endl;
                mutex.unlock();
                system.addRequest(request, 0);
            }
        }
        file.clear();
        if (ch == 'q')
        {
            isLiftStopped = 1;
            file.close();
            break;
        }
    }
}

int main()
{
    int minFloor = -2;
    int maxFloor = 7;
    std::string filename = "input.txt";
    IRequest *request = new Request;
    std::mutex mutex;
    int isLiftStopped = 0;

    IElevator *elevator1 = new Elevator(1, Idle, 0);
    IElevator *elevator2 = new Elevator(2, Idle, maxFloor);
    ElevatorSystem system(elevator1, elevator2);

    std::thread requestInputThread(readRequestFromFile, std::ref(mutex), request, filename, std::ref(system), std::ref(isLiftStopped));

    std::cout << "File read" << std::endl;

    std::cout << "Elevator system has started" << std::endl;

    std::thread lift1(&IElevator::startLift, elevator1, std::ref(mutex));
    std::thread lift2(&IElevator::startLift, elevator2, std::ref(mutex));

    while (true)
    {
        if (isLiftStopped == 1)
        {
            elevator1->setRunningStatus(false);
            elevator2->setRunningStatus(false);
            break;
        }
    }
    requestInputThread.join();
    lift1.join();
    lift2.join();
    return 0;
}