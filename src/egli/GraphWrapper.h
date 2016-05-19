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

    /*! \brief Constructor
     *
     * \param g - An allocated graph
     */
    GraphWrapper(igraph_ptr_t g = nullptr);

    /*! \brief Copy constructor
     *
     * \param o - The GraphWrapper to copy
     *
     * \note The underlying wrapped graph pointer is cloned
     */
    GraphWrapper(const GraphWrapper &o);

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

    #warning TODO doc
    void insert(detail::RealType<Type::Array>::cref infos);

    void insert(detail::RealType<Type::Vertex>::cref vertex);

    void insert(detail::RealType<Type::Edge>::cref edge);

    void erase(detail::RealType<Type::Array>::cref infos);

    void erase(detail::RealType<Type::Vertex>::cref vertex);

    void erase(detail::RealType<Type::Edge>::cref edge);

private:

    void createIfNull();

    static void checkInfos(detail::RealType<Type::Array>::cref infos);

    vertex_t *getVertexById(size_t id);

    enum class GraphType
    {
        Graph,
        DiGraph,
        FlowGraph
    };

    GraphType graphType() const;

    void transformTo(GraphType type);

    // data member
    igraph_ptr_t m_graph;
};
} // namespace egli

#endif // EGLI_GRAPHWRAPPER_H_INCLUDED
