
/**
 * 创建结构体指针
 */
typedef struct graph* Graph;

typedef int Vertex;

typedef struct edge* Edge;

struct edge
{
    Vertex src; // 该edge的起始点
    Vertex dest; // 该edge的终点
    int weight; // 该edge的权重
};


/**
 * 根据顶点个数，创建一个Graph
 * @param v: numberOfVertices
 */
Graph newGraph(int v);

/**
 * 向该Graph中插入一条边
 */
void insertEdge(Graph graph, Edge edge);

/**
 * 从该Graph中山删除一条边
 */
void deleteEdge(Graph graph, Edge edge);

/**
 * 判断是否存在一条边
 */
void adjacent(Graph graph, Edge edge);

/**
 * 打印该Graph
 */
void printGraph(Graph graph);

/**
 * 释放掉该Graph申请的内存
 */
void freeGraph(Graph graph);






