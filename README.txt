name: Mohsen Elhage

mplemented an Uber-like application called CoVoiture, which maintains two lists of Users - one of
Drivers and one of Customers. Each of these users has a current location in the city. 
A Customer can request a ride from the app and the closest Driver that meets the criteria is selected.

Classes Overview:
The application consisted of 9 classes, including Location, User, Customer, Driver, CustomerList, 
DriverList, CoVoiture, Controller, and View. The Location class contained map coordinates and street 
names, the User class contained CoVoiture user information, the Customer class represented a User who
can hail a ride, the Driver class represented a User who can give a ride, the CustomerList class was a
linked list of all Customers, the DriverList class was a linked list of all Drivers with a specialized
findRide function, the CoVoiture class managed Drivers and Customers, the Controller class controlled
the interaction of CoVoiture with the View, and the View class provided a menu, took input, and gave 
output.




Classes:

    User, cc and h
    Driver, cc and h
    Customer, cc and h
    Location, cc and h
    DriverList, cc and h
    CustomerList, cc and h
    CoVoiture, cc and h
    Makefile
    

    defs.h 
    main.cc
    Controller, cc and h (for testing)
    View, cc and h (for testing)


    to run, open integrated terminal, type make, and then type ./a3 to run the executable 
    use valgrind ./a3 to run the memory check testing
