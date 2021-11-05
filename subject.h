#ifndef __subject_h
#define __subject_h

#include <iomanip>
#include <vector>
#include <iostream>
#include <string>
#include <ostream>
#include <istream>

enum class Subject {MATH = 1 , SCIENCE, ART, HISTORY, ENGLISH};

std::string to_string(Subject s);
std::ostream& operator<<(std::ostream& ost, Subject s);
Subject load_subject(std::istream& ist);

#endif