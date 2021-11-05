#include "student.h"
#include "parent.h"
/*Student constructor inherits from person class and adds grade to student */
Parent::Parent(std::string name, std::string email):Person{name,email}{}

Parent::Parent(std::istream& ist):Person{"",""}{
     ist >> name >> email;
 }

 void Parent::save(std::ostream& ost){
     ost << name << std::endl;
     ost << email << std::endl;
 }

void Parent::add_student(Student& student){
    _students.push_back(&student);
}

int Parent::students(){
    return _students.size();
}

Student& Parent::student(int index){
    return *_students.at(index);
}

std::string Parent::full_info(){
    std::string parentsname = "Students: ";

    for(auto&x: _students){
        parentsname += x->to_string() + " ";
    }
    std::string newinfo  = name + " (" + email + + ") " + parentsname;  
    return newinfo;
}
