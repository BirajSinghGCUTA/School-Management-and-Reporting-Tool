#include "semester.h"

std::string to_string(Semester a)
{
    int i = (int) a;
    std::vector<std::string> _sem{"", "fall", "spring", "summer"};
    return _sem[i];
}

std::ostream& operator<<(std::ostream& ost, Semester s)
{
    ost << to_string(s);
    return ost;
}

Semester load_semester(std::istream& ist){
    std::string reader_sem;
    ist >> reader_sem;

    for(Semester m = Semester::FALL; m <= Semester::SUMMER; m = (Semester)((int)m + 1)){
        if(to_string(m).compare(reader_sem) == 0)
            return m;
    }
}
