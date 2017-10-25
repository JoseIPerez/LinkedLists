#include <iostream>
#include <cassert>
#include <vector>
#include "List.h"

using namespace std;

//testing if LinkedList is empty
void test1(){
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
void test2(){
    List a;
    a.push_back(1);
    a.push_back(2);
    
    assert(a.empty() == false);
    assert(a.size() == 2);
    
    a.push_back(3);
    a.push_back(4);
    a.push_front(0);
    
    assert(a.size() == 5);
}

//testing the *it asserting (was bugging out because pop_back)
void test3(){
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
    assert(a.size() == 1);
    it = a.begin();
    assert(*it == 2);
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
    assert(a.size() == 2);
}

//testing Iterator insert
void insert(){
    List a;
    Iterator it = a.begin();
    Iterator end = a.end();
    
    it = a.insert(it, 1);
    assert(*it == 1);
    ++it;
    
    it = a.insert(it, 2);
    assert(*it == 2);
    assert(a.size() == 2);
}

int main(int argc, char * args[]) {
    test1();
    test2();
    test3();
    pop_back();
    erase();
    insert();
    
	cout << "All Tests Passed" << endl;
}
