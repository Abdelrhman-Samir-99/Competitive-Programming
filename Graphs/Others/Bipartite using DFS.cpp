#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class bipartite {

  private:
    vector <vector<int>> g; // my graph.
    vector <bool> visited;
    vector <int> color; // coloring each node either -1, 0, 1 -> -1 for unvisited nodes.
    int number_of_nodes;

    bool dfs(int node, int node_color) {
      // Doing normal DFS for each connected component.
      // IFF there's a cycle then when we back to same name we must back with the same color.
      // otherwise this is not a bipartite graph.
      if(visited[node]) {
        if(color[node] != node_color)
          return false;
      }
      bool ret = true;
      visited[node] = true;
      color[node] = node_color;
      for(int &v : g[node]) {
        ret &= dfs(v, node_color ^ 1); // flipping the bit from 1 to 0 via-versa.
      }
      return ret;
    }

  public:

    bipartite(vector <vector<int>> adjacency_List) { // The constructor.
      g = adjacency_List;
      number_of_nodes = adjacency_List.size();
      visited.resize(number_of_nodes + 1, 0);
      color.resize(number_of_nodes + 1, 0);
    }

    bool check() {
      bool is_Bipartite = true;
      // the check function.
      memset(color, -1, sizeof color); // Filling the whole array with -1.
      for(int u = 0; u < number_of_nodes; ++u) {
        if(visited[u])
          continue;
        is_Bipartite &= dfs(u, 0);
      }
      return is_Bipartite;
    }
};
