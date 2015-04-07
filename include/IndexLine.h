#ifndef _INDEXLINE_H_
#define _INDEXLINE_H_

#include "format_array.h"

class IndexLine : public std::array< int, 2 >
{
private:
    typedef std::array< int, 2 > BaseClass;
public:
    IndexLine() {}
    IndexLine(int n1, int n2) : BaseClass{{n1, n2}} {}
};

template<class S>
S& operator<<(S& s, const IndexLine& line) {
    return format_array(s, line, " - ");
}

#endif // _INDEXLINE_H_
