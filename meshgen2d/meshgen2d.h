#ifndef _MESHGEN2D_H_
#define _MESHGEN2D_H_

#include "meshgen2d_global.h"
#include "TriangleMesh2d.h"
#include "MeshGenInput.h"

class MESHGEN2DSHARED_EXPORT MeshGen2d
{
public:
    const MeshGenInput& inputData() const;
    void setInputData(const MeshGenInput& inputData);
    const TriangleMesh2d& mesh() const;

private:
    MeshGenInput m_inputData;
    mutable TriangleMesh2d m_cachedMesh;

    class Impl;
};

#endif // _MESHGEN2D_H_
