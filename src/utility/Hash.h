/*! \brief Utility methods for IGraph hashing
 *
 * \file Hash.h
 * \author Damien Rochat
 * \date 23.05.2016
 */

#ifndef UTILITY_HASH_H
#define UTILITY_HASH_H

#include "../graph/Includes.h"

template <class T>
inline void hash_combine(std::size_t &seed, const T &v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x4db9a623 + (seed << 6) + (seed >> 2);
}

namespace std
{

    template <>
    struct hash<const IGraph *>
    {
        size_t operator()(const IGraph *graph) const
        {
            size_t hash = 42;

            hash_combine<string>(hash, typeid(graph).name());

            hash_combine<bool>(hash, graph->isNull());
            hash_combine<bool>(hash, graph->isEmpty());
            hash_combine<bool>(hash, graph->isWeighted());
            hash_combine<bool>(hash, graph->isNegativeWeighted());
            //hash_combine<bool>(hash, graph->isPlanar());
            //hash_combine<bool>(hash, graph->isSimple());
            hash_combine<bool>(hash, graph->isConnected());
            hash_combine<bool>(hash, graph->isStronglyConnected());
            hash_combine<bool>(hash, graph->isDirected());
            hash_combine<size_t>(hash, graph->V());
            hash_combine<size_t>(hash, graph->E());

            for (Vertex *vertex : graph->vertexList()) {
                hash_combine<int>(hash, vertex->id());
                hash_combine<string>(hash, vertex->label());
                hash_combine<double>(hash, vertex->weight());
                hash_combine<int>(hash, vertex->minCapacity());
                hash_combine<int>(hash, vertex->maxCapacity());
            }

            for (IEdge *edge : graph->edgeList()) {
                hash_combine<int>(hash, edge->id());
                hash_combine<string>(hash, edge->label());
                hash_combine<double>(hash, edge->weight());
                hash_combine<int>(hash, edge->from()->id());
                hash_combine<int>(hash, edge->to()->id());

                FlowEdge *flowEdge = dynamic_cast<FlowEdge *>(edge);
                if (flowEdge != NULL) {
                    hash_combine<int>(hash, flowEdge->minCapacity());
                    hash_combine<int>(hash, flowEdge->maxCapacity());
                }
            }

            return hash;
        }
    };
}

#endif // UTILITY_HASH_H
