#include "texthelper.h"

TextHelper::TextHelper(const QString & text,
                       QWidget * parent = 0) : parent(parent)
{
    setText(text);
    show();
}
