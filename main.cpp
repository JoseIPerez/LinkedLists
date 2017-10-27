#include <iostream>
#include <cassert>
#include "List.h"

using namespace std;

//testing if LinkedList is empty
void isEmpty(){
    List a;
    assert(a.empty() == true);
    assert(a.size() == 0);
    
    Iterator it = a.begin();
    Iterator end = a.end();
    
    assert(it == end);
    assert(it.operator==(end));
    
    a.push_back(3);
    
    assert(a.empty() == false);
    assert(a.size() == 1);
}

//testing the size after push_back and push_front
void push_front(){
    List a;
    a.push_back(5);
    a.push_front(4);
    a.push_front(3);
    a.push_front(2);
    a.push_front(1);
    a.push_front(0);

    Iterator it = a.begin();
    Iterator end = a.end();
    it = a.begin();
    assert(*it == 0);
    ++it;
    assert(*it == 1);
    ++it;
    assert(*it == 2);
    ++it;
    assert(*it == 3);
    ++it;
    assert(*it == 4);
    ++it;
    assert(*it == 5);
    ++it;
    it = a.end();
}

//testing the *it asserting (was bugging out because pop_back)
void push_back(){
    List a;
    Iterator it = a.begin();
    Iterator end = a.end();
    assert(it == end);
    
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    it = a.begin();
    assert(*it == 1);
    ++it;
    assert(*it == 2);
    ++it;
    assert(*it == 3);
    ++it;
    it = a.end();
}

//testing pop_back()
void pop_back(){
    List a;
    Iterator it = a.begin();
    Iterator end = a.end();
    assert(it.operator == (end));
    
    a.push_back(2);
    a.push_front(3);
    a.push_back(1);
    a.push_back(0);
    assert(a.size() == 4);
    
    a.pop_back();
    a.pop_front();
    a.pop_back();
    it = a.begin();
    assert(*it == 2);
    ++it;
    it = a.end();
}

//testing Iterator erase
void erase(){
    List a;
    Iterator it = a.begin();
    Iterator end = a.end();
    
    a.push_back(0);
    it = a.begin();
    it = a.erase(it);
    
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    it = a.begin();
    assert(*it == 1);
    ++it;
    it = a.erase(it);
    assert(*it == 3);
    ++it;
    it = a.end();
}

//testing Iterator insert
void insert(){
    List a;
    Iterator it = a.begin();
    Iterator end = a.end();
    //Better test code for insert to test correct insert
    a.push_back(1);
    a.push_back(2);
    a.push_front(0);
    it = a.begin();
    it = a.insert(it, 5);
    assert(*it == 5);
    ++it;
    assert(*it == 0);
    ++it;
    assert(*it == 1);
    ++it;
    assert(*it == 2);
    ++it;
    it = a.end();
}

int main(int argc, char * args[]) {
    isEmpty();
    push_front();
    push_back();
    pop_back();
    erase();
    insert();
    
	cout << "All Tests Passed" << endl;
}
