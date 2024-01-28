#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Graph {
private:
    int V; // Количество вершин
    vector<list<int>> adjacencyList;

    // Вспомогательная функция для рекурсивной топологической сортировки
    void topologicalSortUtil(int vertex, vector<bool>& visited, stack<int>& stack) {
        visited[vertex] = true;

        // Рекурсивно обходим все смежные вершины
        for (auto it = adjacencyList[vertex].begin(); it != adjacencyList[vertex].end(); ++it) {
            if (!visited[*it]) {
                topologicalSortUtil(*it, visited, stack);
            }
        }

        // После завершения рекурсии добавляем текущую вершину в стек
        stack.push(vertex);
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

    // Топологическая сортировка графа
    void topologicalSort() {
        // Массив для отслеживания посещенных вершин
        vector<bool> visited(V, false);
        stack<int> stack;

        // Обходим все вершины графа, вызывая рекурсивную функцию, если вершина не была посещена
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, stack);
            }
        }

        // Выводим вершины в порядке топологической сортировки
        cout << "Порядок топологической сортировки: ";
        while (!stack.empty()) {
            cout << stack.top() << " ";
            stack.pop();
        }
    }
};

int main() {
    // Создание графа с 6 вершинами
    Graph graph(6);

    // Добавление рёбер
    graph.addEdge(5, 2);
    graph.addEdge(5, 0);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    // Вызов топологической сортировки
    graph.topologicalSort();

    return 0;
}
