/*! \brief Common class for graphs
 *
 * \file GraphCommon.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_GRAPHCOMMON_H
#define GRAPH_GRAPHCOMMON_H

#include <iostream>
#include <vector>
#include "Vertex.h"
#include "IEdge.h"
#include "../algorithms/Visitor.h"
#include "IGraph.h"

using namespace std;

/*! \brief Common graph class for code factoring
 */
template <typename T> // Type of Edges, for example Edge or DiEdge or FlowEdge
class GraphCommon : public IGraph
{
private:
    /*! \brief Set the id and construct the result table from 'table'
     *
     * \param result - The resulting table
     * \param table - The entry table
     */
    void computeId(vector<Vertex*> &result, vector<Vertex*> &table);

protected:
    vector<Edges> _adjacentList;
    size_t _edgeId;
    vector<Vertex*> _vertices;

    /*! \brief Parse each edge to redefine correctly their id
     */
    virtual void resetEdgeId();

public:
    /*! \brief Constructor
     */
    GraphCommon() : _adjacentList(0), _edgeId(0), _vertices(0) { }

    /*! \brief Constructor
     *
     * \param vertices - The vertices to add to the graph
     */
    GraphCommon(vector<Vertex*> &vertices);

    /*! \brief Copy Constructor
     *
     * \param g - the graph to copy
     */
    GraphCommon(const GraphCommon &g) : _adjacentList(g.V()), _edgeId(g.E()), _vertices(g.V(), nullptr) { }

    /* \brief Destructor deletes vertices and edges
     */
    virtual ~GraphCommon();

    virtual bool isNull() const override;

    virtual bool isEmpty() const override;

    virtual bool isWeighted() const override;

    virtual bool isNegativeWeighted() const override;

    virtual bool isPlanar() const override;

    virtual GraphCommon<T>::Vertices vertexList() const override;

    virtual GraphCommon<T>::Edges edgeList() const override;

    virtual GraphCommon<T>::Edges adjacentEdges(const Vertex* v) const override;

    virtual vector<Edges> adjacentList() const override;

    virtual void ponderateEdges(const double w) override;

    virtual void ponderateVertices(const double w) override;

    virtual void addVertex(Vertex *vertex) override;

    virtual Vertex *getVertex(int id) const override;

    virtual size_t V() const override;

    virtual size_t E() const override;

    virtual void assignVertex(Vertex *v) override;

    virtual void print() const override;

    virtual Vertex *createVertex() const override;

    virtual string toString() const override;

    /*! \brief Apply a function to each vertex
     *
     * \param f - Function to apply
     */
    template<typename Func>
    void forEachVertex(Func f) {
        for (Vertex* v : _vertices) {
            f(v);
        }
    }

    /*! \brief Apply a function to each edge
     *
     * \param f - Function to apply
     */
    template <typename Func>
    void forEachEdge(Func f) {
        for (IEdge *e : edgeList()) {
            f(e);
        }
    }

    /*! \brief Apply a function to each adjacent edge of a vertex
     *
     * \param v - The source vertex
     * \param f - Function to apply
     *
     * \note For directed graphs, function is applied to outer edges
     */
    template <typename Func>
    void forEachAdjacentEdge(Vertex *v, Func f) {
        for (IEdge* e : _adjacentList.at(v->id())) {
            f(e);
        }
    }

    /*! \brief Apply a function to each adjacent vertex of a vertex
     *
     * \param v - The source vertex
     * \param f - Function to apply
     *
     * \note For directed graphs, function is applied to both predecessor and
     * successor vertices
     */
    template <typename Func>
    void forEachAdjacentVertex(Vertex *v, Func f) {
        for (IEdge* ie : _adjacentList.at(v->id())) {
            if (ie->either() == v) {
                f(ie->other(ie->either()));
            } else {
                f(ie->either());
            }

        }
    }

    /*! \brief Redefine ostream operator
     *
     * \param os - The stream
     * \param g - The graph to put in the stream
     */
    friend ostream& operator<<(ostream& os, const GraphCommon<T>& g) {
        return os << g.toString();
    }
};

#include "GraphCommon.cpp"

#endif //GRAPH_GRAPHCOMMON_H
