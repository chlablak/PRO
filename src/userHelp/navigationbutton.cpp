#include "navigationbutton.h"

#include <iostream>

NavigationButton::NavigationButton()
{

}

void NavigationButton::mousePressEvent(QMouseEvent *)
{
    emit mousePressed();
}
