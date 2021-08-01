#include <iostream>
#include <vector>
using namespace std;


template <class T>
class fenwick {
	vector<T> tree;
	int size;

	public:
		// Fenwich tree works in O(log n) per query || update.
		// One based and answer query of type [1, node].
		fenwick(int _size) : size(_size) {
			tree.resize(size);
		} 
		void update(int node, T v) {
			while(node < size) {
				tree[node] += v;
				node += (node & -node); // adding the most significant bit.
			}
		}
	
		T get(int node) {
			long long ret = 0;
			while(node > 0) {
				ret += tree[node];
				node -= (node & -node); // Subtracting the most significant bit.
			}
			return ret;
		}
	
		T get_range(int l, int r) {
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
