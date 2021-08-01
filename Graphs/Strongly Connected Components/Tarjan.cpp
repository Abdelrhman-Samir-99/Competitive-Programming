#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class SCC {
  vector <int> lowest_link, time, SCC_ID;
  vector <bool> visited, in_stk;
  vector <vector<int>> _SCC;
  vector <vector<int>> g;
  stack <int> stk;
  
  int size, cnt;

  public:
    SCC(int _size) : size(_size) {
      lowest_link.resize(size + 1, 1e9);
      visited.resize(size + 1);
      SCC_ID.resize(size + 1);
      in_stk.resize(size + 1);
      time.resize(size + 1);
      g.resize(size + 1);
      cnt = 0;
    }

    void dfs(int node) {
      if(visited[node]) {


      }
      time[node] = ++cnt;
      visited[node] = true;
      in_stk[node] = true;
      stk.push(node);
      for(int &child : g[node]) {
        if(!visited[child]) {
          dfs(child);
          lowest_link[node] = min(lowest_link[node], lowest_link[child]);
        }
        else if(in_stk[child]) {
          lowest_link[node] = min(lowest_link[node], lowest_link[child]);
        }
      }
      
      in_stk[node] = false;
      if(lowest_link[node] == time[node]) {
        int top = -1;
        _SCC.push_back(vector <int>());
        while(top != node) {
          top = stk.top();
          stk.pop();
          _SCC.back().push_back(top);
          SCC_ID[top] = int(_SCC.size()) - 1;
          in_stk[top] = 0;
        }
      }
    }

    pair <vector<vector<int>>, vector <int>> get_SCC() {
      for(int i = 1; i <= size; ++i)
        dfs(i);
      return make_pair(_SCC, SCC_ID);
    }

    vector <vector<int>> build_CG() {
      vector <vector<int>> component_graph(int(_SCC.size() + 1), vector <int> ());
      for(int u = 1; u <= size; ++u) {
        for(int v = 1; v <= size; ++v) {
            if(SCC_ID[u] != SCC_ID[v]) {
              component_graph[SCC_ID[u]].push_back(SCC_ID[v]);
            }
        }
      }
      return component_graph;
    }
};
