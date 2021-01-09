#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e5 + 5;

struct edge {
	int from, to;
	long long weight;
	edge () {}
	edge (int f, int t, long long w) : from(f), to(t), weight(w) {}

	// flipping operator -> will flip the heap from max heap to min heap.
	bool operator < (const edge &rhs) const {
		return weight > rhs.weight;
	}
};

struct dijkstra {

	vector <edge> g[N];
	long long dis[N], par[N];
	
	// O(V + E log V), and it's a greedy approach following *edge relaxation*.
	// V -> The number of Vertices.
	// E -> The number of Edges.
	
	void Dijkstra(int &start) {
		memset(dis, 0x6f, sizeof dis);
		memset(par, -1, sizeof par);
		priority_queue <edge> pq;
		pq.push(edge(-1, start, 0));
		while(!pq.empty()) {
			int u = pq.top().from;
			int v = pq.top().to;
			long long w = pq.top().weight;
			pq.pop();
			if(w >= dis[v])
				continue;
	
			dis[v] = w;
			par[v] = u;
			
			for(edge &e : g[v]) {
				if(w + e.weight < dis[e.to])
					pq.push(edge(v, e.to, w + e.weight));
			}
		}
	}
	
	void print_path(int node) {
		if(~par[node])
			print_path(par[node]);
		printf("%d ", node);
	}
	
	void read() {
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			g[u].push_back(edge(u, v, w));
			g[v].push_back(edge(v, u, w));
		}
	}
};
