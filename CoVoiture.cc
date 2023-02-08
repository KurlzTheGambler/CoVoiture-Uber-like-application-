#include "CoVoiture.h"


CoVoiture::CoVoiture(){}

CoVoiture::~CoVoiture(){
    driver.clear();
    customer.clear();
}


void CoVoiture::addDriver(string name, int rating , Size size, Location l){

    Driver* newDriver =  new Driver(name, rating, size, l);
    driver.add(newDriver);

}

bool CoVoiture::getDriver(string& name, Driver** d) const{
    if(driver.get(name, d)){
        return true;
    }
    cout<<" Cannot get Driver "<<endl;
    return false;

}

bool CoVoiture::removeDriver(string& name){
    Driver* d;
    if(driver.remove(name, &d)){
        return true;
    }
    cout<<"Failed to remove Driver ";
    delete d;
    return false;
}

void CoVoiture::addCustomer(string name, int rating , Location l){
    Customer* newCustomer = new Customer(name, rating , l);
    customer.add(newCustomer);

}

bool CoVoiture::getCustomer(string& name, Customer** c) const{
    if(customer.get(name, c)){
        return true;
    }
    cout<<" Cannot get customer ";
    return false;
}

bool CoVoiture::removeCustomer(string& name){
    Customer* c;
    if(customer.remove(name, &c)){
        return true;
    }
    cout<<"Failed to remove Customer ";
    delete c;
    return false;
}

bool CoVoiture::findRide(string& name, Size size, Driver** d){
    Customer* cust;
    if(customer.get(name, &cust)){
        if(driver.findRide(cust->getRating(), size, cust->getLocation(),d)){

            return true;
        }
    }
    cout<<"Error finding Ride "<<endl;
    return false;
}

void CoVoiture::printCustomers() const{
    customer.print();
}

void CoVoiture::printDrivers()const{
    driver.print();
}


