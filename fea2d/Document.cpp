#include "Document.h"
#include "Exception.h"
#include <QDomDocument>
#include <QFile>

const MeshGenInput& Document::meshGenInput() const
{
    return m_meshGenInput;
}
void Document::setMeshGenInput(const MeshGenInput& meshGenInput)
{
    m_meshGenInput = meshGenInput;
    m_mesh.clear();
    emit changed();
}

const TriangleMesh2d& Document::mesh() const
{
    return m_mesh;
}

void Document::setMesh(const TriangleMesh2d& mesh)
{
    m_mesh = mesh;
    emit changed();
}

void Document::clear() {
    m_meshGenInput = MeshGenInput();
    m_mesh.clear();
    emit changed();
}

void Document::read(const QString& fileName)
{
    QFile f(fileName);
    if (!f.open(QIODevice::ReadOnly))
        throw Exception(tr("Failed to open input file %1").arg(fileName));
    QDomDocument xd;
    if (!xd.setContent(&f))
        throw Exception(tr("Input file %1 does not seem to be an XML document").arg(fileName));

    Q_ASSERT(false);    // TODO: Parse DOM and load it into the document

    emit changed();
}

void Document::write(const QString& fileName) const
{
    Q_UNUSED(fileName);
    Q_ASSERT(false);    // TODO: Parse DOM and load it into the document
}
