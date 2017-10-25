#pragma once
#include "Iterator.h"

class List {
public:
	List() {
        head = nullptr;
        tail = nullptr;
    }
    ~List();
	bool empty() const;
	void push_back(int data);
	void push_front(int data);
	int size();
	void pop_front();
	void pop_back();
	Iterator begin();
	Iterator end();
    Iterator insert(Iterator it, int data);
	Iterator erase(Iterator it);
private:
    Link* head;
    Link* tail;
    int count;
};
