#include <iostream>
using namespace std;

#include "ford.h"

#include "../utils/utils.h"
#include "../utils/graph.h"

int main(int argc, char** argv) {
  Argument args;
  bool sucess = get_arguments(argc, argv, &args);

  if (sucess) {
    if (args.help) {
      help_arguments("The Ford-Fulkerson algorithm (FFA) is a greedy algorithm that computes the maximum flow in a flow network.");
    } else {
      if (args.initial != -1) {
        Graph graph = create_graph(args.input);

        if (args.final != -1) {
          if (args.initial != args.final) {
            int max_flow = ford(&graph, args.initial - 1, args.final - 1, args.solution, args.output);

            if (!args.solution) {
              *args.output << max_flow << endl;
            }
          } else {
            cout << "The final vertex must be different from the initial one!" << endl;
          }
        } else {
          for (int i = 0; i < graph.getSize(); i++) {
            if (i != (args.initial - 1)) {
              if (args.solution) {
                *args.output << "For the vertex: " << i + 1 << endl;
              }

              int max_flow = ford(&graph, args.initial - 1, i, args.solution, args.output);
              
              if (!args.solution) {
                *args.output << i + 1 << ":" << max_flow << " ";
              } else if (i != graph.getSize() - 1) {
                *args.output << endl;
              }
            }
          }
          if (!args.solution) {
            *args.output << endl;
          }
        }
      } else {
        cout << "Missing start vertex argument (-i)!" << endl;
      }
    }
  } else {
    cout << "The arguments entered are invalid!" << endl;
  }

  return 0;
}