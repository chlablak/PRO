#ifndef VISUALIZATION_CONSTANTS_H
#define VISUALIZATION_CONSTANTS_H

#include <QColor>

// Configuration des sommets
static const qreal  VERTEX_RADIUS = 25;
static const QColor VERTEX_COLOR = Qt::cyan;
static const qreal  VERTEX_BORDER_WIDTH = 2;
static const QColor VERTEX_BORDER_COLOR = Qt::darkGray;
static const QColor VERTEX_TEXT_COLOR = Qt::lightGray;

// Configuration des arcs et arêtes
static const qreal  EDGE_VERTEX_MARGIN = 5;
static const qreal  EDGE_WIDTH = 2;
static const QColor EDGE_COLOR = Qt::darkGray;
static const qreal  EDGE_ARROW_SIZE = 10;

#endif // VISUALIZATION_CONSTANTS_H
