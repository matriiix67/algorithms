//
// Created by Bourne on 2017/12/27.
//

#include <vector>
#include <queue>
#include <stack>

#include "Graph.h"
#include "cc.h"

using namespace std;

CC::CC(Graph graph)
{
    marked_.reserve(graph.v());
    id_.reserve(graph.v());
    for(int s = 0; s < graph.v(); s++) {
        if(!marked_[s]) {
            Dfs(graph, s);
            count_++;
        }
    }
}

void CC::Dfs(Graph graph, int v)
{
    marked_[v] = true;
    id_[v] = count_;
    for(int w : graph.adj(v)) {
        if(!marked_[w]) {
            Dfs(graph, w);
        }
    }
}