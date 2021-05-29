#include <stdlib.h>

#include "11.5 dfs.h"  // #include "11.1 graph.h"已在"11.5 dfs.h"中引用

int main() {
    // DFS via "11.3 matrix_graph.c"
    int numberOfVertices = 10;  // 假设有10个顶点
    Graph graph = newGraph(numberOfVertices);
    Edge edge = malloc(sizeof(struct edge));

    // 结构详见 img/graph/DFS.png
    edge->src = 0;
    edge->dest = 1;
    insertEdge(graph, edge);
    edge->src = 0;
    edge->dest = 2;
    insertEdge(graph, edge);
    edge->src = 0;
    edge->dest = 5;
    insertEdge(graph, edge);
    edge->src = 2;
    edge->dest = 3;
    insertEdge(graph, edge);
    edge->src = 1;
    edge->dest = 5;
    insertEdge(graph, edge);
    edge->src = 3;
    edge->dest = 4;
    insertEdge(graph, edge);
    edge->src = 3;
    edge->dest = 5;
    insertEdge(graph, edge);
    edge->src = 3;
    edge->dest = 8;
    insertEdge(graph, edge);
    edge->src = 4;
    edge->dest = 5;
    insertEdge(graph, edge);
    edge->src = 4;
    edge->dest = 7;
    insertEdge(graph, edge);
    edge->src = 4;
    edge->dest = 8;
    insertEdge(graph, edge);
    edge->src = 5;
    edge->dest = 6;
    insertEdge(graph, edge);
    edge->src = 7;
    edge->dest = 8;
    insertEdge(graph, edge);
    edge->src = 7;
    edge->dest = 9;
    insertEdge(graph, edge);
    edge->src = 8;
    edge->dest = 9;
    insertEdge(graph, edge);

    int* visited = malloc(sizeof(int) * numberOfVertices);

    findPath(graph, 0, 6, visited);

    printf("\n打印visited数组(via DFS):\n当前结点: ");
    for(int i = 0; i < numberOfVertices; i++) {
        printf("%d ", i);
    }
    printf("\n前置结点: ");
    for(int i = 0; i < numberOfVertices; i++) {
        printf("%d ", visited[i]);
    }
    printf("\n");

    free(visited);
    free(edge);
    freeGraph(graph);

    return 0;

    // BFS伪码，"img/graph/BFS伪码描述.png"
}