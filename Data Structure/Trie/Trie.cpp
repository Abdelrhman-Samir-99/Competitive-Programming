#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

class Trie {

	private:

		struct node {
			node* characters[26]; // Representing the chars available at this current node, or how this prefix
			// can go further.
			// you can store bunch of other stuff here, like if this is an end of a word or the count etc.
		};
		
		vector <node*> all_nodes; // to pervent memory leak problems, so we clear it in the destructor.
		node* root; // Representing the first level.
		int get_Index(char c) { return c - 'a';} // getting the index in the alphabet.

		node* create_Node() {
			node* new_node = new node;
			
			for(int i = 0; i < 26; ++i) // Initializing all the values with NULL instead of garbage.
				new_node-> characters[i] = NULL;

			all_nodes.emplace_back(new_node); // keeping track of each node to delete it later.
			return new_node;
		}

		void clear() {
			for(node* current : all_nodes)
				delete current; // clearing all the memory we allocated.
		}
		
	public:

		Trie() {
			root = create_Node(); // Start of our Trie.
		}

		~Trie() {
			clear();
		}

		void add(string text) {
			node* parent_pointer = root; // We are one step behind, so for my implementation i always care about the parent.
			
			for(int i = 0; i < int(text.size()); ++i) {
				int index = get_Index(text[i]); // the index of the current char in the alphabetic.

				if(parent_pointer-> characters[index] == NULL) {
					// Checking if there's a path exist already, if not we create a node to extend it.
					parent_pointer-> characters[index] = create_Node();
				}

				// Changing our index to the new node.
				parent_pointer = parent_pointer-> characters[index];
			}
		}

		bool find(string prefix) {
			node* parent_pointer = root;
			// Starting from the root and following the path until we reach to the end of a prefix or NULL.
			for(int i = 0; i < int(prefix.size()); ++i) {
				int index = get_Index(prefix[i]);
				if(parent_pointer-> characters[index] == NULL)
					return false;

				parent_pointer = parent_pointer-> characters[index];
			}
			return true;
		}
};
