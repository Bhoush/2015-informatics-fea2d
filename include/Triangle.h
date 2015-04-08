#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Line.h"
#include <QtGlobal>

template<class X, int n>
class Triangle : public std::array< Vertex<X,n>, 3 >
{
private:
    typedef std::array< Vertex<X,n>, 3 > BaseClass;
    typedef Triangle<X, n> ThisClass;
public:
    typedef Vertex<X,n> V;
    typedef Line<X,n> L;
    enum { dim = n };

    Triangle() {}
    Triangle(const V& v1, const V& v2, const V& v3) : BaseClass{{v1, v2, v3}} {}
    L edge(int i) const {
        Q_ASSERT(i >= 0   &&   i < 3);
        return L((*this)[i], (*this)[(i+1)%3]);
    }
};

template<class S, class X, int n>
S& operator <<(S& s, const Triangle<X,n>& triangle) {
    return format_array(s, triangle, " - ");
}

typedef Triangle<double, 2> Triangle2d;

#endif // _TRIANGLE_H_
