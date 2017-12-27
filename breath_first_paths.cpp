//
// Created by Bourne on 2017/12/27.
//

#include "breath_first_paths.h"
#include <queue>
#include <stack>

using namespace std;

BreathFirstPaths::BreathFirstPaths(Graph g, int s)
{
    marked_.reserve(g.v());
    edge_to_.reserve(g.v());
    s_ = s;
    Bfs(G, s);
}

void BreathFirstPaths::Bfs(Graph g, int s)
{
    queue<int> iq;
    marked_[s] = true;
    iq.push(s);
    while(!iq.empty()) {
        int v = iq.pop();
        for(int w : g.adj(v)) {
            if(!marked_[w]) {
                edge_to_[w] = v;
                marked_[w] = true;
                iq.push(w);
            }
        }
    }
}

bool BreathFirstPaths::HasPathTo(int v)
{
    return marked_[v];
}

stack<int> BreathFirstPaths::PathTo(int v)
{
    stack<int> path;
    for(int x = v; x != start_; x = edgeTo_[x]) {
        path.push(x);
    }
    path.push(s_);
    return path;
}