/*! \brief Get the IGraph class (Adapter)
 *
 * \file Graph.h
 * \author Patrick Champion
 * \date 12.05.2016
 */

#ifndef EGLI_GRAPHWRAPPER_H_INCLUDED
#define EGLI_GRAPHWRAPPER_H_INCLUDED

#pragma GCC diagnostic push
# pragma GCC diagnostic warning "-w" // inhibit all warnings
#  include "../graph/includes.h"
#pragma GCC diagnostic pop

#include "detail/RealType.h"

namespace egli
{
/*! \brief Wrap the IGraph class
 */
class GraphWrapper
{
public:

    // Useful typedefs
    using igraph_ptr_t = ::IGraph*;
    using iedge_ptr_t = ::IEdge*;
    using vertex_t = ::Vertex;

    /*! \brief Type of possible Graph
     */
    enum class GraphType
    {
        Graph,
        DiGraph,
        FlowGraph
    };

    /*! \brief Constructor
     *
     * \param g - An allocated graph
     *
     * \note if g == nullptr, a empty Graph is allocated
     */
    GraphWrapper(igraph_ptr_t g = nullptr);

    /*! \brief Copy constructor
     *
     * \param o - The GraphWrapper to copy
     *
     * \note The underlying wrapped graph pointer is cloned
     */
    GraphWrapper(const GraphWrapper &o);

    /*! \brief Move constructor
     *
     * \param o - The GraphWrapper to move
     */
    GraphWrapper(GraphWrapper &&o);

    /*! \brief Destructor
     *
     * \note delete the underlying wrapped graph pointer
     */
    ~GraphWrapper();

    /*! \brief Assignment
     *
     * \param g - An allocated graph
     * \return *this
     */
    GraphWrapper &operator=(igraph_ptr_t g);

    /*! \brief Copy assignment
     *
     * \param o - The GraphWrapper to copy
     * \return *this
     *
     * \note The underlying wrapped graph pointer is cloned
     */
    GraphWrapper &operator=(const GraphWrapper &o);

    /*! \brief Move assignment
     *
     * \param o - The GraphWrapper to move
     * \return *this
     */
    GraphWrapper &operator=(GraphWrapper &&o);

    /*! \brief Get the underlying wrapped graph pointer
     *
     * \return A pointer to a graph
     */
    igraph_ptr_t graph();

    /*! \brief Get the underlying wrapped graph pointer (const)
     *
     * \return A pointer to a graph (const)
     */
    const igraph_ptr_t graph() const;

    /*! \brief Insert Vertex/Edge into the Graph
     *
     * \param infos - A Array of Edge and Vertex
     *
     * \throw Exception if an error occurs
     */
    void insert(detail::RealType<Type::Array>::cref infos);

    /*! \brief Insert Vertex into the Graph
     *
     * \param vertex - A Vertex
     *
     * \throw Exception if an error occurs
     */
    void insert(detail::RealType<Type::Vertex>::cref vertex);

    /*! \brief Insert Edge into the Graph
     *
     * \param edge - A Edge
     *
     * \throw Exception if an error occurs
     */
    void insert(detail::RealType<Type::Edge>::cref edge);

    /*! \brief Erase Vertex/Edge into the Graph
     *
     * \param infos - A Array of Edge and Vertex
     *
     * \throw Exception if an error occurs
     */
    void erase(detail::RealType<Type::Array>::cref infos);

    /*! \brief Erase Vertex into the Graph
     *
     * \param vertex - A Vertex
     *
     * \throw Exception if an error occurs
     */
    void erase(detail::RealType<Type::Vertex>::cref vertex);

    /*! \brief Erase Edge into the Graph
     *
     * \param edge - A Edge
     *
     * \throw Exception if an error occurs
     */
    void erase(detail::RealType<Type::Edge>::cref edge);

    /*! \brief Get the GraphType of the underlying Graph
     *
     * \return The GraphType
     */
    GraphType graphType() const;

    /*! \brief Get a Vertex* by its ID
     *
     * \param id - The vertex ID
     * \return A pointer to the Vertex
     */
    vertex_t *getVertexById(size_t id) const;

    /*! \brief Get the number of Vertex
     *
     * \return Number of vertices
     */
    size_t V() const;

    /*! \brief Get the number of Edge
     *
     * \return Number of edges
     */
    size_t E() const;

private:

    // Create a Graph if there is none
    void createIfNull();

    // Check if the Array is composed of Vertex and Edge only
    static void checkInfos(detail::RealType<Type::Array>::cref infos);

    // Transform the underlying Graph to type
    void transformTo(GraphType type);

    // data member
    igraph_ptr_t m_graph;
};
} // namespace egli

#endif // EGLI_GRAPHWRAPPER_H_INCLUDED
