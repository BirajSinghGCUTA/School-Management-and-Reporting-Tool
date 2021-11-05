#include "parent.h"
#include "student.h"
/*Student constructor inherits from person class and adds grade to student */
Student::Student(std::string name, std::string email, int _grade):Person{name, email}, grade{_grade}{}

 Student::Student(std::istream& ist): Person{"",""}{
     ist >> name >> email >> grade;
 }

 void Student::save(std::ostream& ost){
     ost << name << std::endl;
     ost << email << std::endl;
     ost << grade << std::endl;
 }


void Student::add_parent(Parent &parent){
    _parents.push_back(&parent);
}

int Student::parents(){
    return _parents.size();
}

Parent& Student::parent(int index){
    return *_parents.at(index);
}

std::string Student::full_info(){
    std::string parentsname = "parents: ";

    for(auto&x: _parents){
        parentsname += x->to_string() + " ";
    }
    std::string newinfo  = name + " (" + email + ") grade: " +std::to_string(grade) +" "+ parentsname;  
    return newinfo;
}
