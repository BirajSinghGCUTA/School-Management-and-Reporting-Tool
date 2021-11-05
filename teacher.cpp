#include "teacher.h"

Teacher::Teacher(std::string name, std::string email):Person{name,email}{}

Teacher::Teacher(std::istream& ist):Person{"",""} {ist >> name >> email; }

void Teacher::save(std::ostream& ost){ ost << name << "\n" << email << "\n";}

std::string Teacher::full_info() {
    std::string fullinfo = name + "(" + email + ")\n";
    return fullinfo;
}       
