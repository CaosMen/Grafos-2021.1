#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "../utils/graph.h"

void dijkstra(Graph* graph, int* distance, int* predecessor, int start);
int findShorterDistance(int* distance, int* visited, int gSize);
void printPath(ostream* output, int initial, int final, int gSize, int* predecessor);

#endif