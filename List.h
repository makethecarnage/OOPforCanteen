

#ifndef OOP_LIST_H
#define OOP_LIST_H

#pragma once
#include <stdlib.h>
#include <iostream>
#include "Dish.h"
#include <fstream>



class List                              
{
public:

    struct Node                            
    {
        Node *next = NULL;
        Node *prev = NULL;
        Dish data;
    };

    class Iterator{
        friend class List;

    private:
        Node* cur;

    public:

        Iterator(Node* first);
        ~Iterator();
        Dish& operator*();

        bool operator==(const Iterator&) const;
        bool operator!=(const Iterator&) const;

        Iterator& operator++(); // prefix increment
        Iterator operator++(int); // postfix increment
        Iterator& operator--();
        Iterator operator--(int);
    };

    List();
    List(List& parent);

    ~List();

    Iterator begin() const;
    Iterator end() const;

    void save(const std::string& path) const;
    void from(const std::string& path);

    void pop(int pos);
    void display();
    void clearAll();

    int length() const;
    bool empty() const;
    Node* find(Dish data) const;
    Node* search(double value) const;
    void insert(const Dish& value);

    void erase(Iterator pos);

    bool operator==(List& other) const;
    bool operator!=(const List *other) const;

private:

    Node *head, *tail;

};


#endif 
