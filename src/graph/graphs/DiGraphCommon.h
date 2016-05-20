//
// Created by PatrickDesle on 16.05.2016.
//

#ifndef GRAPH_DIGRAPHCOMMON_H
#define GRAPH_DIGRAPHCOMMON_H



#include "GraphCommon.h"
#include "DiEdgeCommon.h"

template <typename T> // cant be either DiEdge or FlowEdge
class DiGraphCommon : public GraphCommon<T> {

private:
    void assignDiEdge(T *e);

public:
    DiGraphCommon() : GraphCommon<T>::GraphCommon() { }
    DiGraphCommon(vector<Vertex*> &vertices, vector<T*> &edges): GraphCommon<T>::GraphCommon(vertices) {
        for(T* diEdge: edges) {
            addEdge(diEdge);
        }
    }
    DiGraphCommon(vector<Vertex *> &vertices): GraphCommon<T>::GraphCommon(vertices) {}
    DiGraphCommon(const DiGraphCommon& g);

    virtual ~DiGraphCommon();

    virtual bool isSimple() const override;

    virtual bool isConnected() const override;

    virtual bool isStronglyConnected() const override;

    virtual bool isDirected() const override;

    virtual IGraph::Edges edgeList() const override;

    virtual void addEdge(IEdge *e) override;

    virtual void removeEdge(IEdge *e) override;

    virtual void removeVertex(Vertex *v) override;

    virtual size_t E() const override;

    virtual void assignEdge(IEdge *ie) override;

    virtual IGraph::Edges getEdges(Vertex *v1, Vertex *v2) const override;

};

#include "DiGraphCommon.hpp"

#endif //GRAPH_DIGRAPHCOMMON_H
