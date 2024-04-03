#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <semaphore.h>

extern sem_t laneOneToLaneTwo, laneTwoToLaneThree, laneThreeToLaneFour, laneFourToLaneOne;

#endif