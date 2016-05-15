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
private:
    QString fileName;
    QStringList lines;

public:
    FileReader(QString fileName);
	
	/*! \brief return a list of strings from the file
	 */
    QStringList getStringList();
	
	/*! \brief returns a single string representing the whole file
	 */
    QString getString();
};

#endif // FILEREADER_H
