//
// Created by sebri on 12.05.2016.
//

#ifndef GRAPH_IGRAPH_H
#define GRAPH_IGRAPH_H

#include <list>
#include <vector>
#include "IEdge.h"
#include "../algorithms/Visitor.h"

class IGraph {
public:
    typedef list<IEdge*> Edges;
    typedef list<Vertex*> Vertices;

    virtual ~IGraph() { }

    /*! \brief A graph is null if there isn't any vertex
     *
     * \return true if the graph is null
     */
    virtual bool isNull() const = 0;

    /*! \brief A graph is empty if it doesn't contain any edge
     *
     * \return true is the graph is empty
     */
    virtual bool isEmpty() const = 0;

    /*! \brief A graph is weighted if all of his edges have a weight
     *
     * \return true if the graph is weighted
     */
    virtual bool isWeighted() const = 0;

    /*! \brief A graph is negative weighted is at least one of his edges has
     *  a negative weight.
     *
     * \return true if the graph is weighted
     */
    virtual bool isNegativeWeighted() const = 0;

    /*! \brief A graph is planar if it can be draw on a plan without having his
     *  edges crossing
     *
     * \return true if the graph is planar
     */
    virtual bool isPlanar() const = 0;

    /*! \brief A graph is simple if it doesn't have loop edges or parallel edges
     *
     * \return true if the graph is simple
     */
    virtual bool isSimple() const = 0;

    /*! \brief A graph is connected if all of his edges can be reached from
     *  any vertex of the graph
     *
     * \return true if the graph is connected
     */
    virtual bool isConnected() const = 0;

    /*! \brief A directed graph is strongly connected if all of his edges can
     *  be reached from any vertex of the graph
     *
     * \return true if the graph is strongly connected
     */
    virtual bool isStronglyConnected() const = 0;

    /*! \brief A graph is directed if his edges are directed.
     *
     * \return true if the graph is directed
     */
    virtual bool isDirected() const = 0;

    /*! \return the list of vertices of the graph
     */
    virtual Vertices vertexList() const = 0;

    /*! \return the list of edges of the graph
     */
    virtual Edges edgeList() const = 0;

    /*! \brief Get the adjacent edges of a vertex
     *
     * \param v - The vertex from which to get the adjacent edges
     *
     * \return a list of adjacent edges from the vertex passed in parameter
     *
     * \note For directed graphs, it returns the outer directed edges only
     */
    virtual Edges adjacentEdges(const Vertex* v) const = 0;

    /*! \brief Get the adjacent list of the graph. The adjacent list is a
     *  table of list of edges where the index corresponds to the vertex id
     *
     * \return a table of list of edges
     */
    virtual vector<Edges> adjacentList() const = 0;

    /*! \brief Give a same weight to all edges of the graph
     *
     * \param w - The weight to give to edges
     */
    virtual void ponderateEdges(const double w) = 0;

    /*! \brief Give a same weight to all vertices of the graph
     *
     * \param w - The weight to give to vertices
     */
    virtual void ponderateVertices(const double w) = 0;

    /*! \brief Add a vertex to the graph
     *
     * \param v - The vertex to add to the graph
     */
    virtual void addVertex(Vertex *v) = 0;

    /*!
     * \return the number of vertices in the graph
     */
    virtual size_t V() const = 0;

    /*!
     * \return the number of edges in the graph
     */
    virtual size_t E() const = 0;

    /*! \brief Add an edge to the graph
     *
     * \param e - The edge to add to the graph
     */
    virtual void addEdge(IEdge *e) = 0;

    /*! \brief Remove an edge from the graph
     *
     * \param e - The edge to remove from the graph
     */
    virtual void removeEdge(IEdge *e) = 0;

    /*! \brief Remove the vertex with all of his connected edges from the graph,
     *  and then delete it.
     *
     *  \param v - The vertex to remove from the graph
     */
    virtual void removeVertex(Vertex *v) = 0;

    /*! \brief Get all edges between two vertices, also for directed graphs
     *
     * \param v1 - One of the two vertices
     * \param v2 - The other vertex
     *
     * \return a list of edges between v1 and v2
     */
    virtual Edges getEdges(Vertex *v1, Vertex *v2) const = 0;

    /*! \brief Make a new copy of the graph
     *
     * \return a copy of the graph, iindependentfrom it
     */
    virtual IGraph* clone() const = 0;

    /*! \brief Make an empty copy of the graph, i.e. a copy without vertices
     *  and edges
     *
     * \return an empty copy of the graph
     */
    virtual IGraph* emptyClone() const = 0;

    /*! \brief Add the vertex to the graph at its id position
     *
     * \param v - The vertex to assign to the graph
     * TODO : should pe protected
     */
    virtual void assignVertex(Vertex *v) = 0;

    // TODO : should be protected
    virtual void assignEdge(IEdge *ie) = 0;

    /*! \brief Display the graph
     */
    virtual void print() const = 0;

    /*! \brief Facory method to create a vertex
     *
     * \return a new vertex
     *
     * \note The vertex won't be added to the graph
     */
    virtual Vertex *createVertex() const = 0;

    /*! \brief Create a specific edge depending on the type of the graph.
     *  For example, when this method is called on a Graph it returns an Edge,
     *  on a DiGraph it returns a DiEdge, and on a FlowGraph a FlowEdge.
     *
     * \param v - a Vertex
     * \param w - another Vertex (or it can even be the same as v)
     * \return the specific edge created seen as an IEdge
     *
     * \note Neither the vertices nor the Edge created will be added to this graph.
     */
    virtual IEdge *createEdge(Vertex *v, Vertex *w) const = 0;

    /*!
     * \return a stringify representation of the graph
     */
    virtual string toString() const = 0;

    /*! \brief Used with visitor pattern. Accept a visitor and a source vertex.
     *  This method must be redifined in specific sub-classes
     *
     *  \param v - The visitor who want to visit the graph
     *  \param from - The source vertex from where the visitor will visit the graph
     */
    virtual void accept(Visitor *v, Vertex *from) = 0;

    /*! brief Overload of ostream operator to display a graph in the console
     */
    friend ostream& operator<<(ostream& os, const IGraph& ig) {
        return os << ig.toString();
    }



    virtual void printAdjList() const = 0;
};


#endif //GRAPH_IGRAPH_H
