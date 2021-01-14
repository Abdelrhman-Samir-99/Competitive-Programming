#include <iostream>
using namespace std;

const int N = 1e3 + 5;

struct PS {

	bool dp[N][N];
	char s[N];
	
	void palindrome_Substrings(int &n) {
		// Every Substring of length 1 is palindrome.
		for(int i = 0; i < n; ++i)
			dp[i][i] = true;
	
		// We check the strings of length 2.
		for(int i = 1; i < n; ++i)
			if(s[i] == s[i - 1])
				dp[i - 1][i] = true;
		// now starting from length 3 and so on we only need to check the first and last char,
		// and the substring of length (r - l - 1) is already known.
		for(int i = 3; i <= n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(dp[j + 1][i + j - 2] && s[j] == s[j + i - 1])
					dp[j][j + i - 1] = true;
		}
	}
	
	
	void read() {
		int n;
		scanf("%d", &n);
		scanf("%s", s);
	}
};
