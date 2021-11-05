#ifndef __semester_h
#define __semester_h

#include <iomanip>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <ostream>

enum class Semester {FALL = 1 , SPRING, SUMMER};


std::string to_string(Semester s);
std::ostream& operator<<(std::ostream& ost, Semester s);
Semester load_semester(std::istream& ist);

#endif