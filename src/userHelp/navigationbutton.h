/*! \brief backward or forward naviation button
 *
 * \file navigationbutton.h
 * \author Christopher Browne
 * \date 16.05.2016
 */


#ifndef NAVIGATIONBUTTON_H
#define NAVIGATIONBUTTON_H

#include <QPushButton>

class NavigationButton : public QPushButton
{
    Q_OBJECT
public:
    /*!
     * \brief NavigationButton constructor
     */
    NavigationButton();

public slots:
    /*!
     * \brief slot that emmits custom mouse press signal
     * \param e
     */
    void mousePressEvent(QMouseEvent *e);

signals:
    /*!
     * \brief custom mouse press signal
     */
    void mousePressed();
};

#endif // NAVIGATIONBUTTON_H
