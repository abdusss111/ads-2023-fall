#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
    int V; // Количество вершин
    vector<list<int>> adjacencyList;

    // Вспомогательная функция для рекурсивного обхода в глубину
    void DFSUtil(int vertex, vector<bool>& visited) {
        // Помечаем текущую вершину как посещенную
        visited[vertex] = true;
        cout << vertex << " ";

        // Рекурсивно обходим все смежные вершины, если они не были посещены
        for (auto it = adjacencyList[vertex].begin(); it != adjacencyList[vertex].end(); ++it) {
            if (!visited[*it]) {
                DFSUtil(*it, visited);
            }
        }
    }

public:
    Graph(int vertices) : V(vertices) {
        // Создание списка смежности для каждой вершины
        adjacencyList.resize(V);
    }

    // Добавление ребра между вершинами v и w
    void addEdge(int v, int w) {
        adjacencyList[v].push_back(w);
    }

    // Обход графа в глубину с заданной стартовой вершиной
    void DFS(int startVertex) {
        // Массив для отслеживания посещенных вершин
        vector<bool> visited(V, false);

        // Вызов вспомогательной рекурсивной функции для обхода в глубину
        DFSUtil(startVertex, visited);
    }
};

int main() {
    // Создание графа с 5 вершинами
    Graph graph(5);

    // Добавление рёбер
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Начало обхода графа в глубину с вершины 0
    cout << "Результат обхода графа в глубину (DFS) начиная с вершины 0:" << endl;
    graph.DFS(0);

    return 0;
}
