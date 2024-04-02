#ifndef LANE_H
#define LANE_H

// #include "constants.h"
#include <semaphore>

class Lane
{
protected:
    std::counting_semaphore
        laneOneToLaneTwo{1};
    std::counting_semaphore
        laneTwoToLaneThree{1};
    std::counting_semaphore
        laneThreeToLaneFour{1};
    std::counting_semaphore
        laneFourToLaneOne{1};

    // Constants constant;

public:
    int getCounter();
    void setCounter();
    void switchLight();
};

#endif