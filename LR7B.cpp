#include <stdio.h>
#include <stdlib.h>
#include <clocale> 

#define MAX_VERTICES 100

// Функция для добавления вершины в список смежности
void addEdge(int* adjacencyLists[], int u, int v) {
    adjacencyLists[u][v] = 1;
    adjacencyLists[v][u] = 1; // Для неориентированного графа
}

// Функция для обхода в глубину
void DFS(int* adjacencyLists[], int numVertices, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("Посещенная вершина: %d\n", vertex);

    for (int i = 0; i < numVertices; i++) {
        if (adjacencyLists[vertex][i] == 1 && !visited[i]) {
            DFS(adjacencyLists, numVertices, i, visited);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int numVertices = 6;
    int* adjacencyLists[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        adjacencyLists[i] = (int*)malloc(numVertices * sizeof(int));
    }

    // Инициализация матрицы смежности нулями
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            adjacencyLists[i][j] = 0;
        }
    }

    addEdge(adjacencyLists, 0, 1);
    addEdge(adjacencyLists, 0, 2);
    addEdge(adjacencyLists, 1, 3);
    addEdge(adjacencyLists, 2, 4);
    addEdge(adjacencyLists, 3, 5);

    int visited[MAX_VERTICES] = { 0 };

    printf("Матрица смежности:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjacencyLists[i][j]);
        }
        printf("\n");
    }

    printf("Результат обхода в глубину:\n");
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            DFS(adjacencyLists, numVertices, i, visited);
        }
    }

    // Освобождение памяти
    for (int i = 0; i < MAX_VERTICES; i++) {
        free(adjacencyLists[i]);
    }

    return 0;
}