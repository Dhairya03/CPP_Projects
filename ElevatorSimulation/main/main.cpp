#include <iostream>
#include <thread>
#include <mutex>
#include "Request.h"
#include "ElevatorSystem.h"
#include "IElevator.h"
#include "Elevator.h"
#include <fstream>
#include <chrono>
using namespace std::chrono;

void readRequestFromFile(Request &request, const std::string &filename, ElevatorSystem &system)
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
            if (ch != '\n')
            {
                std::cout << ch;
                request.setFloor();
                if (ch == 48)
                    request.setDirection(Up);
                else if (ch == 49)
                    request.setDirection(Down);
                std::cout << "Request recieved is" << request.getDirection() << "," << request.getFloor() << std::endl;
                system.addRequest(request,0);
            }
        }
        file.clear();
    }
}

int main()
{
    int minFloor = -2;
    int maxFloor = 7;
    std::string filename = "input.txt";
    Request request;
    std::mutex mtx;

    IElevator *elevator1 = new Elevator(Idle,0);
    IElevator *elevator2 = new Elevator(Idle,7);
    ElevatorSystem system(elevator1, elevator2);

    std::thread requestInputThread(readRequestFromFile, std::ref(request), filename, std::ref(system));

    std::cout << "File read" << std::endl;

    system.startElevator();

    elevator1->setRunningStatus(true);
    elevator2->setRunningStatus(true);

    std::thread lift1(&IElevator::startLift, elevator1);
    std::thread lift2(&IElevator::startLift, elevator2);

    requestInputThread.join();
    lift1.join();
    lift2.join();
    return 0;
}