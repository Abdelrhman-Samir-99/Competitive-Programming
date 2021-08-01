#include <iostream>
#include <vector>
using namespace std;

int T = 1;

void Euler_tour(int node, int parent, vector <vector<int>> &graph, vector <pair<int, int>> &Tour) {
  Tour[node].first = T++;
  // It help us to do some operation on each sub-tree cause of the tour property.
  for(int &child : graph[node]) {
    if(child == parent)
      continue;
    Euler_tour(child, node, graph, Tour);
  }
  Tour[node].second = T++;
}
