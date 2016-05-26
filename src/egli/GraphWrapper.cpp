/*! \brief Wrap the IGraph class
 *
 * \file GraphWrapper.cpp
 * \author Patrick Champion
 * \date 12.05.2016
 */

#include <typeinfo>

#include "GraphWrapper.h"
#include "Array.h"
#include "TEdge.h"
#include "TVertex.h"
#include "Exception.h"
#include "Number.h"
#include "detail/interface/builtins.h"

egli::GraphWrapper::GraphWrapper(igraph_ptr_t g) :
    m_graph(g)
{
    createIfNull();
}

egli::GraphWrapper::GraphWrapper(const GraphWrapper &o) :
    m_graph(o.graph()->clone())
{}

egli::GraphWrapper::GraphWrapper(GraphWrapper &&o) :
    m_graph(std::move(o.m_graph))
{
    o.m_graph = nullptr;
}

egli::GraphWrapper::~GraphWrapper()
{
    delete m_graph;
}

egli::GraphWrapper &egli::GraphWrapper::operator=(igraph_ptr_t g)
{
    GraphWrapper tmp(g);
    std::swap(m_graph, tmp.m_graph);
    return *this;
}

egli::GraphWrapper &egli::GraphWrapper::operator=(const GraphWrapper &o)
{
    GraphWrapper tmp(o);
    std::swap(m_graph, tmp.m_graph);
    return *this;
}

egli::GraphWrapper &egli::GraphWrapper::operator=(GraphWrapper &&o)
{
    GraphWrapper tmp(std::move(o));
    std::swap(m_graph, tmp.m_graph);
    return *this;
}

egli::GraphWrapper::igraph_ptr_t egli::GraphWrapper::graph()
{
    return m_graph;
}

const egli::GraphWrapper::igraph_ptr_t egli::GraphWrapper::graph() const
{
    return m_graph;
}

void egli::GraphWrapper::insert(detail::RealType<Type::Array>::cref infos)
{
    checkInfos(infos);
    for (size_t i = 0; i < infos.size(); ++i) {
        if (infos.typeOf(i) == Type::Edge)
            insert(infos.get<detail::RealType<Type::Edge>::type>(i));
        else
            insert(infos.get<detail::RealType<Type::Vertex>::type>(i));
    }
}

void egli::GraphWrapper::insert(detail::RealType<Type::Vertex>::cref vertex)
{
    // Vertex ID must increase by 1
    if (graph()->V() < vertex.id)
        throw Exception("vertex id must increase by 1",
                        "egli::GraphWrapper::insert",
                        detail::builtins::toString_v(vertex));

    // Create or reach the Vertex to insert/modify
    vertex_t *v = nullptr;
    if (graph()->V() > vertex.id)   // update
        v = getVertexById(vertex.id);
    else {                          // new
        v = graph()->createVertex();
        graph()->addVertex(v);
    }

    // Set the Vertex informations
    v->setId(vertex.id);
    if (vertex.label.hasValue())
        v->setLabel(vertex.label.value());
    else
        v->setLabel(detail::builtins::toString_i(vertex.id));
    if (vertex.weight.hasValue())
        v->setWeight(vertex.weight.value());
    if (vertex.maxCapacity.hasValue())
        v->setMaxCapacity(vertex.maxCapacity.value());
    if (vertex.minCapacity.hasValue())
        v->setMinCapacity(vertex.minCapacity.value());
}

void egli::GraphWrapper::insert(detail::RealType<Type::Edge>::cref edge)
{
    // Check Vertices existance
    if (edge.v >= graph()->V() || edge.w >= graph()->V())
        throw Exception("edge's defining vertices do not exist",
                        "egli::GraphWrapper::insert",
                        detail::builtins::toString_e(edge));

    // Transform the Graph if necessary
    GraphType type = graphType();
    if (type != GraphType::FlowGraph
        && (edge.maxCapacity.hasValue() || edge.minCapacity.hasValue())) {
        transformTo(GraphType::FlowGraph);
        type = GraphType::FlowGraph;
    } else if (type == GraphType::Graph
               && edge.connection == egli::Edge::Connection::Unidirectional) {
        transformTo(GraphType::DiGraph);
        type = GraphType::DiGraph;
    }

    // Edge to 2 DiEdge case
    if(type != GraphType::Graph
       && edge.connection == egli::Edge::Connection::Bidirectional) {
        egli::Edge tmp(edge);
        tmp.connection = egli::Edge::Connection::Unidirectional;
        insert(tmp);
        std::swap(tmp.v, tmp.w);
        insert(tmp);
        return;
    }

    // Get the list of existing Edges
    vertex_t *v = getVertexById(edge.v);
    vertex_t *w = getVertexById(edge.w);
    std::list<iedge_ptr_t> edges = graph()->getEdges(v, w);

    // Create or reach the Edge to create/modify
    iedge_ptr_t e = nullptr;
    if (edge.id.hasValue() && edge.id.value() < edges.size()) { // update
        auto it = edges.begin();
        for (size_t i = 0; i < edge.id.value(); ++i)
            ++it;
        e = *it;
    } else {                                                    // new
        e = graph()->createEdge(v, w);
        graph()->addEdge(e);
    }

    // Set the Edge informations
    if (edge.weight.hasValue())
        e->setWeight(edge.weight.value());
    if (edge.label.hasValue())
        e->setLabel(edge.label.value());
    if (edge.maxCapacity.hasValue())
        dynamic_cast<FlowEdge*>(e)->setMaxCapacity(edge.maxCapacity.value());
    if (edge.minCapacity.hasValue())
        dynamic_cast<FlowEdge*>(e)->setMinCapacity(edge.minCapacity.value());
}

void egli::GraphWrapper::erase(detail::RealType<Type::Array>::cref infos)
{
    checkInfos(infos);
    for (size_t i = 0; i < infos.size(); ++i) {
        if (infos.typeOf(i) == Type::Edge)
            erase(infos.get<detail::RealType<Type::Edge>::type>(i));
        else
            erase(infos.get<detail::RealType<Type::Vertex>::type>(i));
    }
}

void egli::GraphWrapper::erase(detail::RealType<Type::Vertex>::cref vertex)
{
    // Check if the Vertex is in the Graph
    if (graph()->V() > vertex.id) {

        // Remove it
        vertex_t *v = getVertexById(vertex.id);
        graph()->removeVertex(v);
    }
}

void egli::GraphWrapper::erase(detail::RealType<Type::Edge>::cref edge)
{
    // Check if the vertices are in the Graph
    if (edge.v < graph()->V() && edge.w < graph()->V()) {

        // Edge to 2 DiEdge case
        GraphType type = graphType();
        if (type != GraphType::Graph
            && edge.connection == egli::Edge::Connection::Bidirectional) {
            egli::Edge tmp(edge);
            tmp.connection = egli::Edge::Connection::Unidirectional;
            erase(tmp);
            std::swap(tmp.v, tmp.w);
            erase(tmp);
            return;
        }

        // There is no DiEdge in a simple Graph
        if (type == GraphType::Graph
            && edge.connection != egli::Edge::Connection::Bidirectional) {
            return;
        }

        // Get the edges
        vertex_t *v = getVertexById(edge.v);
        vertex_t *w = getVertexById(edge.w);
        std::list<iedge_ptr_t> edges = graph()->getEdges(v, w);

        // Remove all edges or just one ?
        if (edge.id.hasValue()) { // one
            if (edge.id.value() < edges.size()) {
                auto it = edges.begin();
                for (size_t i = 0; i < edge.id.value(); ++i)
                    ++it;
                graph()->removeEdge(*it);
            }
        } else { // all
            for (auto it = edges.begin(); it != edges.end(); ++it)
                graph()->removeEdge(*it);
        }
    }
}

void egli::GraphWrapper::createIfNull()
{
    if(!m_graph)
        m_graph = new Graph;
}

void egli::GraphWrapper::checkInfos(detail::RealType<Type::Array>::cref infos)
{
    for (size_t i = 0; i < infos.size(); ++i) {
        Type type = infos.typeOf(i);
        if (type != Type::Edge && type != Type::Vertex)
            throw Exception("graphs are only composed of edges and vertices",
                            "egli::GraphWrapper::checkInfos",
                            detail::builtins::toString_a(infos));
    }
}

egli::GraphWrapper::vertex_t *egli::GraphWrapper::getVertexById(size_t id) const
{
    if (id >= graph()->V())
        throw Exception("vertex id does not exist",
                        "egli::GraphWrapper::getVertexById",
                        detail::builtins::toString_i(id));
    for(vertex_t *it : graph()->vertexList()) {
        if (it->id() == id)
            return it;
    }
    return nullptr;
}

egli::GraphWrapper::GraphType egli::GraphWrapper::graphType() const
{
    // Workaround because there is currently no better solution
    const std::type_info &type = typeid(*graph());
    if (type == typeid(::Graph))
        return GraphType::Graph;
    else if (type == typeid(::DiGraph))
        return GraphType::DiGraph;
    else
        return GraphType::FlowGraph;
}

void egli::GraphWrapper::transformTo(GraphType type)
{
    GraphWrapper tmp;
    if (type == GraphType::Graph)
        tmp = GraphAlgorithm::copyToGraph(graph());
    else if (type == GraphType::DiGraph)
        tmp = GraphAlgorithm::copyToDiGraph(graph());
    else
        tmp = GraphAlgorithm::copyToFlowGraph(graph());
    operator=(tmp);
}
