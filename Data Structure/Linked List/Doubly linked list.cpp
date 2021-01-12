#include <iostream>
#include <assert.h>
using namespace std;


class List {

	private:
		struct node {
			int data;
			node* next;
			node* prev;
		};

		node* head;
		node* tail;
		node* current;

	public:
		int Lenght;
		List() {
			current = NULL;
			head = NULL;
			tail = NULL;
			Lenght = 0;
		}
		
		void add(int Data) {
			// the new node.
			node* new_node = new node;
			new_node-> data = Data;
			new_node-> prev = NULL;
			new_node-> next = NULL;

			// means that the list is empty.
			if(head == NULL) {
				head = new_node;
				tail = new_node;
			}
			else {
				// otherwise we make a new tail.
				tail-> next = new_node;
				new_node-> prev = tail;
				tail = new_node;
			}
			++Lenght;
		}

		void insert(int Data, int index) {
			current = head;
			int current_pos = 0;
			while(current != NULL && current_pos != index) {
				++current_pos;
				current = current-> next;
			}

			// our new node.
			node* new_node = new node;
			new_node-> data = Data;
			new_node-> prev = NULL;
			new_node-> next = NULL;

			if(Lenght == 0) {
				// This means that the list is empty so we need to maintain the head and tail.
				head = new_node;
				tail = new_node;
			}
			else if(current == NULL) {
				// link the tail to a new node amd keep track of the tail.
				new_node-> prev = tail;
				tail-> next = new_node;
				tail = new_node;
			}
			else {
				// Intermediate position.
				new_node-> prev = current;
				new_node-> next = current-> next;
				(current-> next)-> prev = new_node;
				current-> next = new_node;
			}
			++Lenght;
		}
		
		void erase(int Data, int count = 1) {
			// if the count is a negative number then makes no sense.
			assert(count >= 0);
			current = head;
			
			while(current != NULL && count > 0) {
				if(current-> data == Data) {
					// This node will be deleted.
					node* temp = current;
					--count;
					--Lenght;
					if(current == head) {
						// only a single node
						if(Lenght == 0) {
							delete temp;
							head = NULL;
							tail = NULL;
							break;
						}
						
						// If this is the head node then we make a new head node.
						current = current-> next;
						head = current;
						head-> prev = NULL;
					}
					else if(current == tail) {
						// we just remove the tail and modify the previous link and make a new tail.
						tail = current-> prev;
						(current-> prev)-> next = NULL;
						delete temp;
						break;
					}
					else {
						// Else: we delete this node and link the previous node's-> next with the current node
						// and current-> prev with the previous node.
						current = current-> next;
						(temp-> prev)-> next = current;
						current-> prev = temp-> prev;
					}
					delete temp;
				}
				else {
					current = current-> next;
				}
			}

			current = head;
			tail = head;
			while(current != NULL) {
				if(current-> next == NULL)
					tail = current;
				current = current-> next;
			}
		}
		
		void print() {
			current = head;
			while(current != NULL) {
				printf("%d ", current-> data);
				current = current-> next;
			}
			puts("");
		}

		void clear() {
			current = head;
			while(current != NULL) {
				node* temp = current;
				current = current-> next;
				delete temp;
			}
		}
};
