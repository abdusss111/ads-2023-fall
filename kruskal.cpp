#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Структура для представления ребра графа
struct Edge {
    int source, destination, weight;
};

class Graph {
private:
    int V; // Количество вершин
    vector<Edge> edges;

public:
    Graph(int vertices) : V(vertices) {}

    // Добавление ребра между вершинами v и w с весом weight
    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }

    // Функция для поиска минимального остовного дерева методом Краскала
    void kruskalMST() {
        // Сортировка рёбер по весу
        sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
            return a.weight < b.weight;
        });

        vector<Edge> result; // Рёбра минимального остовного дерева

        // Инициализация родительских вершин
        vector<int> parent(V, -1);

        // Функция для нахождения корня подмножества
        auto find = [&](int vertex) {
            while (parent[vertex] != -1)
                vertex = parent[vertex];
            return vertex;
        };

        for (const Edge &edge : edges) {
            int x = find(edge.source);
            int y = find(edge.destination);

            // Добавление ребра, если оно не создает цикл
            if (x != y) {
                result.push_back(edge);
                parent[x] = y;
            }
        }

        // Вывод рёбер минимального остовного дерева
        cout << "Рёбра минимального остовного дерева:" << endl;
        for (const Edge &edge : result) {
            cout << edge.source << " - " << edge.destination << " вес: " << edge.weight << endl;
        }
    }
};

int main() {
    int V = 4; // Количество вершин
    Graph graph(V);

    // Добавление рёбер с весами
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    // Вызов алгоритма Краскала
    graph.kruskalMST();

    return 0;
}
