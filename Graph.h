#ifndef SIAOD_6_GRAPH_H
#define SIAOD_6_GRAPH_H

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


class Graph {
public:
    vector<vector<int>> matrix;
    vector<vector<int>> temp_matrix;
    int numVertices;


    Graph();

    void addEdge(int i, int j, int weight);

    void addVertex();


    void addEdgesToVertex(int new_index);

    bool isBridge(int i, int j);

    void DFS(int v, std::vector<bool>* visited);

    bool isEuler();


    void findEulerCycle();

    void printGraph();

    void printTempGraph();

    bool isConnected();

    void prim();
};


#endif //SIAOD_6_GRAPH_H
