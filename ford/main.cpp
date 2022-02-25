#include <iostream>
using namespace std;

#include "../utils/utils.h"
#include "../utils/graph.h"

int main(int argc, char** argv) {
  Argument args;
  bool sucess = get_arguments(argc, argv, &args);

  if (sucess) {
    if (args.help) {
      help_arguments("The Ford-Fulkerson algorithm (FFA) is a greedy algorithm that computes the maximum flow in a flow network.");
    } else {
      Graph graph = create_graph(args.input);
      graph.display(args.output);
    }
  } else {
    cout << "The arguments entered are invalid!" << endl;
  }

  return 0;
}