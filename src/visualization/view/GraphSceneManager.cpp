/*!
 * \brief Visualization scenes manager class
 *
 * \file GraphSceneManager.cpp
 * \author Damien Rochat
 * \date 23.05.2016
 */

#include "GraphSceneManager.h"

GraphSceneManager::GraphSceneManager()
{}

GraphSceneManager *GraphSceneManager::getInstance()
{
    if (instance == nullptr) {
        instance = new GraphSceneManager();
    }
    return instance;
}

GraphScene *GraphSceneManager::scene(const IGraph *graph)
{
    auto it = scenes.find(graph);
    if (it != scenes.end()) {
        return (*it).second;
    }
    GraphScene *scene = new GraphScene(graph);
    scenes[graph] = scene;
    return scene;
}

GraphSceneManager *GraphSceneManager::instance = nullptr;
