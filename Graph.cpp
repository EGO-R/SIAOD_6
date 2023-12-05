#include "Graph.h"

Graph::Graph() : numVertices(0) {
    matrix.resize(numVertices, vector<int>(numVertices, 0));
}

void Graph::addEdge(int i, int j, int weight) {
    matrix[i][j] = weight;
    matrix[j][i] = weight;
}

void Graph::addVertex() {
    numVertices++;
    for(auto& row : matrix) {
        row.push_back(0);
    }
    matrix.push_back(vector<int>(numVertices, 0));
    addEdgesToVertex(numVertices - 1);
}

void Graph::addEdgesToVertex(int new_index) {
    int index, weight;
    while(true) {
        cout << "Номер вершины для связи: ";
        cin >> index;
        index--;
        if(index < 0) {
            break;
        }

        if (index > numVertices - 1) {
            cout << "Такой вершины нет!" << endl;
            continue;
        }

        cout << "Вес связи: ";
        cin >> weight;
        addEdge(index, new_index, weight);
    }
}

bool Graph::isBridge(int i, int j) {
    int weight = temp_matrix[i][j];
    temp_matrix[i][j] = 0;
    temp_matrix[j][i] = 0;

    vector<bool> visited(numVertices, false);
    DFS(i, &visited);

    temp_matrix[i][j] = weight;
    temp_matrix[j][i] = weight;

    if (visited[j]) {
        return false;
    } else {
        return true;
    }
}

void Graph::DFS(int v, std::vector<bool>* visited) {
    visited->at(v) = true;
    for (int i = 0; i < numVertices; i++) {
        if (temp_matrix[v][i] && !visited->at(i)) {
            DFS(i, visited);
        }
    }
}

bool Graph::isEuler() {
    for (int i = 0; i < numVertices; i++) {
        int degrees = 0;
        for (int j = 0; j < numVertices; j++) {
            if (matrix[i][j] != 0 && i != j)
                ++degrees;
        }

        if (degrees % 2 != 0)
            return false;
    }
    return true;
}

void Graph::findEulerCycle() {
    if (!isEuler()) {
        cout << "Цикла нет" << endl;
        return;
    }
    temp_matrix = matrix;

    int i = 0;
    int degrees = 0;
    while (i < numVertices && degrees == 0) {
        degrees = 0;
        for (int j = 0; j < numVertices; j++) {
            if (matrix[i][j] != 0)
                ++degrees;
        }
    }

    if (degrees == 0) {
        cout << "Цикла нет" << endl;
        return;
    }

    vector<int> cycle;
    while (true) {
        cycle.push_back(i);

        int new_index = -1;
        for (int j = 0; j < numVertices; j++) {
            if (temp_matrix[i][j] != 0) {
                new_index = j;
                if (!isBridge(i, j))
                    break;
            }
        }

        if (new_index == -1)
            break;

        temp_matrix[i][new_index] = 0;
        temp_matrix[new_index][i] = 0;
        i = new_index;
    }

    cout << "Цикл: ";
    for (int i : cycle) {
        cout << i + 1 << " ";
    }
    cout << endl;
}


void Graph::printGraph() {
    if (matrix.empty()) {
        cout << "Граф пустой!" << endl;
        return;
    }
    cout << setw(4) << "";
    for (int i = 0; i < numVertices; i++) {
        cout << setw(3) << i + 1;
    }
    cout << endl;

    cout << setw(3) << "";
    for (int i = 0; i < numVertices; i++) {
        cout << "----";
    }
    cout << endl;

    for (int i = 0; i < numVertices; i++) {
        cout << setw(3) << i + 1 << "|";
        for (int j = 0; j < numVertices; j++) {
            cout << setw(3) << matrix[i][j];
        }
        cout << "\n";
    }
}

void Graph::printTempGraph() {
    if (temp_matrix.empty()) {
        cout << "Граф пустой!" << endl;
        return;
    }
    cout << setw(4) << "";
    for (int i = 0; i < numVertices; i++) {
        cout << setw(3) << i + 1;
    }
    cout << endl;

    cout << setw(3) << "";
    for (int i = 0; i < numVertices; i++) {
        cout << "----";
    }
    cout << endl;

    for (int i = 0; i < numVertices; i++) {
        cout << setw(3) << i + 1 << "|";
        for (int j = 0; j < numVertices; j++) {
            cout << setw(3) << temp_matrix[i][j];
        }
        cout << "\n";
    }
}

bool Graph::isConnected() {
    vector<bool> visited(numVertices, false);
    DFS(0, &visited);

    for (bool i : visited)
        if (!i)
            return false;

    return true;
}

void Graph::prim() {
    temp_matrix = matrix;
    if (!isConnected()) {
        cout << "Граф не связный!" << endl;
        return;
    }
    temp_matrix.clear();
    temp_matrix.resize(numVertices, vector<int>(numVertices, 0));


    vector<bool> visited(numVertices, false);


    visited[0] = true;
    while (true) {
        int min_i = -1, min_j = -1, min_edge = 0;

        for (int i = 0; i < numVertices; i++) {
            if (visited[i]) {
                for (int j = 0; j < numVertices; j++) {
                    if (matrix[i][j] != 0 && i != j && !visited[j]) {
                        if (min_edge == 0 || matrix[i][j] < min_edge) {
                            min_edge = matrix[i][j];
                            min_i = i;
                            min_j = j;
                        }
                    }
                }
            }
        }


        if (min_edge != 0) {
            temp_matrix[min_i][min_j] = matrix[min_i][min_j];
            temp_matrix[min_j][min_i] = matrix[min_j][min_i];
            visited[min_j] = true;
        } else
            break;
    }



    printTempGraph();

}