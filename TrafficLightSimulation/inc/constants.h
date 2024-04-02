#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <semaphore>

std::binary_semaphore
    laneOneToLaneTwo{0},
    laneTwoToLaneThree{0},
    laneThreeToLaneFour{0},
    laneFourToLaneOne{0};

#endif