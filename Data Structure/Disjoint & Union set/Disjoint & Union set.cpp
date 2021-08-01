#include <iostream>
#include <vector>
using namespace std;


template <class T>
class dsu {
  vector<T> par, Size;
  int size;
  
  // Complexity is O(α(N)), where α(N) is the inverse Ackermann function,
  // And we can consider it a linear time Since α(N) grows so slowly.  
  void initialize(int &n) {
    for(int i = 1; i <= n; ++i) {
      Size[i] = 1;
      par[i] = i;
    }
  }

  public:
    dsu(int _size) : size(_size) {
      par.resize(size + 1);
      Size.resize(size + 1);
    }
    int find_parent(int x) {
      // This section is responsible for the path compression.
      return par[x] = x == par[x] ? x : find_parent(par[x]);
    }
    
    void union_set(int u, int v) {
      u = find_parent(u);
      v = find_parent(v);
      // IFF the two nodes are not in the same component we union them together.
      if(u != v) {
        if(Size[u] < Size[v])
          swap(u, v);
        // Adding the two forests (Smallest one to the larger one).
        Size[u] += Size[v];
        par[v] = u;
      }
    }
    
    void read() {
      int edges;
      scanf("%d", &edges);
      initialize(size);
      for(int i = 1; i <= edges; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        union_set(u, v);
      }
    }
};
