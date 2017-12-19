//
// Created by Bourne on 2017/12/12.
//

#include <vector>
#include <list>
#include <fstream>
#include <iostream>

#include "Graph.h"

Graph::Graph(int v) : v_(v), e_(0), adj_(v)
{
}

Graph::Graph(std::ifstream& in)
{
    int t;
    in >> t;
    v_ = t;
    e_ = 0;
    adj_.resize(v_);

    int e;
    in >> e;
    int v, w;
    for(int i = 0; i < e; i++) {
        in >> v;
        in >> w;
        addEdge(v, w);
    }
}

int Graph::v()
{
    return v_;
}

int Graph::e()
{
    return e_;
}

void Graph::addEdge(int v, int w)
{
    adj_[v].push_front(w);
    adj_[w].push_front(v);
    e_++;
}

std::list<int> Graph::adj(int v)
{
    return adj_[v];
}

int Graph::degree(int v)
{
    int degree = 0;
    for(int w : adj_[v]) degree++;
    return degree;
}

int Graph::maxDegree()
{
    int max = 0;
    for(int v = 0; v < v_; v++) {
        if(degree(v) > max)
            max = degree(v);
    }
    return max;
}
double Graph::avgDegree()
{
    return 2.0 * e_ / v_;
}
int Graph::numberOfSelfLoops()
{
    int count = 0;
    for(int v = 0; v < v_; v++) {
        for(int w : adj_[v]) {
            if(v == w)
                count++;
        }
    }
    return count / 2;
}