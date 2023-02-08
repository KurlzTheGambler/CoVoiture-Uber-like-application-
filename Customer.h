#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "User.h"
using namespace std;


class Customer: public User{

    public:
        Customer(string = "Customer", int = 5, Location l = Location(0,0));
        ~Customer();

        void print() const;


    private:
        static const char code;
        static int nextId;
  
};
#endif