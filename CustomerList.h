#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H
#include <string>

#include "Customer.h"

class CustomerList{

    class Node {

        public:
            Customer* data;
            Node*    next;
    };

    public:
        CustomerList();
        // Any data left in the List gets destroyed
        ~CustomerList();
        //we have unlimited size, so add always succeeds
        void add(Customer*);
        //return false if name not found
        bool get(const string& name, Customer**) const;
        //double pointer for a return parameter of a pointer
        bool remove(const string& name, Customer**);

        void clear() const;

        void print() const;

        bool isEmpty() const;

    private:
        Node* head;

};


#endif
