#ifndef VISUALIZER2D_H
#define VISUALIZER2D_H

#include <QWidget>
#include "Document.h"

class Visualizer2d : public QWidget
{
Q_OBJECT
public:
    explicit Visualizer2d(QWidget *parent = 0);
    const Document *document() const;
    void setDocument(const Document *document);

protected:
    void paintEvent(QPaintEvent *);

private:
    const Document *m_document;
};

#endif // VISUALIZER2D_H
