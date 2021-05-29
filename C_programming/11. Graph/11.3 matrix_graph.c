#include "11.1 graph.h"

#define NO_EDGE 0  // 两个V之间若无边相连，则二维Vertex数组中用 NO_EDGE 的大小表示

// typedef int Vertex;

/**
 * 创建结构体指针
 */
// typedef struct graph* Graph;

struct graph {
    int nV;          // numberOfVertices
    int nE;          // numberOfEdges
    Vertex** edges;  // V * V 的二维Vertex (int)类型的数组, 类似于 Vertex edges[row][col]
};

/**
 * 根据顶点个数，创建一个Graph
 * @param v: numberOfVertices
 */
Graph newGraph(int v) {
    Graph graph = malloc(sizeof(struct graph));
    assert(graph != NULL);  // 在开发时可以这么使用，但最终生产时，最好使用if判断并return. 因为assert如果执行失败，会终止整个程序的执行.

    graph->nV = v;
    graph->nE = 0;

    // V * V 的二维Vertex (int)类型的数组
    graph->edges = malloc(sizeof(Vertex*) * v);  // 二维数组的V行
    for(int i = 0; i < v; i++) {
        graph->edges[i] = malloc(sizeof(Vertex) * v);  // 二维数组的每行中的V列
        for(int j = 0; j < v; j++) {
            graph->edges[i][j] = 0;  // 对 V * V 的二维Vertex (int)类型的数组中的值进行初始化
        }
    }

    return graph;
}

/**
 * 向该Graph中插入一条边;
 * 这里实现的是无向图;
 * 有边为1(无权图)，无边为 NO_EDGE
 */
void insertEdge(Graph graph, Edge edge) {
    assert(graph != NULL);

    int flag = adjacent(graph, edge);
    if(flag != NO_EDGE) {
        printf("该Graph中已存在该Edge, 无需重新插入");
        return;
    }

    graph->edges[edge->src][edge->dest] = 1;  // 无向无权图
    graph->edges[edge->dest][edge->src] = 1;  // 无向无权图; 若有向无权图，则删除此行

    graph->nE++;
}

/**
 * 从该Graph中山删除一条边
 */
void deleteEdge(Graph graph, Edge edge) {
    int flag = adjacent(graph, edge);
    if(flag == NO_EDGE) {
        printf("该Graph中无此Edge，无需删除");
    } else {
        graph->edges[edge->src][edge->dest] = NO_EDGE;  // 无向无权图
        graph->edges[edge->dest][edge->src] = NO_EDGE;  // 无向无权图; 若有向无权图，则删除此行

        graph->nE--;

        printf("该Edge已从Graph中删除");
    }
}

/**
 * 判断是否存在一条边.
 * 若存在，则返回其index; 若不存在，则返回-1
 */
int adjacent(Graph graph, Edge edge) {
    if(graph->edges[edge->src][edge->dest] == 1) {
        return true;
    } else {
        return NO_EDGE;
    }
}

/**
 * 返回该Graph中的顶点V的个数.
 */
int numberOfVerticesInGraph(Graph graph){
    return graph->nV;
}

/**
 * 打印该Graph
 */
void printGraph(Graph graph) {
    printf("No. of vertices in graph: %d\n", graph->nV);
    for(int i = 0; i < graph->nV; i++) {      // 对行进行遍历
        for(int j = 0; j < graph->nV; j++) {  // 对列进行遍历
            if(graph->edges[i][j] == 1) {
                printf("Edge: %d --> %d\n", i, j);  // 优化思想: 因为无向无全图对于 V*V 这个二维数组来说是关于对角线对称的，因此可以只打印对角线的一侧.
            }
        }
    }
}

/**
 * 释放掉该Graph申请的内存
 */
void freeGraph(Graph graph) {
    assert(graph != NULL);
    for(int i = 0; i < graph->nV; i++) {  // 对行进行遍历
        free(graph->edges[i]);            // free每行中的所有列
    }
    free(graph->edges);  // free所有行
    free(graph);         // free整个graph
}