#include <iostream>
#include <list>

using namespace std;

class Graph {
private:
    int V; // Количество вершин
    list<int>* adjacencyList;

public:
    Graph(int vertices) : V(vertices) {
        // Создание массива списков для хранения списка смежности
        adjacencyList = new list<int>[V];
    }

    // Добавление ребра между вершинами v и w
    void addEdge(int v, int w) {
        // Для неориентированного графа добавляем связь в обе стороны
        adjacencyList[v].push_back(w);
        adjacencyList[w].push_back(v);
    }

    // Вывод списка смежности
    void printAdjacencyList() {
        for (int i = 0; i < V; ++i) {
            cout << "Вершина " << i << " имеет смежные вершины: ";
            for (auto it = adjacencyList[i].begin(); it != adjacencyList[i].end(); ++it) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Создание графа с 5 вершинами
    Graph graph(5);

    // Добавление ребер
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Вывод списка смежности
    cout << "Список смежности:" << endl;
    graph.printAdjacencyList();

    return 0;
}
