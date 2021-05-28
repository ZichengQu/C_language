#include <stdlib.h>

#include "11.1 graph.h"

int main() {
    int numberOfVertices = 5;  // 假设有5个顶点
    Graph graph = newGraph(numberOfVertices);
    Edge edge = malloc(sizeof(struct edge)); // 会在heap区分配内存

    edge->src = 0;
    edge->dest = 1;
    insertEdge(graph, edge); // 向graph中插入边
    edge->src = 0;
    edge->dest = 3;
    insertEdge(graph, edge);
    edge->src = 1;
    edge->dest = 3;
    insertEdge(graph, edge);
    edge->src = 2;
    edge->dest = 3;
    insertEdge(graph, edge);

    printGraph(graph); // 打印该graph

    deleteEdge(graph, edge); //从graph中删除
    printGraph(graph); // 打印该graph

    freeGraph(graph); // 释放内存

    return 0;
}