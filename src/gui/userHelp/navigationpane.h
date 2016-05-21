/*! \brief left pane, containing nav buttons and nav menu
 *
 * \file navigationpane.h
 * \author Christopher Browne
 * \date 14.05.2016
 */

#ifndef LEFTPANE_H
#define LEFTPANE_H

#include <QVBoxLayout>
#include <QTextBrowser>

#include "buttonpane.h"
#include "navigationmenu.h"

class NavigationPane : public QVBoxLayout
{
private:
    NavigationPane(QWidget *parent);
	
    static NavigationPane *instance;
    static QString *_baseUrl;

    QWidget *parent;
	
    ButtonPane *buttons;
    NavigationMenu *navMenu;

public:
	/*! \brief Returns an instance of NavPane (singleton)
	 */
    static NavigationPane *getInstance(QWidget *parent, QString *baseUrl);
	
    ButtonPane *getButtonPane();
    NavigationMenu *getNavMenu();
};

#endif // LEFTPANE_H
