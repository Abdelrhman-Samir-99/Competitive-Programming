#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5;

class subTree_Sum {

  int Start[N * 2], End[N * 2], items[N], T;
  long long tree[N];
  vector <int> g[N];
  bool vis[N];
  
  void update(int node, int v) {
    while(node < N) {
      tree[node] += v;
      node += (node & -node);
    }
  }
  
  long long get(int node) {
    long long ret = 0;
    while(node > 0) {
      ret += tree[node];
      node -= (node & -node);
    }
    return ret;
  }
  
  
  long long sub_Tree_Sum(int node) {
    return get(End[node]) - get(Start[node] - 1);
  }

  inline void dfs(int node, int parent = -1) {
    Start[node] = ++T;
    if(vis[node])
      return;
    vis[node] = true;
    for(int &x : g[node]) {
      if(x == parent)
        continue;
      dfs(x, node);
    }
    End[node] = ++T;
  }
  
  void solve(int &n) {
    dfs(1);
    for(int i = 1; i <= n; ++i)
      update(Start[i], items[i]);
    int q;
    scanf("%d", &q);
    while(q--) {
      int op;
      scanf("%d", &op);
      if(op == 1) {
        int u, v;
        scanf("%d %d", &u, &v);
        update(Start[u], v - items[u]);
        items[u] = v;
      }
      else {
        int u;
        scanf("%d", &u);
        printf("%lld\n", sub_Tree_Sum(u));
      }
    }
  }
  
  void read() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
      scanf("%d", &items[i]);
    for(int i = 1; i <= m; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }

};
