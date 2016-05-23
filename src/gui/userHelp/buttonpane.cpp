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
    left = new QPushButton();
    right = new QPushButton();

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

QPushButton *ButtonPane::getLeft()
{
    return left;
}

QPushButton *ButtonPane::getRight()
{
    return right;
}
