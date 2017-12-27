//
// Created by Bourne on 2017/12/27.
//

#ifndef ALGORITHMS_CC_H
#define ALGORITHMS_CC_H

#include <vector>
#include <queue>
#include <stack>

#include "Graph.h"
using namespace std;

class CC
{
public:
    CC(Graph graph);
    void Dfs(Graph graph, int v);
    bool Connected(int v, int w) { return id_[v] == id_[w]; }
    int id(int v) { return id_[v]; }
    int count() { return count_; }
private:
    vector<bool> marked_;
    vector<int> id_;
    int count_;
};


#endif //ALGORITHMS_CC_H
