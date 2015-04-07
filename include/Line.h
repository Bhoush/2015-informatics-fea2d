#ifndef _LINE_H_
#define _LINE_H_

#include "Vertex.h"

template<class X, int n>
class Line : public std::array< Vertex<X,n>, 2 >
{
private:
    typedef std::array< Vertex<X,n>, 2 > BaseClass;
    typedef Line<X, n> ThisClass;
public:
    typedef Vertex<X,n> V;
    enum { dim = n };

    Line() {}
    Line(const V& v1, const V& v2) : BaseClass{{v1, v2}} {}
};

template<class S, class X, int n>
S& operator<<(S& s, const Line<X,n>& line) {
    return format_array(s, line, " - ");
}

typedef Line<double, 2> Line2d;

#endif // _LINE_H_
