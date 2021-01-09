#include <iostream>
#include <math.h>
using namespace std;

const int N = 1e5 + 5, M = 21;

struct ST {
	int sparse_Table[M][N], items[N];
	
	// Space Complexity is (O(N log N)), and Time Compleixty is O(1) for each query.
	
	void build(int &n) {
		for(int i = 0; i < n; ++i)
			sparse_Table[0][i] = items[i];
		int P = log2(n);
		// Operations can overlap, so we can make our sparse table runs in constant time,
		// Like GCD, RMQ.
		for(int p = 1; p <= P; ++p) {
			for(int i = 0; (i + (1 << p)) <= n; ++i) {
				int left = sparse_Table[p - 1][i];
				int right = sparse_Table[p - 1][(i + (1 << (p - 1)))];
				sparse_Table[p][i] = max(left, right);
			}
		}
	}
	
	int query(int l, int r) {
		int p = log2(r - l + 1);
		int x = sparse_Table[p][l];
		int y = sparse_Table[p][r - (1 << p) + 1];
		return max(x, y);
	}
	
	
	void read() {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &items[i]);
		build(n);
	}
};
