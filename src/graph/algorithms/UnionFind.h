/*! \brief Union-Find structure for Kruskal algorithm
 *
 * \file UnionFind.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_UNIONFIND_H
#define GRAPH_UNIONFIND_H


#include <vector>

/*! \brief The data structure can be represented as a tree where branches points
 * upward to the parent instead of downward to the children
 */
class UnionFind
{
private:
    std::vector<int> sz;
    std::vector<int> id;
public:
    /*! \brief Constructor. Create the structure for N elements
     *
     * \param N - The number of elements
     */
    UnionFind (int N);

    /*! \brief Destructor
     */
    ~UnionFind() {}

    /*! \brief Meets the equivalent classes p and q
     *
     * \param p - One of the equivalent class to meet
     * \param q - The other equivalent class
     */
    void Union(int p, int q);

    /*! \brief Find the equivalent class p
     *
     * \param p - The equivalent class to find
     * \return the equivalent class found
     */
    int Find(int p);

    /*! \brief Tell if p and q belong to the same equivalent class
     *
     * \param p - One of the equivalent class to meet
     * \param q - The other equivalent class
     * \return true if p and q belong to the same equivalent class
     */
    bool Connected(int p, int q);
};


#endif //GRAPH_UNIONFIND_H
