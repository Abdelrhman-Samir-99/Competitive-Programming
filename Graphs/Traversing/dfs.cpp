#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
vector <int> g[N];
bool vis[N];

void dfs(int node, int parent = -1) {
	if(vis[node])
		return;
	vis[node] = true;
	for(int &child : g[node]) {
		if(child == parent)
			continue;
		dfs(child, node);
	}
}
