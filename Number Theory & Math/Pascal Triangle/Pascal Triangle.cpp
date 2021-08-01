#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int N = 1e3 + 5, mod = 1e9 + 7;

class PT {

  vector <vector<int>> C;
  const int mod = 1e9 + 7, size;
  int add(long long x, int y) {
    x += y;
    if(x >= mod)
      x -= mod;
    return x;
  }

  public:
    PT(int _size) : size(_size) {
      C.resize(size, vector <int> (size, 0));
    }
    
    void pascal_Triangle(int &n) {
      for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= i; ++j) {
          if(j == 0 || j == i)
            C[i][j] = 1;
          else
            C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
        }
      }
    }
};
