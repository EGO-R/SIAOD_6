#include "Graph.h"

int main() {
    system("chcp 65001");

    int action = -1;
    int value1, value2, weight;

    Graph graph;


    while (action != 7) {
        cout << endl << "-------------------" << endl;
        cout << "1. Insert vertex" << endl
             << "2. Print graph" << endl
             << "3. Add edge" << endl
             << "4. Euler cycle" << endl
             << "5. Exit" << endl;
        cin >> action;
        cout << endl;

        switch (action) {
            case 1:
                graph.addVertex();
                break;

            case 2:
                graph.printGraph();
                break;

            case 3:
                cout << "Введите индексы вершин: ";
                cin >> value1 >> value2;

                if (value1 < 0 || value1 > graph.numVertices - 1 ||
                value2 < 0 || value2 > graph.numVertices - 1) {
                    cout << "Таких веришин нет!" << endl;
                    break;
                }

                cout << "Введите вес ребра: ";
                cin >> weight;

                graph.addEdge(value1, value2, weight);
                break;

            case 4:
                graph.findEulerCycle();
                break;
            case 5:
                break;

            default:
                cout << "Wrong option" << endl;
                break;
        }
    }
}
