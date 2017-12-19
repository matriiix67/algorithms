//
// Created by Bourne on 2017/12/12.
//

#include <vector>
#include <stack>
#include <iostream>
#include <fstream>

#include "Graph.h"
#include "DepthFirstPaths.h"
using namespace std;

int main(int argc, char* argv[])
{
    ifstream in("tinyGG.txt");
    Graph graph(in);

    int s = 0;
    DepthFirstPaths search(graph, s);
    for(int v = 0; v < graph.v(); v++) {
        cout << s << " to " << v << ": ";
        if(search.hasPathTo(v)) {
            stack<int> pathTov = search.pathTo(v);

            while(!pathTov.empty()) {
                int x = pathTov.top();
                pathTov.pop();
                if(x == s) {
                    cout << x;
                } else {
                    cout << "-" << x;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
