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
public:
    /*!
     * \brief Returns an instance of NavPane (singleton)
     * \param parent: parent widget
     * \param baseUrl: base url for html help
     * \return current instance of the NavPane
     */
    static NavigationPane *getInstance(QWidget *parent, QString *baseUrl);
	
    /*!
     * \brief ButtonPane accessor
     * \return ButtonPane*
     */
    ButtonPane *getButtonPane();

    /*!
     * \brief NavigationMenu accessor
     * \return NavigationMenu*
     */
    NavigationMenu *getNavMenu();

private:
    NavigationPane(QWidget *parent);

    static NavigationPane *instance;
    static QString *_baseUrl;

    QWidget *parent;

    ButtonPane *buttons;
    NavigationMenu *navMenu;

};

#endif // LEFTPANE_H
