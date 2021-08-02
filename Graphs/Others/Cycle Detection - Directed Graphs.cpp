#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int N = 1e5 + 5;

vector <int> g[N];
vector <bool> in_stack, visited;


// Using a boolean vector to keep track of the nodes in the current stack.
// if we visited a node in the stack then there must be a cycle.

bool Cycle_Detection(int node) {
  if(visited[node]) {
    if(in_stack[node])
      return true;
    return false;
  }

  visited[node] = true;
  in_stack[node] = true;
  bool ret = false;
  for(int &child : g[node]) {
    ret |= Cycle_Detection(child);
  }
  in_stack[node] = false;
  return ret;
}


void read() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
  }
  in_stack.resize(n + 1);
  visited.resize(n + 1);
}

