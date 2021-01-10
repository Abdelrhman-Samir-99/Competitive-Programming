#include <iostream>
using namespace std;
using ll = long long;

const int N = 1e3 + 5, mod = 1e9 + 7;

struct PT {

	int C[N][N];
	
	int add(long long x, int y) {
		x += y;
		if(x >= mod)
			x -= mod;
		return x;
	}
	
	void pascal_Triangle(int &n) {
		for(int i = 0; i <= n; ++i) {
			for(int j = 0; j <= i; ++j) {
				if(j == 0 || j == i)
					C[i][j] = 1;
				else
					C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
			}
		}
	}
};
