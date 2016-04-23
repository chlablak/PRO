#include <QMouseEvent>
#include <QLabel>
#include <QTextEdit>
#include <QTextBrowser>

#ifndef CLICKABLETESTWIDGET_H
#define CLICKABLETESTWIDGET_H


class TextHelper : public QTextBrowser
{
private:
    QTextCursor *cursor;
    QWidget *parent;

public:
    TextHelper(const QString & text, QWidget * parent = 0);

signals:
    void anchorClicked(const QUrl& link);

};

#endif // CLICKABLETESTWIDGET_H
