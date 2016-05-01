//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_GRAPHCOMMON_H
#define GRAPH_GRAPHCOMMON_H


#include <vector>
#include "IGraph.h"
#include "Vertex.h"

using  namespace std;

class GraphCommon : public IGraph {

private:
    unsigned int _edgeid;
    unsigned int _vertexId;
protected:

    virtual void fillAdjacentList();

    vector<Vertex*> _vertices;
    vector<Edge*> _edges;
    vector<edges> _adjacentList;

public:
    GraphCommon() : _vertices(0), _edges(0), _adjacentList(0) {}
    GraphCommon(const vector<Vertex*>& _vertices) : _vertices(_vertices), _edges(0), _adjacentList(0){}
    GraphCommon(const vector<Vertex*>& _vertices, const vector<Edge*>& _edges) : _vertices(_vertices), _edges(_edges) { fillAdjacentList();  }

    virtual ~GraphCommon();

    virtual bool isNull() const override ;

    virtual bool isEmpty() const override ;

    virtual bool isSimple() const override ;

    virtual bool isConnected() const override ;

    virtual bool isStronglyConnected() const override ;

    virtual bool isDirected() const override ;

    virtual bool isNegativeWeighted() const override ;

    virtual bool isPlanar() const override ;

    virtual vertices vertexList() const override ;

    virtual edges edgeList() const override ;

    virtual unsigned int vertexId() override ;

    virtual unsigned int edgeId() override ;

    virtual IGraph::edges adjacentList(const Vertex* _vertex) const override ;

    virtual vector<edges> adjacentList() const override ;

    virtual void ponderate(edges &_edges, const double &_weight) override ;

    virtual void ponderateEdges(const double &_weight) override;

    virtual void ponderate(vertices &_vertices, const double &_weight) override ;

    virtual void addEdge(Edge *_edge) override ;

    virtual void addVertex(Vertex *_vertex) override ;

    virtual void removeEdge(Edge *_edge) override ;

    virtual void removeVertex(Vertex *_vertex) override ;





    //virtual void accept(const Visitor& v);
};


#endif //GRAPH_GRAPHCOMMON_H
