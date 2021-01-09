#include <iostream>
using namespace std;


const int N = 1e5 + 5, base = 31, base2 = 35, mod = 1e9 + 7;

struct Rabin_Karp {
	int power_B[N], power_B2[N], Hash[N], second_Hash[N];
	char s[N];
	
	int mul(long long x, int y) {
		return x * y % mod;
	}
	
	int add(long long x, int y) {
		x += y;
		while(x - mod >= 0)
			x -= mod;
		return x;
	}
	
	int sub(int x, int y) {
		x -= y;
		while(x + mod <= 0)
			x += mod;
		return x;
	}
	
	int get_Hash(int l, int r) {
		if(!l)
			return Hash[r];
		return sub(Hash[r], mul(Hash[l - 1], power_B[r - l + 1]));
	}
	
	int get_Second_Hash(int l, int r) {
		if(!l)
			return second_Hash[r];
		return sub(second_Hash[r], mul(second_Hash[l - 1], power_B2[r - l + 1]));
	}
	
	void solve(int &n) {
		power_B[0] = 1;
		for(int i = 1; i <= n; ++i)
			power_B[i] = mul(power_B[i - 1], base);
		int current = 0;
		int current2 = 0;
		for(int i = 0; i < n; ++i) {
			current = add(s[i] - 'a', mul(current, base));
			current2 = add(s[i] - 'a', mul(current2, base2));
			Hash[i] = current;
			second_Hash[i] = current2;
		}
	}
	
	void read() {
		int n;
		scanf("%d", &n);
		scanf("%s", s);
	}
};
