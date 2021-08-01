#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6 + 6;
vector <int> list[N];

void sieve() {
  for(int i = 1; i < N; ++i)
    for(int j = i; j < N; j += i)
      list[j].push_back(i);
}
