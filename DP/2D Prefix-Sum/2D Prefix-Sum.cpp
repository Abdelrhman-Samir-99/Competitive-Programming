#include <iostream>
using namespace std;

const int N = 1e3 + 3;

struct prefix_Sum {
	long long dp[N][N];
	
	long long query(int l, int r) {
		// 0 Based not 1 Based!!!!!!!!!!!!!!!!
		--l, --r;
		long long ret = dp[r][r];
		if(l > 0) {
			ret -= dp[r][l - 1];
			ret -= dp[l - 1][r];
			ret += dp[l - 1][l - 1];
		}
		return ret;
	}
	
	void _2D_Prefix_Sum(int &n, int &m) {
		for(int i = 0; i < n; ++i)
			for(int j = 1; j < m; ++j)
				dp[i][j] += dp[i][j - 1];
	
		for(int i = 0; i < m; ++i)
			for(int j = 1; j < n; ++j)
				dp[i][j] += dp[i - 1][j];
	}
	
	
	void read() {
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				scanf("%lld", &dp[i][j]);
	}
};
