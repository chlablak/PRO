/*! \brief left pane, containing nav buttons and nav menu
 *
 * \file navigationpane.cpp
 * \author Christopher Browne
 * \date 14.05.2016
 */

#include "navigationpane.h"

NavigationPane *NavigationPane::instance = nullptr;
QString *NavigationPane::_baseUrl = nullptr;

NavigationPane::NavigationPane(QWidget *parent) : parent(parent)
{
    buttons = ButtonPane::getInstance(parent);
    navMenu = NavigationMenu::getInstance(parent, _baseUrl);
    navMenu->setMaximumWidth(200);

    addLayout(buttons);
    addWidget(navMenu);
}

NavigationPane *NavigationPane::getInstance(QWidget *parent, QString *baseUrl)
{    
    if (instance == nullptr) {
        _baseUrl = baseUrl;
        instance = new NavigationPane(parent);
    }
    return instance;
}

ButtonPane *NavigationPane::getButtonPane()
{
    return buttons;
}

NavigationMenu *NavigationPane::getNavMenu()
{
    return navMenu;
}
