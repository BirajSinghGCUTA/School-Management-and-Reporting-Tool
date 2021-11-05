#include "course.h"

Course::Course(Subject subject, int grade): _subject{subject}, _grade{grade}{}

Course::Course(std::istream& ist){
    _subject = load_subject(ist);
    ist >> _grade;
}

void Course::save(std::ostream& ost){
    ost << _subject << '\n' << _grade << '\n';
}

std::ostream& operator<<(std::ostream& ost, const Course& course){
    ost << to_string(course._subject) << " (grade " << course._grade << ")";
    return ost;
}