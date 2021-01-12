#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;



class BST {
	private:
		struct node {
			node* right;
			node* left;
			int key;
		};
		
		node* root;
		vector <node*> track_nodes; // Can not find anything else for now, it's purpose -> pervent memory lekage exception.

		void add_function(int key, node* &current_node) {
			if(current_node == NULL) {
				current_node = create_Leaf(key);
				return;
			}
			int current_key = current_node-> key;
			if(key <= current_key)
				add_function(key, current_node-> left);
			else
				add_function(key, current_node-> right);
		}
		
		
		void InOrder(node* current_node) {
			if(current_node == NULL)
				return;
			InOrder(current_node-> left);
			printf("%d ", current_node-> key);
			InOrder(current_node-> right);
		}

		node* dfs(int key, node* current_node) {
			if(current_node == NULL)
				return NULL;
			if(current_node-> key == key)
				return current_node;
			if(key > current_node-> key)
				return dfs(key, current_node-> right);
			else
				return dfs(key, current_node-> left);
		}

		node* do_lower_bound(int key, node* current_node) {

			if(current_node == NULL)
				return NULL;
				
			if(current_node-> key >= key)
				return current_node;
			
			if(current_node-> left != NULL && (current_node-> left) -> key >= key)
				return do_lower_bound(key, current_node-> left);

			return do_lower_bound(key, current_node-> right);
		}

		node* do_upper_bound(int key, node* current_node) {

			if(current_node == NULL)
				return NULL;
			
			if(current_node-> key > key)
				return current_node;

			if(current_node-> left != NULL && (current_node-> left) -> key > key)
				return do_upper_bound(key, current_node-> left);

			return do_upper_bound(key, current_node-> right);
		}

		
	public:
	
		BST() {
			root = NULL;
		}

		~BST() {
			clear();
		}
		
		node* create_Leaf(int key) {
			node* new_node = new node;
			
			new_node-> key = key;
			new_node-> left = NULL;
			new_node-> right = NULL;
			track_nodes.emplace_back(new_node);
			return new_node;
		}

		void add(int key) {
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
		
		node* find(int key) {
			assert(root != NULL);
			return dfs(key, root);
		}
		
		node* lower_bound(int key) {
			assert(root != NULL);
			return do_lower_bound(key, root);
		}

		node* upper_bound(int key) {
			assert(root != NULL);
			return do_upper_bound(key, root);
		}

		void erase(int key) {
			assert(root != NULL);
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
