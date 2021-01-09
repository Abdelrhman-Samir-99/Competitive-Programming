#include <iostream>
#include <vector>
#include <map>
using namespace std;


const int N = 2e5 + 5;
struct LIS {
	int tree[N * 4], items[N];
	
	void update(int node, int v, int x = 0, int lx = 0, int rx = N) {
		if(rx - lx == 1) {
			tree[x] = v;
			return;
		}
		int mid = (lx + rx) / 2;
		if(node < mid)
			update(node, v, 2 * x + 1, lx, mid);
		else
			update(node, v, 2 * x + 2, mid, rx);
		tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
	}
	
	int get(int l, int r, int x = 0, int lx = 0, int rx = N) {
		if(lx >= l && rx <= r)
			return tree[x];
		if(lx >= r || l >= rx)
			return -1e9;
		int mid = (lx + rx) / 2;
		int ret1 = get(l, r, 2 * x + 1, lx, mid);
		int ret2 = get(l, r, 2 * x + 2, mid, rx);
		return max(ret1, ret2);
	}
	
	
	void read() {
		int n;
		scanf("%d", &n);
		map <int, int> Hash;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &items[i]);
			Hash[items[i]];
		}
		int index = 1;
		map <int, int> :: iterator it = Hash.begin();
		while(it != Hash.end()) {
			it -> second = index++;
			++it;
		}
	}
	
	void solve(map <int, int> Hash, int &n) {
		for(int i = 1; i <= n; ++i) {
			int current_max = get(0, Hash[items[i]]);
			update(Hash[items[i]], current_max + 1);
		}
	}
};
