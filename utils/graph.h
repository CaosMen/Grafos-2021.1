#ifndef GRAPH_H
#define GRAPH_H

struct Node {
  int value, cost;
  Node* next;
};

struct Edge {
  int src, dest, weight;
};

class Graph {
  private:
    int size;
    Node** head;
  public:
    Graph(Edge edges[], int e_count, int v_count);
    ~Graph();

    int getSize() { return this->size; };
    Node** getHead() { return this->head; };

    Node* addNode(int value, int weight, Node* head);
    bool hasEdge(int src, int dest);

    void display(ostream* output);
};

Graph create_graph(istream* input, bool undirected = false);

#endif