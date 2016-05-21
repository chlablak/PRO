/*! \brief left naviation menu
 *
 * \file navigationmenu.h
 * \author Christopher Browne
 * \date 14.05.2016
 */

#ifndef NAVIGATIONMENU_H
#define NAVIGATIONMENU_H

#include <QTextBrowser>

class NavigationMenu : public QTextBrowser
{
    Q_OBJECT
private:
    NavigationMenu(QWidget *parent);
	
	static NavigationMenu *instance;
    static QString *_baseUrl;

    QWidget *parent;
    
public:
	/*! \brief Returns an instance of NavigationMenu (singleton)
	 */
    static NavigationMenu *getInstance(QWidget *parent, QString *baseUrl);
};

#endif // NAVIGATIONMENU_H
