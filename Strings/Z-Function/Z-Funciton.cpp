#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
char s[N];


vector <int> Z_Function(int &n) {
	int left, right;
	left = right = 0;
	vector <int> Z(n);
	for(int i = 1; i < n; ++i) {
		if(i <= right)
			Z[i] = min(Z[i - left], right - i + 1);
		while(i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
			++Z[i];
		if(i + Z[i] - 1 > right) {
			right = i + Z[i] - 1;
			left = i;
		}
	}
}

void read() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
}

