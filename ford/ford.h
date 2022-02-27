#ifndef FORD_H
#define FORD_H

#include "../utils/graph.h"

/*!
 * @function    print_solution
 * @abstract    Shows the solution to the problem in the output.
 * @param       graph      Pointer to a graph.
 * @param       r_graph    Residual graph.
 * @param       v_count    Quantity of vertex.
 * @param       output     Pointer to the output data.
*/
void print_solution(Graph* graph, int** r_graph, int v_count, ostream* output);

/*!
 * @function    residual_graph
 * @abstract    Create a residual graph.
 * @param       graph    Pointer to a graph.
 * @result      Residual graph.
*/
int** residual_graph(Graph* graph);

/*!
 * @function    dfs
 * @abstract    Checks if there is a valid path between src and dest.
 * @param       r_graph    Residual graph.
 * @param       src        Source node.
 * @param       dest       Destination node.
 * @param       v_count    Quantity of vertex.
 * @param       visited    Array with visited vertices.
 * @param       path       Path to solution.
 * @result      Boolean confirming that a path exists and the path array containing the path (if any).
*/
bool dfs(int** r_graph, int src, int dest, int v_count, int visited[], int path[]);

/*!
 * @function    ford
 * @abstract    Ford algorithm.
 * @param       graph       Pointer to a graph.
 * @param       src         Source node.
 * @param       dest        Destination node.
 * @param       solution    Boolean informing if the solution will be presented.
 * @param       output      Pointer to the output data.
 * @result      Maximum flow.
*/
int ford(Graph* graph, int src, int dest, bool solution, ostream* output);

#endif