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
#include <condition_variable>
using namespace std::chrono;

void readRequestFromFile(std::mutex &mtx, IRequest *request, const std::string &filename, ElevatorSystem &system)
{
    std::fstream file(filename);
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
                mtx.lock();
                std::cout << "Request recieved is " << request->getDirection() << ", " << request->getFloor() << std::endl;
                mtx.unlock();
                system.addRequest(request, 0);
            }
        }
        file.clear();
        if (ch == 'q')
        {
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
    std::mutex mtx;
    std::condition_variable cv;

    IElevator *elevator1 = new Elevator(1, Idle, 0);
    IElevator *elevator2 = new Elevator(2, Idle, 7);
    ElevatorSystem system(elevator1, elevator2);

    std::thread requestInputThread(readRequestFromFile, std::ref(mtx), request, filename, std::ref(system));

    std::cout << "File read" << std::endl;

    system.startElevator();

    elevator1->setRunningStatus(true);
    elevator2->setRunningStatus(true);

    std::thread lift1(&IElevator::startLift, elevator1, std::ref(mtx), std::ref(cv));
    std::thread lift2(&IElevator::startLift, elevator2, std::ref(mtx), std::ref(cv));

    requestInputThread.join();
    lift1.join();
    lift2.join();
    return 0;
}