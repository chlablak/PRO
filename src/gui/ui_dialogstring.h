/********************************************************************************
** Form generated from reading UI file 'dialogstring.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSTRING_H
#define UI_DIALOGSTRING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dialogString
{
public:
    QPushButton *validateButton;
    QLineEdit *stringEdit;

    void setupUi(QDialog *dialogString)
    {
        if (dialogString->objectName().isEmpty())
            dialogString->setObjectName(QStringLiteral("dialogString"));
        dialogString->resize(362, 41);
        validateButton = new QPushButton(dialogString);
        validateButton->setObjectName(QStringLiteral("validateButton"));
        validateButton->setGeometry(QRect(280, 10, 75, 23));
        stringEdit = new QLineEdit(dialogString);
        stringEdit->setObjectName(QStringLiteral("stringEdit"));
        stringEdit->setGeometry(QRect(10, 10, 261, 20));

        retranslateUi(dialogString);

        QMetaObject::connectSlotsByName(dialogString);
    } // setupUi

    void retranslateUi(QDialog *dialogString)
    {
        dialogString->setWindowTitle(QApplication::translate("dialogString", "Dialog", 0));
        validateButton->setText(QApplication::translate("dialogString", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class dialogString: public Ui_dialogString {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSTRING_H
