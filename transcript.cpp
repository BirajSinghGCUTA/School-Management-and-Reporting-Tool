#include "transcript.h"

Transcript::Transcript(Student& student, Section& section): _student{student}, _section(section){}
Transcript::Transcript(std::istream& ist): _student{Student{ist}}, _section{Section{ist}}, grade{load_grade(ist)}{}

void Transcript::save(std::ostream& ost){
_student.save(ost);
_section.save(ost);
ost << grade << "\n";
}

void Transcript::assign_grade(Grade _grade ){
    grade = _grade;
}

std::ostream& operator<<(std::ostream& ost, const Transcript &transcript){
    ost << "In "<< transcript._section << ": " << transcript._student << " earned a " << transcript.grade << "\n";
    return ost;
}

