#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6 + 6;
vector <int> list[N];
bool is_coprime[N];

void sieve() {
  is_coprime[1] = true;
  for(int i = 2; i < N; ++i) {
    if(is_coprime[i])
    for(int j = i; j < N; j += i)
      list[j].push_back(i);
  }
}
