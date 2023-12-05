#include "Graph.h"

int main() {
    system("chcp 65001");

    int action = -1;
    int value1, value2, weight;

    Graph graph;


    while (action != 6) {
        cout << endl << "-------------------" << endl;
        cout << "1. Добавить вершину" << endl
             << "2. Вывести граф" << endl
             << "3. Добавить ребро" << endl
             << "4. Найти Эйлеров цикл" << endl
             << "5. Метод Прима" << endl
             << "6. Выход" << endl;
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
                cout << "Введите номера вершин: ";
                cin >> value1 >> value2;

                value1--;
                value2--;

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
                graph.prim();
                break;

            case 6:
                break;

            default:
                cout << "Wrong option" << endl;
                break;
        }
    }
}
