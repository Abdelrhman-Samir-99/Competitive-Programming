#include <iostream>
#include <vector>
using namespace std;


bool check(int mid) {
	// do some stuff here

}

int binary_Search(vector <int> &Items, int low, int high) {
	int found = -1;
	while(low <= high) {
		int mid = low + (high - low) / 2; // or (low + high) / 2 but this one just to pervent overflows.
		if(check(mid) == true) {
			high = mid - 1;
			found = mid;
		}
		else
			low = mid + 1;
	}
	return found;
}
