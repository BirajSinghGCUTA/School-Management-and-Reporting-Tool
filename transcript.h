#ifndef __transcript_h
#define __transcript_h
#include "grade.h"
#include "student.h"
#include "section.h"
 
class Transcript{
    private:
        Section _section;
        Student _student;
        Grade grade;
    public:
        Transcript(Student& student, Section& section);
        Transcript(std::istream& ist);
        void save(std::ostream& ost);
        void assign_grade(Grade _grade);
        friend std::ostream& operator<<(std::ostream& ost, const Transcript &transcript);
};



#endif