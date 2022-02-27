#ifndef PRIM_H
#define PRIM_H

#include "../utils/graph.h"

int** solution_graph(int size);
int prim(Graph* graph, int src, bool solution, ostream* output);

#endif