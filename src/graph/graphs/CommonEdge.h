//
// Created by PatrickDesle on 10.05.2016.
//

#ifndef GRAPH_COMMONEDGE_H
#define GRAPH_COMMONEDGE_H

#include <string>
#include "Vertex.h"

class CommonEdge {

private:


protected:
    int _id;
    Vertex *_a;
    Vertex *_b;
    string _label;

    void setId(int id);

public:
    CommonEdge(): _id(-1), _a(nullptr), _b(nullptr), _label("") {}
    CommonEdge(Vertex &from, Vertex &to) : _a(&from), _b(&to), _id(-1), _label("") {}
    CommonEdge(Vertex &from, Vertex &to, const string label) : _a(&from), _b(&to), _id(-1), _label(label) {}

    // Getters
    int id() const;
    string label() const;
    template <typename T>
    friend class Graph;

    inline bool operator == (const CommonEdge* rhs) const {return this->_id == rhs->_id;}
    inline bool operator != (const CommonEdge* rhs) const {return this->_id != rhs->_id;}
    /*inline bool operator< (const CommonEdge& rhs) const { return weight < rhs.Weight(); }
    inline bool operator> (const CommonEdge& rhs) const {return rhs < *this;}
    inline bool operator<=(const CommonEdge& rhs) const {return !(*this > rhs);}
    inline bool operator>=(const CommonEdge& rhs) const {return !(*this < rhs);}*/


};


#endif //GRAPH_COMMONEDGE_H
