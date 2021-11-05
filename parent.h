#ifndef __parent_h
#define __parent_h
#include "person.h"

class Student;
class Parent: public Person{

    protected:
        typedef std::vector<Student*> Students;
        Students _students;
    public:
        Parent(std::string name, std::string email);
        Parent(std::istream& ist);
        virtual void save(std::ostream& ost) ;
        void add_student(Student& student);
        int students();
        Student& student(int index);
        std::string full_info() override;
        typedef Students::iterator iterator;
        typedef Students::const_iterator const_iterator;
        inline iterator begin() {return _students.begin();};
        inline iterator end() {return _students.end();};
         
};

#endif