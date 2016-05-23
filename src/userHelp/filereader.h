/*! \brief file reader for HTML help pages
 *
 * \file filereader.h
 * \author Christopher Browne
 * \date 22.04.2016
 */

#ifndef FILEREADER_H
#define FILEREADER_H

#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <exception>

class FileReader
{
public:
    /*!
     * \brief constructor
     * \param fileName
     */
    FileReader(QString fileName);

    /*!
     * \brief return a list of strings from the file
     * \return QStringList a.k.a QList<QString>
     */
    QStringList getStringList();

    /*!
     * \brief returns a single string representing the whole file
     * \return QString
     */
    QString getString();

private:
    QString fileName;
    QStringList lines;
};

#endif // FILEREADER_H
