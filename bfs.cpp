#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
    int V; // Количество вершин
    vector<list<int>> adjacencyList;

public:
    Graph(int vertices) : V(vertices) {
        // Создание списка смежности для каждой вершины
        adjacencyList.resize(V);
    }

    // Добавление ребра между вершинами v и w
    void addEdge(int v, int w) {
        adjacencyList[v].push_back(w);
    }

    // Обход графа в ширину
    void BFS(int startVertex) {
        // Массив для отслеживания посещенных вершин
        vector<bool> visited(V, false);

        // Создание очереди для BFS
        queue<int> queue;

        // Пометка стартовой вершины как посещенной и добавление ее в очередь
        visited[startVertex] = true;
        queue.push(startVertex);

        while (!queue.empty()) {
            // Извлечение вершины из очереди и вывод ее на экран
            int currentVertex = queue.front();
            cout << currentVertex << " ";
            queue.pop();

            // Перебор всех соседних вершин текущей вершины
            for (auto it = adjacencyList[currentVertex].begin(); it != adjacencyList[currentVertex].end(); ++it) {
                // Если соседняя вершина не была посещена, помечаем ее как посещенную и добавляем в очередь
                if (!visited[*it]) {
                    visited[*it] = true;
                    queue.push(*it);
                }
            }
        }
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

    // Начало обхода графа в ширину с вершины 0
    cout << "Результат обхода графа в ширину (BFS) начиная с вершины 0:" << endl;
    graph.BFS(0);

    return 0;
}
