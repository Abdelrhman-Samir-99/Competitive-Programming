#include <iostream>
#include <vector>
using namespace std;

struct edge {
  long long from, to, weight;
};
  
template <class T>
class bellman {
  
  const T size, _edges, INF;
  vector <edge> edges;
  vector <T> SSSP;

  public:
    bellman(T _size, T __edges, T _INF) : size(_size), INF(_INF), _edges(__edges) {
      SSSP.resize(size, INF);
    }

    void read() {
      for(int i = 1; i <= _edges; ++i) {
        T u, v, w;
        cin >> u >> v >> w;
        edges.push_back(edge(u, v, w));
      }
    }

    vector <vector<T>> do_bellman(int src) {
      SSSP[src] = 0;
      for(int i = 1; i < size; ++i) {
        for(edge &current_edge : edges) {
          T from = current_edge.from;
          T to = current_edge.to;
          T cost = current_edge.weight;
          if(SSSP[from] + cost < SSSP[to]) {
            SSSP[to] = from + cost;
          }
        }
      }
      return SSSP;
    }

    bool negative_cycle() {
      for(edge &current_edge : edges) {
        T from = current_edge.from;
        T to = current_edge.to;
        T cost = current_edge.weight;
        if(SSSP[from] + cost < SSSP[to]) {
          return true;
        }
      }
      return false;
    }
};
