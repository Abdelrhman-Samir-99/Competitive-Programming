#include <iostream>
#include <vector>
using namespace std;


void count_Sort(vector <int> &Items, int max_Item) {
  vector <int> count(max_Item + 1, 0);
  for(int &current_Item : Items)
    ++count[current_Item];
  int ptr = 0;
  for(int i = 0; i < int(Items.size()); ++i) {
    while(count[i] != 0) {
      Items[ptr++] = i;
      --count[i];
    }
  }
}
