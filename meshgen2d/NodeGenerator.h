#ifndef NODEGENERATOR_H
#define NODEGENERATOR_H

#include "MeshGenInput.h"

class NodeGenerator
{
public:
    explicit NodeGenerator(const MeshGenInput& inputData);
    QVector<V2d> generateNodes();
private:
    const MeshGenInput& m_inputData;
};

#endif // NODEGENERATOR_H
