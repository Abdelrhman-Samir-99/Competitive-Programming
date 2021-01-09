#include <iostream>
using namespace std;

const int N = 1e5 + 5;

struct ST {
	long long tree[N * 4], lazy[N * 4], items[N];
	
	// Building function takes O(N), and initialize our segment tree.
	// O(log n) for each query || update.
	// This is range sum segment tree.
	void build(int x = 0, int lx = 0, int rx = N) {
		if(rx - lx == 1) {
			tree[x] = items[lx];
			return;
		}
		int mid = (lx + rx) / 2;
		build(2 * x + 1, lx, mid);
		build(2 * x + 2, mid, rx);
		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}
	
	void propagate(int x = 0, int lx = 0, int rx = N) {
		// Updating the node and propagating the value when it's needed to both children.
		// IFF we are on a leaf node then there's nothing to propagate.
		tree[x] += lazy[x];
		if(rx - lx == 1) {
			lazy[x] = 0;
			return;
		}
		lazy[2 * x + 1] += lazy[x];
		lazy[2 * x + 2] += lazy[x];
		lazy[x] = 0;
	}
	
	inline void node_update(int node, int v, int x = 0, int lx = 0, int rx = N) {
		// This function is responsible for updating a single node.
		propagate(x, lx, rx);
		if(rx - lx == 1) {
			tree[x] = v;
			return;
		}
		int mid = (lx + rx) / 2;
		if(node < mid)
			node_update(node, v, 2 * x + 1, lx, mid);
		else
			node_update(node, v, 2 * x + 2, mid, rx);
		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}
	
	inline long long get_node(int node, int x = 0, int lx = 0, int rx = N) {
		// This function responsible for getting the value of a single item,
		// Single item may represent anything like (prefix sum [0, node[.
		propagate(x, lx, rx);
		if(rx - lx == 1)
			return tree[x];
		int mid = (lx + rx) / 2;
		long long ret;
		if(node < mid)
			ret = get_node(node, 2 * x + 1, lx, mid);
		else
			ret = get_node(node, 2 * x + 2, mid, rx);
		return ret;
	}
	
	
	inline long long get_range(int l, int r, int x = 0, int lx = 0, int rx = N) {
		// This function is responsible for range query, getting the value of [l, r[.
		propagate(x, lx, rx);
		if(lx >= l && rx <= r)
			return tree[x];
		if(l >= rx || lx >= r)
			return 0;
		int mid = (lx + rx) / 2;
		long long ret1 = get_range(l, r, 2 * x + 1, lx, mid);
		long long ret2 = get_range(l, r, 2 * x + 2, mid, rx);
		return ret1 + ret2;
	}
	
	inline void update_range(int l, int r, long long v, int x = 0, int lx = 0, int rx = N) {
		propagate(x, lx, rx);
		if(lx >= l && rx <= r) {
			lazy[x] += v;
			return;
		}
		if(l >= rx || lx >= r)
			return;
		int mid = (lx + rx) / 2;
		update_range(l, r, 2 * x + 1, v, lx, mid);
		update_range(l, r, 2 * x + 2, v, mid, rx);
	}
	void read() {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			scanf("%lld", &items[i]);
	}
};

