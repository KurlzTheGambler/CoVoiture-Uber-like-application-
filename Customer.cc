#include "Customer.h"

const char Customer::code = 'C';
int Customer::nextId= 0;

Customer::Customer(string name, int rating, Location l): User(code, nextId, name, rating,l){
    nextId+=1;
}


Customer::~Customer(){

}

void Customer::print() const{
    cout<<" Customer ID: "<<this->getId()<<" Customer Name: "<<this->getName()<<endl;
}
