#include "subject.h"

std::string to_string(Subject a)
{
    int i = (int) a;
    std::vector<std::string> _sub{"", "math", "science", "art", "history", "english"};
    return _sub[i];
}

std::ostream& operator<<(std::ostream& ost, Subject s)
{
    ost << to_string(s);
    return ost;
}

Subject load_subject(std::istream& ist){

    std::string reader_sub;
    ist >> reader_sub;
    for(Subject m = Subject::MATH; m <= Subject::ENGLISH; m = (Subject)((int)m + 1)){
        if(to_string(m).compare(reader_sub) == 0)
            return m;
    }
   
      //POTENTIAL ERROR, IF File not found Return ?? 
   
}
