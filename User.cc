#include "User.h"

User::User(char code, int number, string& n, int r, Location& l){
    name = n;
    rating = r;
    location = l;
    id = code + to_string(number);
}

User::~User(){}

string User::getId() const{ return id;}

string User::getName() const{ return name;}

int User::getRating() const{ return rating;};

Location User::getLocation() const{return this->location;}

void User::setRating(int r){ rating = r;}

void User::setLocation(Location& l){location.setLocation(l.x, l.y);}

void User::setLocation(int x, int y){location.setLocation(x,y);}

bool User::lessThan(User& user) const{return name < user.name;}

void User::print() const{
    cout<<"UserName:"<< name<< "Rating:"<< rating<< "ID:"<< id<< "Location:"<<location.x<<location.y<<endl;
}