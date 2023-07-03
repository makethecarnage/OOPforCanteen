#include "Dish.h"
#include <string.h>
#include <iostream>
#include "workerDish.h"

workerDish::workerDish() {

    this->name = "Dish";
    this->cost = 200;
    this->weight = 100;
    this->contentProteins = 20;
    this->contentFats = 20;
    this->contentCarbons = 20;
    this->contentAcids = 20;
    this->contentFibers = 20;
}

workerDish::workerDish(std::string name, int cost, int weight, int contentProteins, int contentFats, int contentCarbons, int contentAcids, int contentFibers) {

    this->name = name;
    this->cost - cost;
    this->weight = weight;
    this->contentProteins = contentProteins;
    this->contentFats = contentFats;
    this->contentCarbons = contentCarbons;
    this->contentAcids = contentAcids;
    this->contentFibers = contentFibers;

}


float workerDish::getPrice(std::string post) {

    auto newCost = float(this->getCost());

    if (post=="student"){
        return  newCost - discountStudent*newCost;
    }

    else if (post=="professor"){
        return newCost - discountProfessor*newCost;;
    }

    else
        return newCost - discountOther*newCost;;

}

