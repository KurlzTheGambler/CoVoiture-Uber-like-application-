#ifndef COVOITURE_H
#define COVOITURE_H
#include <string>
#include "DriverList.h"
#include "CustomerList.h"

using namespace std;

class CoVoiture{


    public:

        CoVoiture();
        ~CoVoiture();

        // output message needed for any function that return false

        //Driver:
        void addDriver(string name, int rating , Size, Location l);

        bool getDriver(string& name, Driver**) const;

        bool removeDriver(string& name);

        //Customer:

        void addCustomer(string name, int rating , Location l);
        
        bool getCustomer(string& name, Customer**) const;

        bool removeCustomer(string& name);

        //find 

        bool findRide(string& name, Size size, Driver**);

        //print

        void printCustomers() const;

        void printDrivers()const;




    private:
        DriverList driver;
        CustomerList customer;

};
#endif