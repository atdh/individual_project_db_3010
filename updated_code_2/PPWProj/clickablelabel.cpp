#include "clickablelabel.h"
#include <QtDebug>

ClickableLabel::ClickableLabel(QWidget* parent)
    : QLabel(parent)
{

}

ClickableLabel::~ClickableLabel()
{
}

void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
    qDebug() << "hi";
    emit clicked();
}
