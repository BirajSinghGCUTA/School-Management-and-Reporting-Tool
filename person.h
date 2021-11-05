#ifndef __person_h
#define __person_h

#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include <fstream>

class Person{
    public:
        Person(std::string _name, std::string _email); //constructor for person class. Initializes the name and the email of the person
        Person(std::istream& ist);
        virtual void save(std::ostream& ost);
        std::string to_string() const;//returns string name
        virtual std::string full_info();//returns string name + email
        friend std::ostream& operator<<(std::ostream& ost, const Person &person); // prints the name
    protected:
        std::string name;
        std::string email;
};
#endif