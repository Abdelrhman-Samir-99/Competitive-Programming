#include <iostream>
#include <vector>
using namespace std;


// In in-order we go (left-> root -> right).
void in_order(int node, int parent, vector <vector<int>> &graph) {
	if(graph[node].size() == 1) {
		// this is a leaf node and we will print it.
		printf("%d ", node);
		return;
	}
	bool printed = false;
	for(int &child : graph[node]) {
		if(child == parent)
			continue;
		in_order(child, node, graph);
		if(printed == false) {
			printf("%d ", node);
			printed = true;
		}
	}
}
