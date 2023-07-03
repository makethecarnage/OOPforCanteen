
#include "Dish.h"
#include <string.h>
#include <iostream>
#include <vector>




Dish::Dish() {

    this->name = "Dish";
    this->cost = 200;
    this->weight = 100;
    this->contentProteins = 20;
    this->contentFats = 20;
    this->contentCarbons = 20;
    this->contentAcids = 20;
    this->contentFibers = 20;
}

Dish::Dish(std::string name, int cost, int weight, int contentProteins, int contentFats, int contentCarbons, int contentAcids, int contentFibers) {

    this->name = name;
    this->cost - cost;
    this->weight = weight;
    this->contentProteins = contentProteins;
    this->contentFats = contentFats;
    this->contentCarbons = contentCarbons;
    this->contentAcids = contentAcids;
    this->contentFibers = contentFibers;

}

Dish::Dish(const Dish& other) {

    this->name = other.name;
    this->cost = other.cost;
    this->weight = other.weight;
    this->contentProteins = other.contentProteins;
    this->contentFats = other.contentFats;
    this->contentCarbons = other.contentCarbons;
    this->contentAcids = other.contentAcids;
    this->contentFibers = other.contentFibers;

}

Dish::Dish(const std::string &csv) {

    std::vector<std::string> arr;
    std::string delim(" ");
    size_t prev = 0;
    size_t next;
    size_t delta = delim.length();

    while( ( next = csv.find( delim, prev ) ) != std::string::npos ){
        arr.push_back( csv.substr( prev, next-prev ) );
        prev = next + delta;
    }

    arr.push_back( csv.substr( prev ) );

    this->name = arr[0];
    this->cost = stoi(arr[1]);
    this->weight = stoi(arr[2]);
    this->contentProteins = stoi(arr[3]);
    this->contentFats = stoi(arr[4]);
    this->contentCarbons = stoi(arr[5]);
    this->contentAcids = stoi(arr[6]);
    this->contentFibers = stoi(arr[7]);

}

Dish::~Dish() {

}

double Dish::energyValue() const{

    return (contentProteins * 4.0 + contentFats * 9.0 + contentCarbons * 3.75 + contentAcids * 3.0 + contentFibers * 1.9);

}

const std::string& Dish::getName() const {
    return name;
}

int Dish::getCost() const {
    return cost;
}

int Dish::getWeight() const {
    return weight;
}

int Dish::getContentProteins() const {
    return contentProteins;
}

int Dish::getContentFats() const {
    return contentFats;
}

int Dish::getContentCarbons() const {
    return contentCarbons;
}

int Dish::getContentAcids() const {
    return contentAcids;
}

int Dish::getContentFibers() const {
    return contentFibers;
}

void Dish::setName(const std::string& name) {
    this->name = name;
}

void Dish::setCost(int cost) {
    this->cost = cost;
}

void Dish::setWeight(int weight) {
    this->weight = weight;
}

void Dish::setContentProteins(int contentProteins) {
    this->contentProteins = contentProteins;
}

void Dish::setContentFats(int contentFats) {
    this->contentFats = contentFats;
}

void Dish::setContentCarbons(int contentCarbons) {
    this->contentCarbons = contentCarbons;
}

void Dish::setContentAcids(int contentAcids) {
    this->contentAcids = contentAcids;
}

void Dish::setContentFibers(int contentFibers) {
    this->contentFibers = contentFibers;
}

std::string Dish::toString() const
{
    std::string tmp;
    tmp += this->name;
    tmp += ", ";
    tmp += std::to_string(this->cost);
    tmp += ", ";
    tmp += std::to_string(this->weight);
    tmp += ", ";
    tmp += std::to_string(this->contentProteins);
    tmp += ", ";
    tmp += std::to_string(this->contentFats);
    tmp += ", ";
    tmp += std::to_string(this->contentCarbons);
    tmp += ", ";
    tmp += std::to_string(this->contentAcids);
    tmp += ", ";
    tmp += std::to_string(this->contentFibers);


    return tmp;
}

bool Dish::operator<(const Dish& other) const
{
    return (this->energyValue() <
           other.energyValue());
}

void Dish::displayDish() {

    std::cout << name << std::endl;

}
