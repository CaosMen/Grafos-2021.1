#ifndef FORD_H
#define FORD_H

#include "../utils/graph.h"

void print_solution(Graph* graph, int** r_graph, int v_count, ostream* output);
int** residual_graph(Graph* graph);
bool dfs(int** r_graph, int src, int dest, int v_count, int visited[], int path[]);
int ford(Graph* graph, int src, int dest, bool solution, ostream* output);

#endif