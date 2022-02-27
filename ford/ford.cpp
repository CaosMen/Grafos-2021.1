#include <sstream>
#include <limits.h>
using namespace std;

#include "ford.h"

#include "../utils/graph.h"

void print_solution(int** r_graph, int v_count, ostream* output) {
  for (int i = 0; i < v_count; i++) {
    for (int j = 0; j < v_count; j++) {
      if (r_graph[i][j] != INT_MAX) {
        *output << "(" << i + 1 << "," << j + 1 << ") " << r_graph[i][j] << endl;
      }
    }
  }
}

int** residual_graph(Graph* graph) {
  int v_count = graph->getSize();

  int** r_graph = new int * [v_count];
  for (int i = 0; i < v_count; i++) {
    r_graph[i] = new int[v_count];
    for (int j = 0; j < v_count; j++) {
      r_graph[i][j] = INT_MAX;
    }
  }
  
  for (int i = 0; i < v_count; i++) {
    Node* currentNode = graph->getHead()[i];

    while (currentNode != nullptr) {
      r_graph[i][currentNode->value] = currentNode->cost;
      r_graph[currentNode->value][i] = 0;

      currentNode = currentNode->next;
    }
  }

  return r_graph;
}

bool dfs(int** r_graph, int src, int dest, int v_count, int visited[], int path[]) {
  if (src == dest) {
    return true;
  }

  for (int i = 0; i < v_count; i++) {
    int current = r_graph[src][i];
    if ((current > 0 && current < INT_MAX) && visited[i] == 0) {
      path[src] = i;
      visited[i] = 1;

      if (dfs(r_graph, i, dest, v_count, visited, path)) {
        visited[i] = 0;
        return true;
      } else {
        visited[i] = 0;
        path[src] = -1;
      }
    }
  }

  return false;
}

int ford(Graph* graph, int src, int dest, bool solution, ostream* output) {
  int u, v;
  int max_flow = 0;

  int** r_graph = residual_graph(graph);
  
  int v_count = graph->getSize();

  int path[v_count] = {};
  int visited[v_count] = {};

  visited[src] = 1;

  while (dfs(r_graph, src, dest, v_count, visited, path)) {
    int path_flow = INT_MAX;

    for (u = src; u != dest; u = path[u]) {
      v = path[u];
      path_flow = min(path_flow, r_graph[u][v]);
    }

    for (u = src; u != dest; u = path[u]) {
      v = path[u];
      r_graph[u][v] -= path_flow;
      r_graph[v][u] += path_flow;
    }

    max_flow += path_flow;
  }

  if (solution) {
    print_solution(r_graph, v_count, output);
  }

  return max_flow;
}