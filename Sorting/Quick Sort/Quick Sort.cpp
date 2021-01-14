#include <iostream>
using namespace std;


const int N = 1e5 + 5;

int Items[N];

void swap(int *x, int *y) {
	// Using this function to sawp by reference.
	int t = *x;
	*x = *y;
	*y = t;
}

int partition(int low, int high) {
	int pivot = Items[high];
	int i = low - 1;
	for(int j = low; j <= high - 1; ++j) {
		if(Items[j] <= pivot) {
			++i;
			swap(&Items[i], &Items[j]);
		}
	}
	++i;
	swap(&Items[i], &Items[high]);
	return i;
}

void quick_Sort(int low, int high) {
	if(low < high) {
		int pos = partition(low, high);
		quick_Sort(low, pos - 1);
		quick_Sort(pos + 1, high);
	}
}


