#include <iostream>
using namespace std;

int fast_power(long long base, int power) {
	if(power == 0)
		return 1;
	long long temp = fast_power(base, power / 2);
	long long ret = temp * temp * (power % 2 == 1 ? base : 1);
	return ret;
}
