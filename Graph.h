#ifndef SIAOD_6_GRAPH_H
#define SIAOD_6_GRAPH_H

#include <iostream>
#include <vector>
using namespace std;


class Graph {
public:
    vector<vector<int>> matrix;
    int numVertices;


    Graph(int numVertices) : numVertices(numVertices) {
        matrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    void addEdge(int i, int j, int weight) {
        matrix[i][j] = weight;
    }

    void addVertex() {
        numVertices++;
        for(auto& row : matrix) {
            row.push_back(0);
        }
        matrix.push_back(vector<int>(numVertices, 0));
        for (int i = 0; i < numVertices; i++) {
            matrix[i][numVertices-1] = 0;
            matrix[numVertices-1][i] = 0;
        }


    }


    void addEdgesToNewVertex() {
        int index, weight;
        std::cout << "Enter the index of a node to connect to the new node and the weight of the edge (enter a negative index to stop):\n";
        while(true) {
            std::cin >> index;
            if(index < 0) {
                break;
            }
            std::cin >> weight;
            addEdge(numVertices-1, index, weight);
        }
    }
};


#endif //SIAOD_6_GRAPH_H
