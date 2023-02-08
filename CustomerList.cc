#include <iostream>
#include <string>
using namespace std;

#include "CustomerList.h"

CustomerList::CustomerList(): head(NULL){}


CustomerList::~CustomerList(){
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
void CustomerList::add(Customer* cust){
    Node* newNode = new Node();
    newNode->data = cust;
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

bool CustomerList::remove(const string& name, Customer** goner){
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

bool CustomerList::get(const string& name, Customer** cust) const{
    Node* currNode = head;

    while (currNode!=NULL){
        if (currNode->data->getName()==name){
           break; 
        }
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *cust = NULL;
        return false;
    }
    //currNode is not NULL
    *cust = currNode->data;
    return true;
}

void CustomerList::clear() const{
    Node* currNode = head;
    Node* nextNode = NULL;

    while(currNode!=NULL){
        nextNode = currNode->next;
        delete currNode->data;
        currNode = nextNode;
    }

    CustomerList::~CustomerList();

}
bool CustomerList::isEmpty() const{
    if(head == NULL){
        return true;
    }
    return false;
}

void CustomerList::print() const{
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

