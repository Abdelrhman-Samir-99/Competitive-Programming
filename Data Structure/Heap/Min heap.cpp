#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

class min_Heap {
	private:
		vector <int> heap;
		
		int parent(int index) { return (index - 1) / 2;}
		int left_Child(int index) { return index * 2 + 1;}
		int right_Child(int index) { return index * 2 + 2;}
		
		bool has_Left(int index) { return int(heap.size()) > left_Child(index);}
		bool has_Right(int index) { return int(heap.size()) > right_Child(index);}
		bool has_Parent(int index) { return index != 0;}

		int get_Left(int index) { return heap[left_Child(index)];}
		int get_Right(int index) { return heap[right_Child(index)];}
		int get_Parent(int index) { return heap[parent(index)];}
		
		void build(vector <int> &Items) {
			heap = Items;
			int total = heap.size();
			for(int i = total / 2 - 1; i >= 0; --i)
				shiftDown(i);
		}
		
		void shiftUp(int index) {
			while(has_Parent(index) && heap[index] < get_Parent(index)) {
				swap(heap[index], heap[parent(index)]);
				index = parent(index);
			}
		}
		
		void shiftDown(int index) {
			// if we don't have a left child, then for sure we don't have a right one (complete binary tree).
			while(has_Left(index) == true) {
				int max_value = get_Left(index);
				if(has_Right(index) == true) {
					max_value = min(max_value, get_Right(index));
				}
				if(heap[index] <= max_value)
					break;
				if(has_Right(index) == true) {
					if(get_Left(index) < get_Right(index)) {
						swap(heap[index], heap[left_Child(index)]);
						index = left_Child(index);
					}
					else {
						swap(heap[index], heap[right_Child(index)]);
						index = right_Child(index);
					}
				}
				else {
					swap(heap[index], heap[left_Child(index)]);
					index = left_Child(index);
				}
			}
		}

	public:
		min_Heap(vector <int> &Items) {
			build(Items);
		}

		bool empty() { return int(heap.size()) == 0;}
		int size() { return int(heap.size());}

		int peek() {
			assert(this-> empty() == false);
			return heap[0];
		}
		
		int pop() {
			assert(this-> empty() == false);
			int ret = heap[0];
			if(this-> size() == 1) {
				heap.pop_back();
				return ret;
			}
			heap[0] = heap.back();
			heap.pop_back();
			shiftDown(0);
			return ret;
		}
		void push(int value) {
			heap.push_back(value);
			shiftUp(this-> size() - 1);
		}
};
