#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> LIS(vecotr <int> &items) {
	int n = items.size();
	vector <int> dp;
	vector <int> :: iterator it;
	for(int i = 0; i < n; ++i) {
		it = lower_bound(dp.begin(), dp.end(), items[i]);
		if(it == dp.end())
			dp.push_back(items[i]);
		else
			*it = items[i];
	}
	return LIS;
}
