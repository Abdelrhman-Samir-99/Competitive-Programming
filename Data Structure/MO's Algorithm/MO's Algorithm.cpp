#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

// MO's algorithm works in (O(N + Q) * Sqrt(N)) which is really high and may TLE,
// with higher constraints.

int items[N], answer[N], n, q;
int block_Size, current_Left, current_Right, current_Answer;

struct query {
	int l, r, index;
	// Sorting operator -> Sort the queries by the block ID,
	// IFF two blocks have the same ID then we process the one with the small right border.
	
	bool operator < (const query &rhs) const {
		if(l / block_Size != rhs.l / block_Size)
			return l < rhs.l;
		return r < rhs.r;
	}
} queries[N]; 


void add(int index) {

}

void remove(int index) {

}

void solve() {
	block_Size = sqrt(n);
	current_Right = -1;
	sort(queries, queries + n);
	for(int i = 0; i < q; ++i) {
		query &current = queries[i];
		// Worst case is that we move (Sqrt(N)) for query.
		while(current_Left < current.l) remove(current_Left++);
		while(current_Left > current.l) add(--current_Left);
		while(current_Right < current.r) add(++current_Right);
		while(current_Right < current.r) remove(current_Right--);
		answer[current.index] = current_Answer;
	}
}



void read() {
	// THIS IS 0-BASED NOT 1-BASED, Please Take care!.
	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; ++i)
		scanf("%d", &items[i]);
	for(int i = 0; i < q; ++i) {
		query &current = queries[i];
		scanf("%d %d", &current.l, &current.r);
		--current.l;
		--current.r;
		current.index = i;
	}
}
