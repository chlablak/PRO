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
#  include "../graph/graphs/IGraph.h"
#  include "../graph/graphs/IEdge.h"
#pragma GCC diagnostic pop

namespace egli
{
/*! \brief Wrap the IGraph class
 */
class GraphWrapper
{
public:

    // The true Graph type
    using igraph_ptr_t = IGraph<IEdge>*;

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

private:

    // data member
    igraph_ptr_t m_graph;
};
} // namespace egli

#endif // EGLI_GRAPHWRAPPER_H_INCLUDED
