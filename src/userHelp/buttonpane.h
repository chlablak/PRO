/*! \brief top left button pane for navigating back and forth
 *
 * \file buttonpane.h
 * \author Christopher Browne
 * \date 14.05.2016
 */

#ifndef BUTTONPANE_H
#define BUTTONPANE_H

#include <QHBoxLayout>
#include <QPushButton>

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
     * \return QPushButton*
     */
    QPushButton *getLeft();

    /*!
     * \brief right (forwards) button accessor
     * \return QPushButton*
     */
    QPushButton *getRight();

private:
    ButtonPane(QWidget *parent);

	static ButtonPane *instance;
	
    QWidget *parent;
	
    QPushButton *left;
    QPushButton *right;
};

#endif // BUTTONPANE_H
