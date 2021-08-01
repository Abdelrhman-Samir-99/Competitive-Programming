#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


template <class T>
class Sparse_Table {

  vector<vector<T>> sparse_Table;
  vector<T> items;
  int size, bits;
  
  // Space Complexity is (O(N log N)), and Time Compleixty is O(1) for each query.
  public:
    Sparse_Table(int _size, int _bits) : size(_size), bits(_bits) {
      items.resize(size);
      sparse_Table.resize(bits, vector<T> (size, 0));
    }
    
    void build(int &n) {
      for(int i = 0; i < n; ++i)
        sparse_Table[0][i] = items[i];
      int P = log2(n);
      // Operations can overlap, so we can make our sparse table runs in constant time,
      // Like GCD, RMQ.
      for(int p = 1; p <= P; ++p) {
        for(int i = 0; (i + (1 << p)) <= n; ++i) {
          int left = sparse_Table[p - 1][i];
          int right = sparse_Table[p - 1][(i + (1 << (p - 1)))];
          sparse_Table[p][i] = max(left, right);
        }
      }
    }
    
    int query(int l, int r) {
      int p = log2(r - l + 1);
      int x = sparse_Table[p][l];
      int y = sparse_Table[p][r - (1 << p) + 1];
      return max(x, y);
    }
    
    
    void read() {
      for(int i = 0; i < size; ++i)
        scanf("%d", &items[i]);
      this-> build(size);
    }
};
