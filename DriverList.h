#ifndef DRIVERLIST_H
#define DRIVERLIST_H
#include <string>

#include "Driver.h"
class DriverList{

    class Node {

        public:
            Driver* data;
            Node*    next;
    };

    public:
        DriverList();
        // Any data left in the List gets destroyed
        ~DriverList();
        //we have unlimited size, so add always succeeds
        void add(Driver*);
        //return false if name not found
        bool get(const string& name, Driver**) const;
        //double pointer for a return parameter of a pointer
        bool remove(const string& name, Driver**);

        bool findRide(int rating, Size, Location, Driver** d);

        void clear() const;

        void print() const;

        bool isEmpty() const;

    private:
        Node* head;

};


#endif
