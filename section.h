#ifndef __section_h
#define __section_h

#include "course.h"
#include "semester.h"
#include "teacher.h"


class Section{
public:
    Section(Course course, Semester semester, int year, Teacher& teacher);
    Section(std::istream& ist);
    void save(std::ostream& ost);
    friend std::ostream& operator<<(std::ostream& ost, const Section& section);

private:
    int _year;
    Course _course;
    Semester _semester;
    Teacher _teacher;
};

#endif
