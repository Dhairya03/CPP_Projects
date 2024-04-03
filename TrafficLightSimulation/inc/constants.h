#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <semaphore.h>

extern sem_t laneOneToLaneTwo, laneTwoToLaneThree, laneThreeToLaneFour, laneFourToLaneOne;

enum TrafficSignals
{
    Red = 0, Green = 1
};

#endif