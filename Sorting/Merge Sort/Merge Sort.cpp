#include <iostream>
using namespace std;


const int N = 1e5 + 5;

int Items[N];


inline void merge(int low, int mid, int high) {

  // the purpose of the merging function is to make a sorted array from two smaller sorted arrays.
  // in O(A + B) where A -> length of the first array, B -> length of the second array.
  
  int len1 = mid - low + 1, len2 = high - mid;
  int Left[len1], Right[len2];
  int i, j;

  for(i = 0; i < len1; ++i)
    Left[i] = a[i + low];

  for(i = 0; i < len2; ++i)
    Right[i] = a[i + mid + 1];

  int ptr = low;
  i = j = 0;

  // this loop will just iterate until we finish one array.
  while(i < len1 && j < len2) {
    if(Left[i] <= Right[j])
      Items[ptr] = Left[i++];
    else
      Items[ptr] = Right[j++];
    ++ptr;
  }
  
  // this will happen if j = len2
  while(i < len1) {
    Items[ptr] = Left[i++];
    ++ptr;
  }

  // this will happen if i = len1
  // only one of those loops should work but NEVER both i believe.
  while(j < len2) {
    Items[ptr] = Right[j++];
    ++ptr;
  }
}
 

inline void merge_sort(int low, int high) {
  // The purpose of the this function is to partition the array.
  // (I THINK) not quite sure but it will run (1, 2, 4, 8, 16, 32, ...),
  // always as a power of 2, so i think the Big O for it should be O(2 ^ (Ceil(log2 N))).
  int mid = (low + high) / 2;
  if(low < high) {
    merge_sort(low, mid);
    merge_sort(mid + 1, high);
    merge(low, mid, high);
  }
}
