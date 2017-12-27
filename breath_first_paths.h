//
// Created by Bourne on 2017/12/27.
//

#ifndef ALGORITHMS_BREATH_FIRST_PATHS_H
#define ALGORITHMS_BREATH_FIRST_PATHS_H

#include <vector>
#include <stack>

#include "Graph.h"
using namespace std;

class BreathFirstPaths
{
public:
    BreathFirstPaths(Graph g, int s);
    void Bfs(Graph g, int s);
    bool HasPathTo(int v);
    stack<int> PathTo(int v);
private:
    vector<bool> marked_;
    vector<int> edge_to_;
    int s_;
};


#endif //ALGORITHMS_BREATH_FIRST_PATHS_H
