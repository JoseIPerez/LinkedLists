#pragma once
#include <iostream>
#include <cassert>

class Link{
private:
    Link(int n){
        data = n;
        next = nullptr;
    };
    
    Link* next;
    int data;
    friend class List;
    friend class Iterator;
};
