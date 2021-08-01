#include <iostream>
#include <vector>
using namespace std;

vector <int> get_Divisors(int n) {
  vector <int> Divisors;
  for(int i = 1; i * i <= n; ++i) {
    if(n % i == 0) {
      Divisors.push_back(n / i);
      if(i * i != n)
        Divisors.push_back(i);
    }
  }
  return Divisors;
}
