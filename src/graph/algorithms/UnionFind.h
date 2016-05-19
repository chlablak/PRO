//
// Created by sebri on 18.05.2016.
//

#ifndef GRAPH_UNIONFIND_H
#define GRAPH_UNIONFIND_H


#include <vector>

class UnionFind
{
private:
    std::vector<int> sz;
    std::vector<int> id;
public:
    UnionFind (int N);
    void Union(int p, int q);
    int Find(int p);
    bool Connected(int p, int q);
};


#endif //GRAPH_UNIONFIND_H
