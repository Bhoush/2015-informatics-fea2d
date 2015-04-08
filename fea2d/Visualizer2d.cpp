#include "Visualizer2d.h"
#include <QPainter>
#include <QPalette>

Visualizer2d::Visualizer2d(QWidget *parent) :
    QWidget(parent),
    m_document(0)
{
}

const Document *Visualizer2d::document() const {
    return m_document;
}

void Visualizer2d::setDocument(const Document *document) {
    if (m_document)
        m_document->disconnect(this);
    m_document = document;
    if (m_document)
        connect(m_document, SIGNAL(changed()), SLOT(update()) );
}

void Visualizer2d::paintEvent(QPaintEvent *)
{
    // TODO: Draw scene
    QPainter painter(this);
    painter.fillRect(rect(), palette().color(QPalette::Base));
    painter.drawText(rect(), Qt::AlignCenter, tr("TODO: Draw scene"));
}
