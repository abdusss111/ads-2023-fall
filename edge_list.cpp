#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class EdgeListGraph {
private:
    int V; // Количество вершин
    vector<pair<int, int>> edgeList;

public:
    EdgeListGraph(int vertices) : V(vertices) {}

    // Добавление ребра между вершинами v и w
    void addEdge(int v, int w) {
        // Добавление пары вершин как ребра в список рёбер
        edgeList.push_back({v, w});
    }

    // Вывод списка рёбер
    void printEdgeList() {
        cout << "Список рёбер:" << endl;
        for (auto edge : edgeList) {
            cout << edge.first << " - " << edge.second << endl;
        }
    }
};

int main() {
    // Создание графа с 5 вершинами
    EdgeListGraph graph(5);

    // Добавление рёбер
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Вывод списка рёбер
    graph.printEdgeList();

    return 0;
}
