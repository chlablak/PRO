/*! \brief left naviation menu
 *
 * \file navigationmenu.cpp
 * \author Christopher Browne
 * \date 14.05.2016
 */

#include "navigationmenu.h"

NavigationMenu *NavigationMenu::instance = nullptr;
QString *NavigationMenu::_baseUrl = nullptr;

NavigationMenu::NavigationMenu(QWidget *parent) : parent(parent)
{
    setSearchPaths(QStringList(*_baseUrl));
    setSource(QUrl(*_baseUrl + "navigation_menu.html"));
    setOpenLinks(false);
    show();
}

NavigationMenu *NavigationMenu::getInstance(QWidget *parent, QString *baseUrl)
{
    if(instance == nullptr) {
        _baseUrl = baseUrl;
        instance = new NavigationMenu(parent);
    }
    return instance;
}
