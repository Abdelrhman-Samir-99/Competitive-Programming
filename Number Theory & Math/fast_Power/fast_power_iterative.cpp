#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

int fast_power(long long base, int power) {
	long long ret = 1;
	while(power > 0) {
		if(power & 1)
			ret = ret * base % mod;
		power >>= 1;
		base = base * base % mod;
	}
	return ret;
}
