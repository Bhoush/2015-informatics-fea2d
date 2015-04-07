#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Vertex.h"

template<class X, int n>
class Triangle : public std::array< Vertex<X,n>, 3 >
{
private:
    typedef std::array< Vertex<X,n>, 3 > BaseClass;
    typedef Triangle<X, n> ThisClass;
public:
    typedef Vertex<X,n> V;
    enum { dim = n };

    Triangle() {}
    Triangle(const V& v1, const V& v2, const V& v3) : BaseClass{{v1, v2, v3}} {}
};

template<class S, class X, int n>
S& operator <<(S& s, const Triangle<X,n>& triangle) {
    return format_array(s, triangle, " - ");
}

typedef Triangle<double, 2> Triangle2d;

#endif // _TRIANGLE_H_
