#include "11.5 dfs.h"

bool dfsPathCheck(Graph graph, Vertex v, Vertex dest, int* visitied) {
    if(v == dest) {
        return true;
    } else {
        int numberOfVertices = numberOfVerticesInGraph(graph);
        Edge edge = malloc(sizeof(struct edge));
        for(Vertex w = 0; w < numberOfVertices; w++) {
            edge->src = v;
            edge->dest = w;
            if(adjacent(graph, edge) == true) {  // 如果graph中存在该edge
                if(visitied[w] == -1) {          // 如果w未被访问过
                    visitied[w] = v;             // 记录当前顶点W的前一个结点, 最后时会是dest结点会是w，其前一个结点便是v.
                    if(dfsPathCheck(graph, w, dest, visitied) == true) {
                        return true;
                    }
                }
            }
        }
        free(edge);
        return false;
    }
}

void printPath(Vertex current, Vertex src, int* visited) {
    if(current != src) {
        printPath(visited[current], src, visited);
        printf(" --> %d", current);
    } else {
        printf("%d", src);
    }
}

void findPath(Graph graph, Vertex src, Vertex dest, int* visited) {
    int numberOfVertices = numberOfVerticesInGraph(graph);

    for(int i = 0; i < numberOfVertices; i++) {
        visited[i] = -1;
    }
    visited[src] = src;
    if(dfsPathCheck(graph, src, dest, visited) == true) {
        printf("DFS路径为(从后向前输出): "); // 6 <-- 5 <-- 1 <-- 0
        Vertex v = dest;  // 从后向前遍历. 
        while(v != src) { // 
            printf("%d <-- ", v);
            v = visited[v];  // 获取路径中，顶点V的前一个顶点
        }
        printf("%d\n", src);

        printf("DFS路径为(从前向后输出): "); // 0 --> 1 --> 5 --> 6
        printPath(dest, src, visited); 
        printf("\n");
    }
}