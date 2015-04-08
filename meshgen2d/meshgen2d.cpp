#include "MeshGen2d.h"
#include "NodeGenerator.h"
#include "ElementGenerator.h"

class MeshGen2d::Impl
{
public:
    explicit Impl(const MeshGenInput& inputData) : m_inputData(inputData) {}
    TriangleMesh2d run()
    {
        TriangleMesh2d result;
        NodeGenerator ng(m_inputData);
        result.nodes() = ng.generateNodes();
        ElementGenerator eg(m_inputData, result.nodes());
        result.elements() = eg.generateElements();
        return result;
    }

private:
    const MeshGenInput& m_inputData;
};


const MeshGenInput& MeshGen2d::inputData() const {
    return m_inputData;
}

void MeshGen2d::setInputData(const MeshGenInput& inputData)
{
    m_inputData = inputData;

    // Clear cache
    m_cachedMesh.clear();
}

const TriangleMesh2d& MeshGen2d::mesh() const
{
    if (m_cachedMesh.isEmpty()) {
        // No cached mesh, generate
        Impl impl(m_inputData);
        m_cachedMesh = impl.run();
    }
    return m_cachedMesh;
}
