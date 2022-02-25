#include <fstream>
#include <sstream>
using namespace std;

#include "graph.h"

Graph::Graph(Edge edges[], int e_count, int v_count) {
  this->head = new Node*[v_count]();
  this->size = v_count;

  for (int i = 0; i < v_count; ++i) {
    head[i] = nullptr;
  }

  for (unsigned i = 0; i < e_count; i++) {
    int src_ver = edges[i].src;
    int dest_ver = edges[i].dest;
    int weight_ver = edges[i].weight;

    Node* newNode = addNode(dest_ver, weight_ver, this->head[src_ver]);
    this->head[src_ver] = newNode;
  }
}

Graph::~Graph() {
  for (int i = 0; i < size; i++) {
    delete[] head[i];
    delete[] head;
  }
}

Node* Graph::addNode(int value, int weight, Node* head) {
  Node* newNode = new Node;
  newNode->value = value;
  newNode->cost = weight;

  newNode->next = head;
  return newNode;
}

void Graph::display(ostream* output) {
  for (int i = 0; i < this->size; i++) {
    Node* currentNode = this->head[i];

    while (currentNode != nullptr) {
      if (i > 0) {
        *output << endl;
      } 

      *output << "(" << i + 1 << ", " << currentNode->value + 1 << ", " << currentNode->cost << ") ";
      currentNode = currentNode->next;
    }
  }
}

Graph create_graph(istream* input) {
  int v_count, e_count;
  *input >> v_count >> e_count;

  string line;
  getline(*input, line);

  Edge edges[e_count] = {};
  for (int i = 0; i < e_count; i++) {
    getline(*input, line);
    
    istringstream line_cin(line);
    int src, dest, weight = 1;
    line_cin >> src >> dest >> weight;

    edges[i] = {src - 1, dest - 1, weight};
  }

  return Graph(edges, e_count, v_count);
}