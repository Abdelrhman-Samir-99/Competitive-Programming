#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct edge {
  int from, to, weight;
  edge () {}
  edge(int f, int t, int w) : from(f), to(t), weight(w) {}

  // Sorting operator -> we sort the edges based on their weights.
  bool operator < (const edge &rhs) const {
    return weight < rhs.weight;
  }
};

class building_MST {
  
  vector<int> par, Size;
  vector <edge> edges;
  int size;
  
  void initialize(int &n) {
    for(int i = 1; i <= n; ++i) {
      Size[i] = 1;
      par[i] = i;
    }
  }


  public:
    building_MST(int _size) : size(_size) {
      par.resize(size + 1);
      Size.resize(size + 1);
    }
    int find_parent(int x) {
      return par[x] = x == par[x] ? x : find_parent(par[x]);
    }
    
    // using DSU to know if we will merge two forests or not.
  
    bool union_set(int u, int v) {
      u = find_parent(u);
      v = find_parent(v);
      if(u != v) {
        if(Size[u] < Size[v])
          swap(u, v);
        Size[u] += Size[v];
        par[v] = u;
        return true;
      }
      return false;
    }
    
    // O(E log N),
    // since we only need to sort the edges, and DSU query is almost a constant time.
    
    vector <edge> kruskal() {
      vector <edge> MST;
      sort(edges.begin(), edges.end());
      for(edge &e : edges) {
        if(union_set(e.from, e.to))
          MST.push_back(e);
      }
      return MST;
    }
    
    void read() {
      int n, m;
      scanf("%d %d", &n, &m);
      initialize(n);
      for(int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges.push_back(edge(u, v, w));
      }
    }
};
