//
// Created by Bourne on 2017/12/12.
//
#include <vector>
#include <stack>
#include <iostream>

#include "DepthFirstPaths.h"
#include "Graph.h"

using namespace std;

DepthFirstPaths::DepthFirstPaths(Graph graph, int start) : marked_(graph.v()), edgeTo_(graph.v()), start_(start)
{
    dfs(graph, start);
}

void DepthFirstPaths::dfs(Graph graph, int v)
{
    marked_[v] = true;
    for(int w : graph.adj(v)) {
        if(!marked_[w]){
            edgeTo_[w] = v;
            dfs(graph, w);
        }
    }
}

bool DepthFirstPaths::hasPathTo(int v)
{
    return marked_[v];
}

std::stack<int> DepthFirstPaths::pathTo(int v)
{
    stack<int> path;
    for(int x = v; x != start_; x = edgeTo_[x]) {
        path.push(x);
    }
    path.push(start_);
    return path;
}
