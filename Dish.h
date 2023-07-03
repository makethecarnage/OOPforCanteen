#ifndef OOP_DISH_H
#define OOP_DISH_H


#pragma once
#include <string>
#include <iostream>
class Dish {
public:

    Dish();
    Dish(std::string name, int cost, int weight, int contentProteins, int contentFats, int contentCarbons, int contentAcids, int contentFibers);
    explicit Dish(const std::string& csv);
    Dish(const Dish& other);

    ~Dish();

    const std::string& getName() const;
    int getCost() const;
    int getWeight() const;
    int getContentProteins() const;
    int getContentFats() const;
    int getContentCarbons() const;
    int getContentAcids() const;
    int getContentFibers() const;

    double energyValue() const;

    void setName(const std::string& name);
    void setCost(int cost);
    void setWeight(int weight);
    void setContentProteins(int contentProteins);
    void setContentFats(int contentFats);
    void setContentCarbons(int contentCarbons);
    void setContentAcids(int contentAcids);
    void setContentFibers(int contentFibers);
    std::string toString() const;

    void displayDish();

    bool operator<(const Dish& other) const;

protected:

    std::string name;
    int cost;
    int weight;
    int contentProteins;
    int contentFats;
    int contentCarbons;
    int contentAcids;
    int contentFibers;

};


#endif //OOP_DISH_H
