#include <iostream>
#include <algorithm>
#include <assert.h>
#include <vector>
using namespace std;



void dfs(int u, vector <vector<int>> &adjacency_list, vector <bool> &visited, vector <int> &start, vector <int> &Topology, int &T) {
	if(visited[u] == true) {
		if(T >= start[u]) {
			puts("There's a cycle, hence there's no topological sorting for this graph.");
			exit(0);
		}
		return;
	}
	visited[u] = true;
	start[u] = T++;
	for(int &v : adjacency_list[u])
		dfs(v, adjacency_list, visited, start, Topology, T);
	Topology.push_back(u);
}

vector <int> Topological_order(vector <vector<int>> &adjacency_list) {
	int n = adjacency_list.size();
	vector <bool> visited(n + 1, false);
	vector <int> start(n + 1);
	vector <int> Topology;
	int T = 0;
	for(int u = 0; u < n; ++u) {
		if(visited[u])
			continue;
		dfs(u, adjacency_list, visited, start, Topology, T);
	}
	reverse(Topology.begin(), Topology.end());
	return Topology;
}
