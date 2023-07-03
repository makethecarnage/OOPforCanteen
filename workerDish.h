#ifndef OOP_WORKERDISH_H
#define OOP_WORKERDISH_H

#pragma once
#include <stdlib.h>
#include <iostream>
#include "Dish.h"

class workerDish : public Dish{

public:

    workerDish();
    workerDish(std::string name, int cost, int weight, int contentProteins, int contentFats, int contentCarbons, int contentAcids, int contentFibers);


    float getPrice(const std::string post);

private:

    const float discountStudent = 0.25;
    const float discountProfessor = 0.3;
    const float discountOther = 0.1;

};

#endif //OOP_WORKERDISH_H
