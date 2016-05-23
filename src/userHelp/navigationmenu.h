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
public:
    /*!
     * \brief Returns an instance of NavigationMenu (singleton)
     * \param parent: parent widget
     * \param baseUrl: base url for html files
     * \return NavigationMenu*
     */
    static NavigationMenu *getInstance(QWidget *parent, QString *baseUrl);

private:
    NavigationMenu(QWidget *parent);
	
	static NavigationMenu *instance;
    static QString *_baseUrl;

    QWidget *parent;
};

#endif // NAVIGATIONMENU_H
