#include "Driver.h"

const char Driver::code = 'D';
int Driver::nextId= 0;


Driver::Driver(string name, int rating, Size size , Location l):User(code, nextId, name, rating,l){
    nextId+=1;
    this->size = size;
}
Driver::~Driver(){

}

bool Driver::match(int r, Size size){
    if(this->size>= size){
        if(abs(this->rating-r)<=2){
            return true;
        }
    }
    return false;
}

int Driver::getDistance(const Location& l){

    return location.getDistance(l);

}


void Driver::print()const {
    cout<<"Driver ID: "<<this->getId()<<" Driver Name: "<<this->getName()<<endl;
}