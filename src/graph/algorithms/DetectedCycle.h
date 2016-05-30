/*! \brief Determine wether a graph is acyclic
 *
 * \file DetectedCycle.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_DETECTEDCYCLE_H
#define GRAPH_DETECTEDCYCLE_H


#include "Visitor.h"
#include "../graphs/IGraph.h"
#include <vector>
#include <stdexcept>

using namespace std;

/*! \brief Determine weither a graph is acyclique an then get the cycle if the graph
 * contains one
 */
class DetectedCycle : public Visitor
{
private:
    vector<bool> _marked;
    vector<bool> _stacked;
    vector<Vertex*> _cycle;
    bool cycleFounded;
    IGraph *_G;
    vector<int> _distances;

    /*! \brief Determine weither a digraph or flowgraph is acyclique an then return and then get the cycle
     *
     * \param g - The CommonDigraph on which to search the cycle
     * \param v - The source vertex from where to start the research the cycle
     *
     */
    void hasCycleDirected(Vertex *v, IGraph* g);

    /*! \brief Determine weither a graph is acyclique an then return and then get the cycle
     *
     * \param g - The graph on which to search the cycle
     * \param from - The source vertex from where to start the research the cycle
     * \param fromId - id of v that will be use by its adjacents vertex to identify it
     */
    void hasCycle(Vertex *v, int fromId, IGraph *g);

    /*! \brief this is a precedure that is common to digraph and flowgraph
     * it forms the graph that represents the cycle found by hasCycleDirected method
     *
     * \param g - The CommonDigraph on which to apply the precedure
     */
    void commonFlowDiGraph (IGraph *g);

public:
    /*! \brief Constructor
     */
    DetectedCycle() : _marked(0), _stacked(0), _cycle(0), cycleFounded(false), _G(nullptr), _distances(0) {}

    /*! \brief Destructor
     */
    virtual ~DetectedCycle()override {}

    virtual void visit(Graph *g, Vertex *from, Vertex *to) override ;

    virtual void visit(DiGraph *g, Vertex *from, Vertex *to) override ;

    virtual void visit(FlowGraph *g, Vertex *from, Vertex *to) override;

    virtual IGraph *G() const override ;

    virtual std::vector<double> table() override ;

};


#endif //GRAPH_DETECTEDCYCLE_H
