/*! \brief main help window, acts as controller for all signals/slots
 *
 * \file helpwindow.h
 * \author Christopher Browne
 * \date 14.05.2016
 */

#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QHBoxLayout>
#include <QString>
#include "navigationpane.h"
#include "browserpane.h"

class HelpWindow : public QHBoxLayout
{
private:
    HelpWindow(QWidget *parent);
	
	static HelpWindow *instance;
    static QString *_baseUrl;

    QWidget *parent;
	
    NavigationPane *leftPane;
    BrowserPane *rightPane;

public:
	/*! \brief Returns an instance of HelpWindow (singleton)
	 */
    static HelpWindow *getInstance(QWidget *parent, QString *baseUrl);
};

#endif // HELPWINDOW_H
