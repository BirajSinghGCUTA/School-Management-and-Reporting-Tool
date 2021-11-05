#ifndef __student_h
#define __student_h
#include "person.h"

class Parent;
class Student: public Person{
    protected:
        int grade;
        typedef std::vector<Parent*> Parents;
        Parents _parents;
    public:
        Student(std::string name, std::string email, int _grade);
        Student(std::istream& ist);
        virtual void save(std::ostream& ost);
        void add_parent(Parent &Parent);
        int parents();
        Parent& parent(int index);
        std::string full_info() override;
        typedef Parents::iterator iterator;
        typedef Parents::const_iterator const_iterator;
        inline iterator begin() {return _parents.begin();};
        inline iterator end(){return _parents.end();};
   
};

#endif