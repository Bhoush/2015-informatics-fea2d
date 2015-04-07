#ifndef _MESHGEN2D_H_
#define _MESHGEN2D_H_

#include "meshgen2d_global.h"
#include "Vertex.h"
#include "Line.h"
#include "Triangle.h"
#include <QList>

void MESHGEN2DSHARED_EXPORT f();

template<class X, int n>
class Path
{
private:
    typedef Path<X, n> ThisClass;
public:
    typedef X value_type;
    typedef Vertex<X,n> V;
    typedef Line<X,n> L;
    enum { dim = n };
    V& vertex(int i) {
        return m_data[i];
    }
    const V& vertex(int i) const {
        return (const_cast< ThisClass* >(this))->vertex(i);
    }
    Line line(int i) const {
        return L(m_data[i], m_data[(i+1)%n]);
    }
    ThisClass& operator<<(const V& v) {
        m_data << v;
    }
    int size() const {
        return m_data.size();
    }
    QVector<V>& data() {
        return m_data;
    }
    const QVector<V>& data() const {
        return m_data;
    }

private:

    QVector<V> m_data;
};

typedef QList<V2d> Path2d;
typedef QList<V2i> Path2i;



class MESHGEN2DSHARED_EXPORT Meshgen2d
    {

    public:
        Meshgen2d();
    };

#endif // _MESHGEN2D_H_
