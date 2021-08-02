#include <iostream>
#include <vector>
using namespace std;

struct edge {
  long long from, to, weight;
};
  
template <class T>
class bellman {

  // Bellman is simple algorithm used to detect negtative cycle and find SSSP in O(|V| * |E|).
  // The idea is the longest path in the SSSP tree may be of length n - 1, so we don't need more than n - 1 iterations.
  // Each iteration we just relax the edges.
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
