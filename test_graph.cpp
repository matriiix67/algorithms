//
// Created by Bourne on 2017/12/12.
//

#include <iostream>
#include <vector>
#include <list>
#include <fstream>

#include "Graph.h"

using namespace std;

int main(int argc, char* argv[])
{
    ifstream in("tinyG.txt");
    Graph graph(in);

    int degree = graph.degree(0);
    cout << "degree: " << degree << endl;

    cout << "maxDegree: " << graph.maxDegree() << endl;
    cout << "avgDegree: " << graph.avgDegree() << endl;
    cout << "numberOfSelfLoops: " << graph.numberOfSelfLoops() << endl;
    cout << "end..." << endl;
    return 0;
}
