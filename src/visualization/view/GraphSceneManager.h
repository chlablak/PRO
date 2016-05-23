#ifndef VISUALIZATION_GRAPHSCENEMANAGER_H
#define VISUALIZATION_GRAPHSCENEMANAGER_H

#include <unordered_map>

#include "../../graph/graphs/IGraph.h"

#include "GraphScene.h"
#include "../utility/Hash.h"

class GraphSceneManager
{
private:
    static GraphSceneManager *instance;

    std::unordered_map<const IGraph *, GraphScene *> scenes;

    GraphSceneManager();

public:
    GraphSceneManager(const GraphSceneManager &) = delete;
    void operator=(const GraphSceneManager &) = delete;

    static GraphSceneManager *getInstance();

    GraphScene *scene(const IGraph *graph);
};

#endif // VISUALIZATION_GRAPHSCENEMANAGER_H
