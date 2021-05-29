#include "11.1 graph.h"
#include "utils/list.h"

/**
 * 创建结构体指针
 */
// typedef struct graph* Graph;

struct graph {
    int nV;             // numberOfVertices
    int nE;             // numberOfEdges
    LinkedList* edges;  // edges数组, 里面是一个个LinkedList
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
    graph->edges = malloc(sizeof(LinkedList) * graph->nV);  // Allocate enough memory. 可以使用remalloc，但这里为了简便，一次分配了所有顶点的空间，每个V对应一个list。

    for(int i = 0; i < graph->nV; i++) {
        graph->edges[i] = NULL;  // 初始化
    }

    return graph;
}

/**
 * 向该Graph中插入一条边
 */
void insertEdge(Graph graph, Edge edge) {
    assert(graph != NULL);

    if(graph->edges[edge->src] == NULL) {
        graph->edges[edge->src] = newList();
    }
    appendByOrder(graph->edges[edge->src], edge->dest);  // 在提供的接口功能中，检查了是否重复，若重复则不添加.

    graph->nE++;
}

// /**
//  * 从该Graph中山删除一条边
//  */
void deleteEdge(Graph graph, Edge edge) {
    assert(graph != NULL);

    delete(graph->edges[edge->src], edge->dest);

    if(isEmptyList(graph->edges[edge->src])) {  // 如果某个顶点V的edges为空，则删除掉该edges数组.
        free(graph->edges[edge->src]);
        graph->edges[edge->src] = NULL;
    }
    graph->nE--;
}

/**
 * 判断是否存在一条边.
 * 若存在，则返回其index; 若不存在，则返回-1
 */
int adjacent(Graph graph, Edge edge) {
    assert(graph != NULL);
    bool flag = false;
    if(graph->edges[edge->src] != NULL) {
        flag = valueIsExist(graph->edges[edge->src], edge->dest);
    }
    return flag;
}

/**
 * 打印该Graph
 */
void printGraph(Graph graph) {
    printf("No. of vertices in graph: %d\n", graph->nV);
    for(int index = 0; index < graph->nV; index++) {
        if(graph->edges[index] != NULL) {
            printf("Vertices: %d\tList: ", index);
            printList(graph->edges[index]);
        }
    }
}

/**
 * 释放掉该Graph申请的内存
 */
void freeGraph(Graph graph) {
    assert(graph != NULL);
    for(int index = 0; index < graph->nV; index++) {
        if(graph->edges[index] != NULL) {
            freeList(graph->edges[index]);
        }
    }
    free(graph->edges);
    free(graph);
}