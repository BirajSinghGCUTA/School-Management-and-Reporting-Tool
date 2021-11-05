#include "person.h"

/*constructor for person class. Initializes the name and the email of the person*/
Person::Person(std::string _name, std::string _email):name{_name}, email{_email}{} 

Person::Person(std::istream& ist){
     ist >> name >> email;
 }

 void Person::save(std::ostream& ost){
     ost << name << std::endl;
     ost << email << std::endl;
 }


/*to_string method returns the name of the person. as string eg: Biraj GC*/
std::string Person::to_string() const{
    return name;
}

/*full_info returns the name and the email in () of the person as string eg: Biraj GC (birajsinghgc@gmail.com)*/
std::string Person::full_info(){
    std::string fullinfo = name + " (" + email + ")"; 
    return fullinfo;  
}

/* Prints out the name of the person into the command line*/
std::ostream& operator<<(std::ostream& ost, const Person &person){
    ost << person.name;
    return ost;
}