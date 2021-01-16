#include <iostream>
#include <vector>
using namespace std;


// In pre-order we go (root -> left -> right).
void pre_order(int node, int parent, vector <vector<int>> &graph) {
	printf("%d ", node);
	for(int &child : graph[node]) {
		if(child == parent)
			continue;
		pre_order(child, node, graph);
	}
}
