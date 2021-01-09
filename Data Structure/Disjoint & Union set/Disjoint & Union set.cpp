#include <iostream>
using namespace std;


const int N = 1e5 + 5;

struct dsu {
	int par[N], Size[N];
	
	// Complexity is O(α(N)), where α(N) is the inverse Ackermann function,
	// And we can consider it a linear time Since α(N) grows so slowly.  
	void initialize(int &n) {
		for(int i = 1; i <= n; ++i) {
			Size[i] = 1;
			par[i] = i;
		}
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
		int n, m;
		scanf("%d %d", &n, &m);
		initialize(n);
		for(int i = 1; i <= m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			union_set(u, v);
		}
	}
};
