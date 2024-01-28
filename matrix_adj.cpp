#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int V; // Количество вершин
    vector<vector< int > > adjacencyMatrix;

public:
    Graph(int vertices) : V(vertices) {
        // Инициализация матрицы смежности
        adjacencyMatrix.assign(V, vector<int>(V, 0));
    }

    // Добавление ребра между вершинами v и w
    void addEdge(int v, int w) {
        // Для неориентированного графа ребро связывает v с w и w с v
        adjacencyMatrix[v][w] = 1;
        adjacencyMatrix[w][v] = 1;
    }

    // Вывод матрицы смежности
    void printAdjacencyMatrix() {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
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

    // Вывод матрицы смежности
    cout << "Матрица смежности:" << endl;
    graph.printAdjacencyMatrix();

    return 0;
}
