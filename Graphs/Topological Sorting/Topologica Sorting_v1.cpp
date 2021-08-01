#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Topology {
  vector <vector<int>> g;
  vector <int>  topology;
  vector <bool> processed;
  int size;
  
  void dfs(int node) {
    if(processed[node])
      return;
    processed[node] = true;
    for(int &child : g[node])
      dfs(child);
    topology.push_back(node);
  }
  
  
  public:
    Topology(vector<vector<int>> &graph) {
      g = graph;
      size = g.size();
      processed.resize(size + 1);
    }
    vector <int> build_topology(int &n) {
      for(int i = 1; i <= n; ++i) {
        if(!processed[i])
          dfs(i);
      }
      reverse(topology.begin(), topology.end());
    }
    
    
    void read() {
      int n, m;
      scanf("%d %d", &n, &m);
      for(int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
      }
    }
};
