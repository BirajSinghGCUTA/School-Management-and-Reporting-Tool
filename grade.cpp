#include "grade.h"

std::string to_string(Grade a)
{
    int i = (int) a;
    std::vector<std::string> _sem{"", "A", "B", "C","D","F","I","X"};
    return _sem[i];
}

std::ostream& operator<<(std::ostream& ost, Grade s)
{
    ost << to_string(s);
    return ost;
}

Grade load_grade(std::istream& ist){
    std::string reader_grd;
    ist >> reader_grd;

    for(Grade m = Grade::A ; m <= Grade::X; m = (Grade)((int)m + 1)){
        if(to_string(m).compare(reader_grd) == 0)
            return m;
    }
}
