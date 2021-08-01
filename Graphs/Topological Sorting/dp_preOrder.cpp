#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;
vector <int> g[N];
int dp[N], n;
bool vis[N];


int add(long long x, int y) {
  x += y;
  if(x >= mod)
    x -= mod;
  return x;
}

void dfs(int node) {
  vis[node] = 1;
  if(node == n) {
    dp[node] = 1;
    return;
  }
  for(int &child : g[node]) {
    if(!vis[node])
      dfs(node);
    dp[node] = add(dp[node], dp[child]);
  }
}

void read() {
  int m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
  }
}
