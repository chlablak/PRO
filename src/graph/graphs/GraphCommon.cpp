//
// Created by sebri on 24.04.2016.
//

#include "GraphCommon.h"



void GraphCommon::fillAdjacentList() {
    for(vector<Vertex>::iterator it = _vertices.begin(); it != _vertices.end(); ++it ){
        /* pour chaque edge du graphe vérifier si l'une de ses extremités correspond au vertex courant*/
        for(vector<Edge>::iterator ed = _edges.begin(); ed != _edges.end(); ++ed){
            if((ed->either()->id() == it->id()) || (ed->other(ed->either())->id() == it->id()))
                adjacentList.at(it->id()).push_back(&*ed); // ajouter ce edge dans liste des edges adjacents du vertex courant

        }
    }
}