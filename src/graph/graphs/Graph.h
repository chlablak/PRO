//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H


#include "GraphCommon.h"

class Graph : public GraphCommon {
private:

public:

    /**
     * Constructors
     */
    Graph() : GraphCommon() { }
    Graph(const vector<Vertex> vertices) : GraphCommon(vertices) { }
    Graph(const vector<Vertex> &vertices, const vector<Edge> &edges)
            : GraphCommon(vertices, edges) { }

    ~Graph();

    bool isSimple() const override ;

    bool isConnected() const override {
        return true;
    }

    bool isStronglyConnected() const override {
        return false;
    }

    bool isDirected() const override {
        return false;
    }

    void addEdge(const Edge &e) override;

    void removeEdge(Edge &edge) override;
    //virtual void accept(Visitor* v)
};


#endif //GRAPH_GRAPH_H
