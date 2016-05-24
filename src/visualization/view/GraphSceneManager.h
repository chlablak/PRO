/*!
 * \brief Visualization scenes manager class
 *
 * \file GraphSceneManager.h
 * \author Damien Rochat
 * \date 23.05.2016
 */

#ifndef VISUALIZATION_GRAPHSCENEMANAGER_H
#define VISUALIZATION_GRAPHSCENEMANAGER_H

#include <unordered_map>

#include "../../graph/graphs/IGraph.h"

#include "GraphScene.h"
#include "../utility/Hash.h"

class GraphSceneManager
{
private:

    /*!
     * \brief Only instance of GraphSceneManager
     */
    static GraphSceneManager *instance;

    /*!
     * \brief All instancied scnes
     */
    std::unordered_map<const IGraph *, GraphScene *> scenes;

    /*!
     * \brief Private constructor
     */
    GraphSceneManager();

public:

    /*!
     * \brief Deleted copy constructor
     */
    GraphSceneManager(const GraphSceneManager &) = delete;

    /*!
     * \brief Delete assignation operator
     */
    void operator=(const GraphSceneManager &) = delete;

    /*!
     * \brief Get the instance of the GraphSceneManager
     *
     * \return the only instance
     */
    static GraphSceneManager *getInstance();

    /*!
     * \brief Private constructor
     */
    GraphScene *scene(const IGraph *graph);
};

#endif // VISUALIZATION_GRAPHSCENEMANAGER_H
