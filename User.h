#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "Location.h"
using namespace std;

class User{

    public:
        ~User();

        string getId() const;
        string getName() const;
        int getRating() const;
        Location getLocation() const;
        void setRating(int r);

        void setLocation(Location& l);
        void setLocation(int x, int y);
        void print() const;
        bool lessThan(User& user) const;

        //constructor
        User(char code, int number, string& name, int rating, Location& l);


    protected:
        string id;
        string name;
        int rating;
        Location location;
};
#endif
