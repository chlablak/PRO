#ifndef NAVIGATIONBUTTON_H
#define NAVIGATIONBUTTON_H

#include <QPushButton>

class NavigationButton : public QPushButton
{
    Q_OBJECT
public:
    NavigationButton();

public slots:
    void mousePressEvent(QMouseEvent *e);

signals:
    void mousePressed();
};

#endif // NAVIGATIONBUTTON_H
