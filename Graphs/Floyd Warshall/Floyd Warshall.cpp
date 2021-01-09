#include <iostream>
using namespace std;

const long long N = 505, INF = ((long long)1 << 61); 


struct floyd_Warshall {

	long long dis[N][N], par[N][N];
	
	void initialize(int &n) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				par[i][j] = i;
				dis[i][j] = (i == j ? 0 : INF);
			}
		}
	}
	
	
	inline void floyed_Warshall(int &n) {
		for(int k = 0; k < n; ++k) {
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < n; ++j) {
					if(dis[i][j] > dis[i][k] + dis[k][j]) {
						dis[i][j] =  dis[i][k] + dis[k][j];
						par[i][j] = i;
					}
				}
			}
		}
	}
	
	inline void print_path(int u, int v) {
		if(u != v)
			print_path(u, par[u][v]);
		printf("%d ", v + 1);
	}
	
	bool negative_Cycle(int n) {
		bool ret = false;
		for(int i = 0; i < n; ++i)
			ret |= (dis[i][i] < 0);
		return ret;
	}
	
	void read() {
		int n, m;
		scanf("%d %d", &n, &m);
		initialize(n);
	
		for(int i = 1; i <= m; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			--u, --v;
			dis[u][v] = dis[v][u] = min(dis[u][v], (long long)w);
		}
	}
};
