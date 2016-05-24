/*! \brief user interface search bar
 *
 * \file searchbar.cpp
 * \author Christopher Browne
 * \date 22.04.2016
 */

#include "searchbar.h"

SearchBar *SearchBar::instance = nullptr;

SearchBar::SearchBar(QWidget *parent) : parent(parent)
{
    setPlaceholderText("Enter a search term (e.g.: \"Graph\")");
}

SearchBar *SearchBar::getInstance(QWidget *parent)
{
    if (instance == nullptr) {
        instance = new SearchBar(parent);
    }
    return instance;
}
