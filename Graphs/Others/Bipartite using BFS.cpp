#include <iostream>
#include <cstring>
#include <vector>
#include <queue>  
using namespace std;

class bipartite {

  private:
    vector <vector<int>> g;
    vector <bool> visited;
    vector <int> color;
    int number_of_nodes;
    
    bool BFS(int source) {
      queue <pair<int, int>> bfs;
      bool is_Bipartite = true;
      bfs.push(make_pair(source, 0));

      // Just doing normal BFS, and checking if there's a cycle then we must finish it as we started.
      // Also can be used to see if there's a cycle of odd length.
      while(!bfs.empty()) {
        int top = bfs.front().first;
        int node_color = bfs.front().second;
        bfs.pop();
        if(visited[top] == true) {
          if(color[top] != node_color)
            is_Bipartite = false;
          return is_Bipartite;
        }
        visited[top] = true;
        color[top] = node_color;
        node_color ^= 1;
        for(int &v : g[top]) {
          if(visited[v] == true) {
            if(color[v] != node_color)
              is_Bipartite = false;
            return is_Bipartite;
          }
          bfs.push(make_pair(v, node_color));
        }
      }
      return is_Bipartite;
    }
    
  public:
    bipartite(vector <vector<int>> adjacency_List) {
      g = adjacency_List;
      number_of_nodes = adjacency_List.size();
      visited.resize(number_of_nodes + 1, 0);
      color.resize(number_of_nodes + 1, 0);
    }

    bool check() {
      bool is_Bipartite = true;
      for(int u = 0; u < number_of_nodes; ++u) {
        if(visited[u])
          continue;
        is_Bipartite &= BFS(u);
      }
      return is_Bipartite;
    }
};
