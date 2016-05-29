/*! \brief Common class for edges
 *
 * \file EdgeCommon.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_EDGECOMMON_H
#define GRAPH_EDGECOMMON_H

#include "IEdge.h"

/*! \brief Common graph class for code factoring
 */
class EdgeCommon : public IEdge
{
protected:
    int _id;
    Vertex *_a;
    Vertex *_b;
    string _label;
    double _weight;

public:
    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     */
    EdgeCommon(Vertex *from, Vertex *to)
        : _id(-1), _a(from), _b(to), _label(""), _weight(1) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param weight - The weight of the edge
     */
    EdgeCommon(Vertex *from, Vertex *to, const double weight)
        : _id(-1), _a(from), _b(to), _label(""), _weight(weight) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param label - The name of the edge
     */
    EdgeCommon(Vertex *from, Vertex *to, const string& label)
        : _id(-1), _a(from), _b(to), _label(label), _weight(1) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param label - The name of the edge
     * \param weight - The weight of the edge
     */
    EdgeCommon(Vertex *from, Vertex *to, const string& label, const double weight)
        : _id(-1), _a(from), _b(to), _label(label), _weight(weight) {}

    /*! \brief Copy constructor
     */
    EdgeCommon(const EdgeCommon& e);

    /*! \brief Destructor
     */
    ~EdgeCommon() {}

    virtual string toString() const override;

    virtual int id() const override;

    virtual string label() const override;

    virtual double weight() const override;

    virtual void setId(int id) override;

    virtual void setA(Vertex *v) override;

    virtual void setB(Vertex *v) override;

    virtual void setLabel(const string &label) override;

    virtual void setWeight(double weight) override;
};


#endif //GRAPH_EDGECOMMON_H
