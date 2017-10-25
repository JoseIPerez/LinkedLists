#include "List.h"
#include <cassert>

List::~List(){
    Link* temp;
    while(head != nullptr){
        temp = head->next;
        delete head;
        head = temp;
    }
}

bool List::empty() const{
	if (head == nullptr)
		return true;
	else
		return false;
}

void List::push_back(int data){
    Link *temp = new Link(data);
    if (head == nullptr){
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

void List::push_front(int data){
    Link* temp = new Link(data);
    if (head == nullptr){
        head = temp;
        tail = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

int List::size(){
    int count = 0;
    Link* temp = head;
    while (temp != nullptr){
        ++count;
        temp = temp->next;
    }
    delete temp;
    return count;
}

void List::pop_back(){
    assert(head != nullptr);
    if (head->next == nullptr){
        delete head;
        head = nullptr;
        return;
     }
    Link* temp = head;
    while (temp->next != tail){
        temp = temp->next;
    }
    tail = temp;
    tail->next = nullptr;
    delete temp->next;
}

void List::pop_front(){
    Link* temp = head;
    head = head->next;
    delete temp;
}
Iterator List::begin(){
    return Iterator(head);
}

Iterator List::end(){
    return Iterator(nullptr);
}

Iterator List::insert(Iterator it, int data){
    Link* temp1 = it.link;
    
    if (temp1 == nullptr) {
        push_back(data);
        return Iterator(tail);
    }
    
    Link* temp2 = new Link(data);
    Link* temp3 = temp1->next;
    
    temp1->next = temp2;
    temp2->next = temp3;
    
    int currData = temp1->data;
    temp1->data = temp2->data;
    temp2->data = currData;
    
    return it;
}

Iterator List::erase(Iterator it){
    Link* temp1 = it.link;
    
    if (temp1->next == nullptr){
        delete temp1;
        temp1 = nullptr;
        return Iterator(head);
    }
    
    Link* temp2 = temp1->next;
    int currData = temp1->data;
    temp1->data = temp2->data;
    temp2->data = currData;
    
    Link* temp3 = temp1->next->next;
    temp1->next = temp3;
    delete temp2;
    return it;
}
