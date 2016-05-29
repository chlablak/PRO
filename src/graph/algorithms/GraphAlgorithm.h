/*! \brief static Class providing all algorithms implemented in this project
 *
 * \file GraphAlgorithm.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_GRAPHALGORITHM_H
#define GRAPH_GRAPHALGORITHM_H


#include "../graphs/IGraph.h"
#include "../graphs/Graph.h"
#include "../graphs/DiGraph.h"
#include "../graphs/FlowGraph.h"

class GraphAlgorithm
{
public:
    /*! \brief Breadth First Search (BFS) algorithm
     *
     * \param g - The graph on which to apply the BFS
     * \param from - The vertex from where to apply the BFS
     * \param distances - Table containing the order of vertices discovery
     * \return the resulting BFS graph
     */
    static IGraph* bfs(IGraph *g, Vertex *from, vector<double>& distances);

    /*! \brief Depth First Search (DFS) algorithm
     *
     * \param g - The graph on which to apply the DFS
     * \param from - The vertex from where to apply the DFS
     * \param distances - Table containing the order of vertices discovery
     * \return the resulting DFS graph
     */
    static IGraph* dfs(IGraph *g, Vertex *from, vector<double>& dfsnum);

    /*! \brief Connected component (CC) algorithm
     *
     * \param g - The graph on which to search the CCs
     * \return a table where index corresponds to vertex's id and value
     * to the CC where the vertex belongs
     */
    static vector<double> connectedComponent(IGraph *g);

    /*! \brief Stringly Connected component (SCC) algorithm
     *
     * \param g - The graph on which to search the SCCs
     * \return a table where index corresponds to vertex's id and value
     * to the CC where the vertex belongs
     *
     * \throw runtime_error Exception if applied on a non-directed graph
     */
    static vector<double> stronglyConnectedComponent(IGraph *g);

    /*! \brief Search of minimum spanning tree (MST) with Kruskal algorithm's
     *
     * \param g - The graph on which to search the MST
     * \return the MST of g
     *
     * \throw runtime_error Exception if graph is not connected or not weighted
     * \throw runtime_error Exception if applied on directed graphs
     */
    static IGraph* kruskal(IGraph *g);

    /*! \brief Copy any type of graph into a non-directed graph
     *
     * \param g - The graph to copy
     * \return a new non-directed graph
     */
    static IGraph* copyToGraph(IGraph *g);

    /*! \brief Copy any type of graph into a directed graph
     *
     * \param g - The graph to copy
     * \return a new directed graph
     */
    static IGraph* copyToDiGraph(IGraph *g);

    /*! \brief Copy any type of graph into a flow graph
     *
     * \param g - The graph to copy
     * \return a new flow graph
     */
    static IGraph* copyToFlowGraph(IGraph *g);

    /*! \brief Copy any type of graph into a non-directed graph
     *
     * \param g - The graph to copy
     * \return a new non-directed graph
     */
    static IGraph* bellmanFord(IGraph *g, Vertex *from, vector<double>& distances);

    /*! \brief Search for the shortest path in a graph using Dijkstra's algorithm
     *
     * \param g - The graph on which to apply Dijkstra
     * \param from - The source vertex from where to apply Dijkstra
     * \param distances - Table where index corresponds to vertices' ids and
     * where values correspond to the distance from the 'from' vertex and the
     * specific index
     * \return the shortest path from the 'from' vertex to all vertices reachable
     * in the graph
     *
     * \throw runtimer_error Exception if the graph is negatively weighted
     */
    static IGraph* dijkstra(IGraph *g, Vertex *from, vector<double>& distances);

    /*! \brief Determine weither a graph is acyclique an then return the cycle if the graph contains one or an empty graph
    *
    * \param g - The graph on which to search the cycle
    * \return the cycle found in g or an empty graph
    *
    */
    static IGraph* detectCycle(IGraph *g);

    /*! \brief search the topologique order of an acyclique digraph or flowgraph by using topological sort algorithm
    *
    * \param g - The graph on which to search the sort
    * \return a vector of the topoligical order of each vertex of the graph identify by their id
    * \throw runtimer_error Exception if the graph is not a digraph or flow graph
    *
    */
    static vector<double> topologicalSort(IGraph* g);

    /*! \brief Search the maximum flow in a flow graph
     *
     * \param g - The graph on which to search the max flow
     * \param from - The source vertex
     * \param to - The sink vertex
     * \return the max flow of graph g
     *
     * \throw runtimer_error Exception if the graph is not a flow graph
     */
    static int maxFlow(IGraph *g, Vertex *from, Vertex *to);
};


#endif //GRAPH_GRAPHALGORITHM_H
