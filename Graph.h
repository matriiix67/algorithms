//
// Created by Bourne on 2017/12/12.
//

#ifndef ALGORITHMS_GRAPH_H
#define ALGORITHMS_GRAPH_H

#include <vector>
#include <list>
#include <fstream>

class Graph
{
public:
    Graph(int v);
    Graph(std::ifstream& in);

    int v();
    int e();

    void addEdge(int v, int w);
    std::list<int> adj(int v);

    int degree(int v);
    int maxDegree();
    double avgDegree();
    int numberOfSelfLoops();

private:
    int v_;
    int e_;
    std::vector<std::list<int>> adj_;
};


#endif //ALGORITHMS_GRAPH_H
