/*! \brief user interface search bar
 *
 * \file searchbar.h
 * \author Christopher Browne
 * \date 22.04.2016
 */

#ifndef SEARCHBAR_H
#define SEARCHBAR_H

#include <QLineEdit>

class SearchBar : public QLineEdit
{
public:
    /*!
     * \brief Returns an instance of SearchBar (singleton)
     * \param parent: parent widget
     * \return Searchbar*
     */
    static SearchBar *getInstance(QWidget *parent);

private:
    SearchBar(QWidget *parent);

    static SearchBar *instance;

    QWidget *parent;
};

#endif // SEARCHBAR_H
