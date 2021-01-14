#include <iostream>
#include <vector>
using namespace std;


int sequential_Search(vector <int> &Items, int value) {
	int found = -1;
	for(int i = 0; i < int(Items.size()); ++i) {
		if(Items[i] == value) {
			found = i;
			break;
		}
	}
	return found;
}
