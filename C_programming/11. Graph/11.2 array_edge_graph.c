#include "11.1 graph.h"

/**
 * 创建结构体指针
 */
// typedef struct graph* Graph;

struct graph {
    int nV;       // numberOfVertices
    int nE;       // numberOfEdges
    Edge* edges;  // Edge数组 也可以 Edge edges[100]
};

// typedef int Vertex;

// typedef struct edge* Edge;

// struct edge {
//     Vertex src;   // 该edge的起始点
//     Vertex dest;  // 该edge的终点
//     int weight;   // 该edge的权重
// };

/**
 * 根据顶点个数，创建一个Graph
 * @param v: numberOfVertices
 */
Graph newGraph(int v) {
    Graph graph = malloc(sizeof(struct graph));
    assert(graph != NULL);  // 在开发时可以这么使用，但最终生产时，最好使用if判断并return. 因为assert如果执行失败，会终止整个程序的执行.

    graph->nV = v;
    graph->nE = 0;
    graph->edges = malloc(sizeof(struct edge) * 100);  // Allocate enough memory. 可以使用remalloc，但这里为了简便，一次分配了100个edge的空间。

    return graph;
}

/**
 * 向该Graph中插入一条边
 */
void insertEdge(Graph graph, Edge edge) {
    assert(graph != NULL);

    int index = adjacent(graph, edge);
    if(index != -1) {
        printf("该Graph中已存在该Edge, 无需重新插入");
        return;
    }

    // graph->edges = edge; // 因为main中的edge是存放在stack区，不是通过malloc存放在heap区的。因此随着stack区中的edge的值的改变，会影响这里。因此不用这样使用.
    graph->edges[graph->nE] = malloc(sizeof(struct edge));
    graph->edges[graph->nE]->src = edge->src;
    graph->edges[graph->nE]->dest = edge->dest;
    graph->edges[graph->nE]->weight = edge->weight;
    graph->nE++;
}

/**
 * 从该Graph中山删除一条边
 */
void deleteEdge(Graph graph, Edge edge) {
    int index = adjacent(graph, edge);
    if(index == -1) {
        printf("该Graph中无此Edge，无需删除");
    } else {
        Edge deleteEdge = graph->edges[index];

        graph->edges[index] = graph->edges[graph->nE - 1];  // Replace <v,w> by last edge in array.
        graph->nE--;

        free(deleteEdge);

        printf("该Edge已从Graph中删除");
    }
}

/**
 * 判断是否存在一条边.
 * 若存在，则返回其index; 若不存在，则返回-1
 */
int adjacent(Graph graph, Edge edge) {
    int index = 0;
    while(index < graph->nE) {
        if(graph->edges[index]->src == edge->src && graph->edges[index]->dest == edge->dest) {
            return index;
        }
        index++;
    }
    return -1;
}

/**
 * 打印该Graph
 */
void printGraph(Graph graph) {
    printf("No. of vertices in graph: %d\n", graph->nV);
    for(int index = 0; index < graph->nE; index++) {
        printf("Edge: %d --> %d\n", graph->edges[index]->src, graph->edges[index]->dest);
    }
}

/**
 * 释放掉该Graph申请的内存
 */
void freeGraph(Graph graph) {
    assert(graph != NULL);
    for(int index = 0; index < graph->nE; index++) {
        free(graph->edges[index]);
    }
    free(graph);
}