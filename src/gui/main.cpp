/*! \brief Window to get a string from the user
 *
 * \file dialogstring.h
 * \author Alain Hardy
 * \date 23.04.2016
 */

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

}
