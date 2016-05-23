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
private:
    ButtonPane(QWidget *parent);

	static ButtonPane *instance;
	
    QWidget *parent;
	
    QPushButton *left;
    QPushButton *right;

public:
	/*! \brief returns an instance of the ButtonPage (singleton)
	 */
    static ButtonPane *getInstance(QWidget *parent);
	
    QPushButton *getLeft();
    QPushButton *getRight();
};

#endif // BUTTONPANE_H
