#include "ElementGenerator.h"

ElementGenerator::ElementGenerator(const MeshGenInput &inputData, const QVector<V2d> &nodes) :
    m_inputData(inputData),
    m_nodes(nodes)
{
}

QVector<IndexTriangle> ElementGenerator::generateElements()
{
    Q_ASSERT(false);
    return QVector<IndexTriangle>();    // TODO
}
