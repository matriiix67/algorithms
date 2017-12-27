//
// Created by Bourne on 2017/12/27.
//
#include <fstream>
#include <iostream>

#include "cc.h"
#include "Graph.h"

using namespace std;

int main(int argc, char* argv[])
{
    ifstream in("tinyG.txt");
    Graph graph(in);

    CC cc(graph);
    int m = cc.count();

    cout << m << " components" << endl;

    vector<vector<int>> components;
    components.reserve(m);

    for(int v = 0; v < graph.v(); v++) {
        components[cc.id(v)].push_back(v);
    }

    for(int i = 0; i < m; i++) {
        for(int v : components[i]) {
            cout << v << " " ;
        }
        cout << endl;
    }

    return 0;
}
