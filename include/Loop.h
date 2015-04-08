#ifndef _LOOP_H_
#define _LOOP_H_

#include "Line.h"
#include <QVector>

template<class X, int n>
class Loop : public QVector< Vertex<X,n> >
{
public:
    typedef Vertex<X,n> V;
    typedef Line<X,n> L;
    enum { dim = n };
    L edge(int i) const {
        return L((*this)[i], (*this)[(i+1)%this->size()]);
    }
    Loop<X,n>& operator<<(const V& v) {
        QVector< V >::operator <<(v);
        return *this;
    }
};

template<class S, class X, int n>
S& operator<<(S& s, const Loop<X,n>& loop) {
    return format_array(s, loop, " - ", "- ", " -");
}

typedef Loop<double, 2> Loop2d;


#endif // _LOOP_H_
