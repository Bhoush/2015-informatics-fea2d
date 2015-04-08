#ifndef ELEMENTGENERATOR_H
#define ELEMENTGENERATOR_H

#include "MeshGenInput.h"
#include "IndexTriangle.h"

class ElementGenerator
{
public:
    ElementGenerator(const MeshGenInput& inputData, const QVector<V2d>& nodes);
    QVector<IndexTriangle> generateElements();
private:
    const MeshGenInput& m_inputData;
    const QVector<V2d>& m_nodes;
};

#endif // ELEMENTGENERATOR_H
