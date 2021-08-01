#include <iostream>
#include <vector>
using namespace std;


// This algorithms should run on a tree or a DAG as far as i know.
// Just print the points in order(left, right, root).

void Post_order(int node, int parent, vector <vector<int>> &graph) {
  for(int &child : graph[node]) {
    if(child == parent) // in case we are on a tree not a DAG. (The symmetry between nodes).
      continue;
    Post_order(child, node, graph);
  }
  printf("%d ", node);
}
