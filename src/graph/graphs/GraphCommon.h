//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_GRAPHCOMMON_H
#define GRAPH_GRAPHCOMMON_H

#include <vector>
#include "IGraph.h"
#include "Vertex.h"

using namespace std;

class GraphCommon : public IGraph {

private:
    template <typename T>
    void computeId(vector<T> &result, const vector<T> &table);
protected:

    vector<Vertex> _vertices;
    unsigned int edgeId;
    vector<list<Edge*>> _adjacentList;

    void fillAdjacentList(const vector<Edge>& edges);

public:
    GraphCommon() : _vertices(0), _adjacentList(0) { }

    GraphCommon(const vector<Vertex> &vertices);

    GraphCommon(const vector<Vertex> &vertices, const vector<Edge> &edges);

    ~GraphCommon() override { }

    bool isNull() const override;

    bool isEmpty() const;

    virtual bool isSimple() const = 0; // TODO si définir dans common ou classes filles

    bool isConnected() const { return false; }

    virtual bool isStronglyConnected() const = 0; // TODO return isConnected() ici et redéfinir dans DiGraph

    virtual bool isDirected() const = 0;

    bool isNegativeWeighted() const override;

    bool isPlanar() const override;

    virtual IGraph::vertices vertexList() const override ;

    virtual IGraph::edges edgeList() const override ;

    virtual IGraph::edges adjacentEdges(const Vertex* vertex) const override ;

    virtual vector<edges> adjacentList() const override ;

    void ponderateEdges(const double &weight) override;

    void pondeateVertices(const double &weight) override;

    virtual void addEdge(const Edge &e) = 0;

    void addVertex(Vertex &vertex) override;

    virtual void removeEdge(Edge &edge) = 0;

    void removeVertex(Vertex &vertex) override;

    int V() const override { return _vertices.size(); }

    //virtual void accept(const Visitor& v);
};


#endif //GRAPH_GRAPHCOMMON_H
