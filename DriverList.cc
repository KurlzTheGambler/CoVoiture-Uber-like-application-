#include <iostream>
#include <string>
#include <climits>
using namespace std;

#include "DriverList.h"

DriverList::DriverList(): head(NULL){}


DriverList::~DriverList(){
    Node* currNode = head;
    Node* nextNode = NULL;

    while(currNode!=NULL){
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
        
    }
    head = NULL;
}

//add in sorted order by name
void DriverList::add(Driver* dri){
    Node* newNode = new Node();
    newNode->data = dri;
    newNode->next = NULL;

    Node* currNode = head;
    Node* prevNode = NULL;

    while(currNode!=NULL){
        if (newNode->data->lessThan(*currNode->data)){
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    //insert currNode
    if (prevNode == NULL){
        head = newNode;
    }else{
        prevNode->next = newNode;
    }
    newNode->next = currNode;

}

bool DriverList::remove(const string& name, Driver** goner){
    Node * currNode;
    Node * prevNode;

    currNode = head;
    prevNode = NULL;

    while (currNode!=NULL){
        if (currNode->data->getName()==name){
           break; 
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *goner = NULL;
        return false;
    }
    //currNode is not NULL
    if (prevNode == NULL){
        head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }
    *goner = currNode->data;
    delete currNode;

    return true;
}

bool DriverList::get(const string& name, Driver** dri) const{
    Node * currNode;

    currNode = head;

    while (currNode!=NULL){
        if (currNode->data->getName()==name){
           break; 
        }
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *dri = NULL;
        return false;
    }
    //currNode is not NULL
    *dri = currNode->data;
    return true;
}

void DriverList::clear() const{
    Node* currNode = head;
    Node* nextNode = NULL;

    while(currNode!=NULL){
        nextNode = currNode->next;
        delete currNode->data;
        currNode = nextNode;
    
    }
    DriverList::~DriverList();

}
bool DriverList::findRide(int rating, Size size, Location l , Driver** d){
    Node * currNode = head;
    bool found = false;
    int distance = INT_MAX;
    while (currNode!=NULL){
        if (currNode->data->match(rating, size)){
            found = true;
            if(currNode->data->getDistance(l)< distance){
                distance = currNode->data->getDistance(l);
                *d = currNode->data;
            }
        }
        currNode = currNode->next;
    }  
    return found;
}

bool DriverList::isEmpty() const{
    if(head == NULL){
        return true;
    }
    return false;
}

void DriverList::print() const{
    Node* currNode = head;
    cout<<"Print list..."<<endl;

    if (currNode == NULL){
        cout <<"List empty"<<endl;
    }

    while(currNode != NULL){
        currNode->data->print();
        currNode = currNode->next;
    }
}

