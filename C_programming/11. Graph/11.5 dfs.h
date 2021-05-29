#include <stdlib.h>

#include "11.1 graph.h"

bool dfsPathCheck(Graph graph, Vertex v, Vertex dest, int* visitied);

void printPath(Vertex current, Vertex src, int* visited);

void findPath(Graph graph, Vertex src, Vertex dest, int* visited);