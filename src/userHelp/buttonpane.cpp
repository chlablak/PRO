/*! \brief top left button pane for navigating back and forth
 *
 * \file buttonpane.cpp
 * \author Christopher Browne
 * \date 14.05.2016
 */

#include "buttonpane.h"

ButtonPane *ButtonPane::instance = nullptr;

ButtonPane::ButtonPane(QWidget *parent) : parent(parent)
{
    left = new NavigationButton();
    right = new NavigationButton();

    left->setText("←");
    right->setText("→");

    addWidget(left);
    addWidget(right);
}

ButtonPane *ButtonPane::getInstance(QWidget *parent)
{
    if (instance == nullptr) {
        instance = new ButtonPane(parent);
    }
    return instance;
}

NavigationButton *ButtonPane::getLeft()
{
    return left;
}

NavigationButton *ButtonPane::getRight()
{
    return right;
}
