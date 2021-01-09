#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5;

int longest, current_node;
vector <int> g[N];

void dfs(int node, int parent = -1, int depth = 0) {
	if(depth >= longest) {
		longest = depth;
		current_node = node;
	}
	for(int &child : g[node]) {
		if(child == parent)
			continue;
		dfs(child, node, depth + 1);
	}
}

pair <int, int> get_Diameter() {
	pair <int, int> two_nodes;
	dfs(1);
	two_nodes.first = current_node;
	longest = 0;
	dfs(current_node);
	two_nodes.second = current_node;
	return two_nodes;
}

void read() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
}
