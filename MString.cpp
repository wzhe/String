
#include "MString.h"

std::ostream & operator<<(std::ostream &out,const String &obj)
{
    for(size_t i = 0; i < obj.size(); ++i)
    {
        out << obj[i];
    }
    out << '\0';
    return out;
}