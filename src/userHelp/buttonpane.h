/*! \brief top left button pane for navigating back and forth
 *
 * \file buttonpane.h
 * \author Christopher Browne
 * \date 14.05.2016
 */

#ifndef BUTTONPANE_H
#define BUTTONPANE_H

#include <QHBoxLayout>

#include "navigationbutton.h"

class ButtonPane : public QHBoxLayout
{
public:
    /*!
     * \brief Returns an instance of the ButtonPage (singleton)
     * \param parent: parent widget
     * \return ButtonPane*
     */
    static ButtonPane *getInstance(QWidget *parent);

    /*!
     * \brief left (backwards) button accessor
     * \return NavigationButton*
     */
    NavigationButton *getLeft();

    /*!
     * \brief right (forwards) button accessor
     * \return NavigationButton*
     */
    NavigationButton *getRight();

private:
    ButtonPane(QWidget *parent);

	static ButtonPane *instance;
	
    QWidget *parent;
	
    NavigationButton *left;
    NavigationButton *right;
};

#endif // BUTTONPANE_H
