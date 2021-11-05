#ifndef __course_h
#define __course_h

#include "subject.h"

class Course{
public:
    Course(Subject subject, int grade);
    Course(std::istream& ist);
    void save(std::ostream& ost);
    friend std::ostream& operator<<(std::ostream& ost, const Course& course);

private:
    int _grade;
    Subject _subject;
};

#endif
