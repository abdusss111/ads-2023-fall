#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> iPair;

class Graph {
private:
    int V; // Количество вершин
    vector<vector<iPair>> adjacencyList;

public:
    Graph(int vertices) : V(vertices) {
        adjacencyList.resize(V);
    }

    // Добавление ребра между вершинами v и w с весом weight
    void addEdge(int src, int dest, int weight) {
        adjacencyList[src].push_back(make_pair(dest, weight));
        adjacencyList[dest].push_back(make_pair(src, weight)); // Для неориентированного графа
    }

    // Алгоритм Прима для поиска минимального остовного дерева
    void primMST() {
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq; // Очередь с приоритетом для выбора минимального ребра
        vector<int> key(V, numeric_limits<int>::max()); // Массив для хранения весов рёбер
        vector<bool> inMST(V, false); // Массив для отслеживания рёбер в остовном дереве
        vector<int> parent(V, -1); // Массив для хранения предков

        int startVertex = 0; // Начальная вершина
        pq.push(make_pair(0, startVertex)); // Добавляем начальную вершину в очередь
        key[startVertex] = 0; // Вес начальной вершины равен 0

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true;

            // Обходим все смежные вершины текущей вершины
            for (auto it = adjacencyList[u].begin(); it != adjacencyList[u].end(); ++it) {
                int v = it->first;
                int weight = it->second;

                // Если v не включена в остовное дерево и вес ребра меньше, чем текущий минимальный
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }

        // Вывод рёбер минимального остовного дерева
        cout << "Рёбра минимального остовного дерева:" << endl;
        for (int i = 1; i < V; ++i) {
            cout << parent[i] << " - " << i << endl;
        }
    }
};

int main() {
    int V = 5; // Количество вершин
    Graph graph(V);

    // Добавление рёбер с весами
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 9);

    // Вызов алгоритма Прима
    graph.primMST();

    return 0;
}
