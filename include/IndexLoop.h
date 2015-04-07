#ifndef _INDEXLOOP_H_
#define _INDEXLOOP_H_

#include "IndexLine.h"
#include <QVector>

class IndexLoop : public QVector< int >
{
public:
    IndexLine line(int i) const {
        return IndexLine((*this)[i], (*this)[(i+1)%size()]);
    }
    IndexLoop& operator<<(int v) {
        QVector< int >::operator <<(v);
        return *this;
    }
};

template<class S>
S& operator<<(S& s, const IndexLoop& loop) {
    return format_array(s, loop, " - ", "- ", " -");
}

typedef Loop<double, 2> Loop2d;


#endif // _INDEXLOOP_H_
