#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>
#include "User.h"
#include "defs.h"
using namespace std;

class Driver: public User{

    public:

        Driver(string= "Driver", int= 5 , Size size= small, Location l = Location(1,1));
        ~Driver();


        //functions
        bool match(int , Size);
        int getDistance(const Location& l);

        //print
        void print() const;


    private:
        Size size;
        static const char code;
        static int nextId;

};

#endif