#include <iostream>
using namespace std;

const int N = 1e5 + 5;

struct BIT {
	long long tree[N];
	
	// Fenwich tree works in O(log n) per query || update.
	// One based and answer query of type [1, node].
	void update(int node, int v) {
		while(node < N) {
			tree[node] += v;
			node += (node & -node); // adding the most significant bit.
		}
	}
	
	long long get(int node) {
		long long ret = 0;
		while(node > 0) {
			ret += tree[node];
			node -= (node & -node); // Subtracting the most significant bit.
		}
		return ret;
	}
	
	long long get_range(int l, int r) {
		return get(r) - get(l - 1);
	}
	
	void range_update(int l, int r, long long v) {
		// Note that we can only use either (point update & range query)
		// or (range update, point query).
		update(l, (r - l + 1) * v);
		update(r + 1, (r - l + 1) * -v);
	}
	
	
	void read() {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			int x;
			scanf("%d", &x);
			update(i, x);
		}
	}
};
