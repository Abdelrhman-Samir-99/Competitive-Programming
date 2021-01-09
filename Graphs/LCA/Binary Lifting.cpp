#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1e5 + 5, M = 20;
struct LCA {
	int par[M][N], depth[N];
	vector <int> g[N];
	
	void dfs(int node, int parent = -1, int d = 0) {
		depth[node] = d;
		for(int &child : g[node]) {
			if(child == parent)
				continue;
			par[0][child] = node;
			dfs(child, node, d + 1);
		}
	}
	
	void build(int &n) {
		memset(par, -1, sizeof par);
		dfs(1);
		for(int i = 1; i < M; ++i) {
			for(int j = 1; j <= n; ++j) {
				int mid = par[i - 1][j];
				if(mid != -1)
					par[i][j] = par[i - 1][mid];
			}
		}
	}
	
	
	int walk(int u, int steps) {
		for(int i = 0; i < M && u != -1; ++i) {
			if((1 << i) & steps)
				u = par[i][u];
		}
		return u;
	}
	
	int lca(int u, int v) {
		if(depth[u] > depth[v])
			u = walk(u, depth[u] - depth[v]);
		if(depth[v] > depth[u])
			v = walk(v, depth[v] - depth[u]);
		if(u == v)
			return u;
	
		for(int i = M - 1; i >= 0; --i) {
			if(par[i][u] != par[i][v]) {
				u = par[i][u];
				v = par[i][v];
			}
		}
		return par[0][u];
	}
	
	int dis(int u, int v) {
		return depth[u] + depth[v] - 2 * depth[lca(u, v)];
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

};
