#ifndef _TRIANGLEMESH2D_H_
#define _TRIANGLEMESH2D_H_

#include "Vertex.h"
#include "IndexTriangle.h"
#include "Triangle.h"
#include <QVector>

class TriangleMesh2d
{
public:
    typedef QVector<V2d> Nodes;
    typedef QVector<IndexTriangle> Elements;

    Nodes& nodes() {
        return m_nodes;
    }
    const Nodes& nodes() const {
        return m_nodes;
    }
    Elements& elements() {
        return m_elements;
    }
    const Elements& elements() const {
        return m_elements;
    }
    V2d& node(int index) {
        return m_nodes[index];
    }
    const V2d& node(int index) const {
        return const_cast<TriangleMesh2d*>(this)->node(index);
    }
    IndexTriangle& element(int index) {
        return m_elements[index];
    }
    const IndexTriangle& element(int index) const {
        return const_cast<TriangleMesh2d*>(this)->element(index);
    }
    Triangle2d triangle(const IndexTriangle& it) const {
        return Triangle2d(node(it[0]), node(it[1]), node(it[2]));
    }
    Triangle2d triangle(int index) const {
        return triangle(element(index));
    }
    bool isEmpty() const {
        return m_nodes.isEmpty() && m_elements.isEmpty();
    }
    void clear() {
        m_nodes.clear();
        m_elements.clear();
    }

private:
    Nodes m_nodes;
    Elements m_elements;

};

#endif // _TRIANGLEMESH2D_H_
