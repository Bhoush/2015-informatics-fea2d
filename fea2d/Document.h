#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "TriangleMesh2d.h"
#include "MeshGenInput.h"
#include <QObject>

class Document : public QObject
{
Q_OBJECT
public:
    const MeshGenInput& meshGenInput() const;
    void setMeshGenInput(const MeshGenInput& meshGenInput);
    const TriangleMesh2d& mesh() const;
    void setMesh(const TriangleMesh2d& mesh);

    void clear();
    void read(const QString& fileName);
    void write(const QString& fileName) const;

signals:
    void changed();

private:
    MeshGenInput m_meshGenInput;
    TriangleMesh2d m_mesh;
};

#endif // DOCUMENT_H
