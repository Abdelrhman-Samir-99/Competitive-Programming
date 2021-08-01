#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e5 + 5;
int dis[N], par[N];
vector <int> g[N];



void bfs(int start) {
  memset(par, -1, sizeof par);
  memset(dis, -1, sizeof dis);

  queue <int> q;
  q.push(start);
  dis[start] = 0;

  while(!q.empty()) {
    int node = q.front();
    q.pop();
    for(int &child : g[node]) {
      if(dis[child] == -1) {
        dis[child] = dis[node] + 1;
        par[child] = node;
        q.push(child);
      }
    }
  }
}

void print_path(int node) {
  if(~par[node])
    print_path(par[node]);

  printf("%d ", par[node]);
}


void read() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
}

