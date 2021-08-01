#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;


template <class T>
class BST {
	
	private:
		struct node {
			node* right;
			node* left;
			T key;
		};
		
		node* root;
		vector <node*> track_nodes; // Can not find anything else for now, it's purpose -> pervent memory lekage exception.

		void add_function(T key, node* &current_node) {
			if(current_node == NULL) {
				current_node = create_Leaf(key);
				return;
			}
			T current_key = current_node-> key;
			if(key <= current_key)
				add_function(key, current_node-> left);
			else
				add_function(key, current_node-> right);
		}
		
		
		void InOrder(node* current_node) {
			if(current_node == NULL)
				return;
			InOrder(current_node-> left);
			cout <<  current_node-> key << " ";
			InOrder(current_node-> right);
		}

		node* dfs(T key, node* current_node) {
			if(current_node == NULL)
				return NULL;
			if(current_node-> key == key)
				return current_node;
			if(key > current_node-> key)
				return dfs(key, current_node-> right);
			else
				return dfs(key, current_node-> left);
		}

		node* do_lower_bound(T key, node* current_node) {

			if(current_node == NULL)
				return NULL;
				
			if(current_node-> key >= key)
				return current_node;
			
			if(current_node-> left != NULL && (current_node-> left) -> key >= key)
				return do_lower_bound(key, current_node-> left);

			return do_lower_bound(key, current_node-> right);
		}

		node* do_upper_bound(T key, node* current_node) {

			if(current_node == NULL)
				return NULL;
			
			if(current_node-> key > key)
				return current_node;

			if(current_node-> left != NULL && (current_node-> left) -> key > key)
				return do_upper_bound(key, current_node-> left);

			return do_upper_bound(key, current_node-> right);
		}

		void do_erase(T key, node* current_node, node* my_parent, bool is_Left = false) {

			// is_Left -> to keep track if the current_node is left or right to the parent.
			// we maintain my_parent to link the nodes after removal.

			// this key do not exist.
			if(current_node == NULL)
				return;

			// if my left child is the same as me then i just need to delete this node
			if(current_node-> left != NULL && current_node-> left -> key == key) {
				if(is_Left == true) {
					my_parent-> left = current_node-> left;
				}
				else {
					my_parent-> right = current_node-> left;
				}
				delete current_node;
				return;
			}
			
			if(current_node-> key == key) {
				if(current_node-> left == NULL && current_node-> right == NULL) {
					// this node is a leaf.
					delete current_node;
				}
				else if(current_node-> left != NULL && current_node-> right == NULL) {
					// only left child.
					if(is_Left == true) {
						my_parent-> left = current_node-> left;
					}
					else {
						my_parent-> right = current_node-> left;
					}
					delete current_node;
				}
				else if(current_node-> left == NULL && current_node-> right != NULL) {
					// only right child.
					if(is_Left == true) {
						my_parent-> left = current_node-> right;
					}
					else {
						my_parent-> right = current_node-> right;
					}
					delete current_node;
				}
				else {
					// have 2 childs.
					// get the lower_bound node (there must be one since there's a right child).
					node* best_value = this-> lower_bound(current_node-> key);
					current_node-> key = best_value-> key;
					erase(current_node-> key);
					delete current_node;
				}
				return;
			}
			if(key > current_node-> key) {
				do_erase(key, current_node-> right, current_node, false);
			}
			else {
				do_erase(key, current_node-> left, current_node, true);
			}
		}

		
	public:
	
		BST() {
			root = NULL;
		}

		~BST() {
			clear();
		}
		
		node* create_Leaf(T key) {
			node* new_node = new node;
			
			new_node-> key = key;
			new_node-> left = NULL;
			new_node-> right = NULL;
			track_nodes.emplace_back(new_node);
			return new_node;
		}

		void add(T key) {
			if(root == NULL) {
				root = create_Leaf(key);
			}
			else {
				add_function(key, root);
			}
		}

		void print_InOrder() {
			assert(root != NULL);
			InOrder(root);
		}
		
		node* find(T key) {
			assert(root != NULL);
			return dfs(key, root);
		}
		
		node* lower_bound(T key) {
			assert(root != NULL);
			return do_lower_bound(key, root);
		}

		node* upper_bound(T key) {
			assert(root != NULL);
			return do_upper_bound(key, root);
		}

		void erase(T key) {
			assert(root != NULL);
			do_erase(key, root, NULL);
		}

		void clear() {
			for(node* &current : track_nodes)
				delete current;
			track_nodes.clear();
		}

		node* get_Root() {
			assert(root != NULL);
			return root;
		}
};
