#ifndef _INDEXTRIANGLE_H_
#define _INDEXTRIANGLE_H_

#include "IndexLine.h"
#include <QtGlobal>

class IndexTriangle : public std::array< int, 3 >
{
private:
    typedef std::array< int, 3 > BaseClass;
public:
    IndexTriangle() {}
    IndexTriangle(int n1, int n2, int n3) : BaseClass{{n1, n2, n3}} {}
    IndexLine edge(int i) const {
        Q_ASSERT(i >= 0   &&   i < 3);
        return IndexLine((*this)[i], (*this)[(i+1)%3]);
    }
};

template<class S>
S& operator<<(S& s, const IndexTriangle& triangle) {
    return format_array(s, triangle, " - ");
}

#endif // _INDEXTRIANGLE_H_
