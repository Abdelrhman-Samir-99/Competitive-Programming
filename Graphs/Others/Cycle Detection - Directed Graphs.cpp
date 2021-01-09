#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5;

vector <int> g[N];
int Time[N], T;


void Cycle_Detection(int node) {
	Time[node] = ++T;
	for(int &child : g[node]) {
		if(Time[child] < Time[node]) {
			puts("Cycle Detected");
			exit(0);
		}
		Cycle_Detection(child);
	}
}


void read() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
	}
}
