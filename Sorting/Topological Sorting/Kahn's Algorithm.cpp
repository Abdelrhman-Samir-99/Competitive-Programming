#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;



// This algorithm is used to find a topological order of items in O(|E| + |V|).
// This must run on a DAG.
vector <int> Kahns_Algorithm(vector <vector<int>> &adjacency_list) {
  int n = adjacency_list.size();
  vector <int> Indegree(n + 1, 0);
  for(int u = 0; u < n; ++u) {
    for(int &v : adjacency_list[u])
      ++Indegree[v];
  }
  
  vector <int> Topology;
  for(int u = 0; u < n; ++u) {
    if(Indegree[u] == 0)
      Topology.push_back(u);
  }
  
  int ptr = 0;
  while(ptr != int(Topology.size())) {
    int u = Topology[ptr];
    for(int &v : adjacency_list[u]) {
      if(Indegree[v] == 0) {
        // This must be a cycle.
        puts("There's no topological ordering since there's a cycle.");
        exit(0);
      }
      --Indegree[v];
      if(Indegree[v] == 0)
        Topology.push_back(v);
    }
    ++ptr;
  }
  assert(Topology.empty() == false);
  return Topology;
}
