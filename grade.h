#ifndef __grade_h
#define __grade_h

#include <iomanip>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <ostream>

enum class Grade {A = 1,B,C,D,F,I,X};


std::string to_string(Grade s);
std::ostream& operator<<(std::ostream& ost, Grade s);
Grade load_grade(std::istream& ist);

#endif