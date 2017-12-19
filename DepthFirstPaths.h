//
// Created by Bourne on 2017/12/12.
//

#ifndef ALGORITHMS_DEPTHFIRSTPATHS_H
#define ALGORITHMS_DEPTHFIRSTPATHS_H

#include <vector>
#include <stack>
#include "Graph.h"


class DepthFirstPaths
{
public:
    DepthFirstPaths(Graph graph, int start);
    void dfs(Graph graph, int v);
    bool hasPathTo(int v);
    std::stack<int> pathTo(int v);
private:
    std::vector<bool> marked_;
    std::vector<int> edgeTo_;
    int start_;
};


#endif //ALGORITHMS_DEPTHFIRSTPATHS_H
