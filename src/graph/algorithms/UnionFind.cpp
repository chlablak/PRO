//
// Created by sebri on 18.05.2016.
//

#include "UnionFind.h"

UnionFind::UnionFind(int N) {
    id.reserve(N);
    for(int i=0;i<N;++i)
        id[i] = i;
    sz.assign(N,1);
}

void UnionFind::Union(int p, int q) {
    int i = Find(p);
    int j = Find(q);
    if( i == j) return;
    if(sz[i]<sz[j]) // le plus petit arbre
    { // s'accroche au plus grand
        id[i] = j; sz[j] += sz[i];
    } else {
        id[j] = i; sz[i] += sz[j];
    }
}

int UnionFind::Find(int p) {
    while (p != id[p])
        p = id[p] = id[id[p]];
    return p;
}

bool UnionFind::Connected(int p, int q) {
    return Find(p) == Find(q);
}







