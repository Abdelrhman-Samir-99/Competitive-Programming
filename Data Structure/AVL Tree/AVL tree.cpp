#include <bits/stdc++.h>
using namespace std;


template <class T>
class AVL {

private:
  // The node class.
  class Node {
    public:
      Node* left;
      Node* right;
      T value;
      
      // augmented data.
      int height, subtreeSize; 
      int count;
      

      Node() {}

      Node(T initialValue) {
        left = nullptr;
        right = nullptr;
        value = initialValue;
        height = 0, count = 1;
        subtreeSize = 1;
      }
  };

  
  Node* avlRoot; // the root of the tree.

  int height(Node* node) {
    // returning the depth of a node.
    return (node == nullptr ? -1 : node-> height);
  }

  int nodeBalance(Node* node) {
    // returning the balance of a node.
    return abs(height(node-> left) - height(node-> right));
  }


  Node* rotateLeft(Node* node) {
    Node* right = node-> right;
    Node* temp = right-> left; // otherwise I lose this subtree if I didn't creat temp.
    
    right-> left = node;
    node-> right = temp;

    
    fixNode(node);
    fixNode(right);
    
    return right;
  }

  Node* rotateRight(Node* node) {
    Node* left = node-> left;
    Node* temp = left-> right; // otherwise I lose this subtree if I didn't creat temp.

    left-> right = node;
    node-> left = temp;

    fixNode(node);
    fixNode(left);
    
    return left;
  }

  int getTreeSize(Node* node) {
    return node == nullptr ? 0 : node-> subtreeSize;
  }

  void fixNode(Node* node) {
    // I should just update the height of the node and subtree size.

    node-> height = max(height(node-> left), height(node-> right)) + 1;
    node-> subtreeSize = getTreeSize(node-> left) + getTreeSize(node-> right) + node-> count;
  }

  Node* balanceNode(Node* root) {
    /*
      there can be only 4 cases.
      left left
      left right
        right right
      right left
    */
       
    if(height(root-> left) > height(root-> right)) {
      // left is heavier
      if(height(root-> left -> left) > height(root-> left-> right)) {
        // left of the child is heavier
        return rotateRight(root);
      }
      else {
        // right of the child is heavier
        root-> left = rotateLeft(root-> left);
        return rotateRight(root);
      }
    }
    else {
      // right child is heavier
      if(height(root-> right -> right) > height(root-> right -> left)) {
        // right of the child is heavier
        return rotateLeft(root);
      }
      else {
        // left of the child is heavier
        root-> right = rotateRight(root-> right);
        return rotateLeft(root);
      }
    }
    return root;
  }
  

  inline Node* avlInsert(T insertedValue, Node* root) {

    if(root == nullptr) {
      return new Node(insertedValue);
    }
    

    if(root-> value == insertedValue) {
      ++(root-> count);
    }
    else if(insertedValue > root-> value) {
      root-> right = avlInsert(insertedValue, root-> right);
    }
    else {
      root-> left = avlInsert(insertedValue, root-> left);
    }

    fixNode(root);

    // updating the height of the node after insertion.
    
    if(nodeBalance(root) > 1) {
      return balanceNode(root);
    }
    return root;
  }

  inline Node* avlSearch(T searchValue, Node* root) {

    if(root == nullptr) {
      return nullptr;
    }

    if(root-> value == searchValue) {
      return root;
    }
    
    Node* ret;
    
    if(root-> value > searchValue) {
      ret = avlSearch(searchValue, root-> left);
    }
    else {
      ret = avlSearch(searchValue, root-> right);
    }
    return ret;
  }

  inline Node* do_lower_bound(T value, Node* root) {
    Node* ret;

    if(root-> value >= value) {
      ret = root;
    }
    else {
      ret = do_lower_bound(value, root-> right);
    }
    return ret;
  }

  inline Node* do_upper_bound(T value, Node* root) {
    Node* ret;
    if(root-> value > value) {
      ret = root;
    }
    else {
      ret = do_upper_bound(value, root-> right);
    }
    return ret;
  }


  // Fix these 3 functions
  inline int getGreater(T value, Node* root) {
    if(root == nullptr) {
      return 0;
    }

    int ret = 0;

    if(root-> value > value) {
      ret = root-> count;
    }
    ret += getGreater(value, root-> right);
    return ret;
  }

  inline int getLower(T value, Node* root) {
    if(root == nullptr) {
      return 0;
    }

    int ret = 0;
    if(root-> value < value) {
      ret = root-> count;
    }
    ret += getLower(value, root-> left);
    return ret;
  }

  inline int getEqual(T value, Node* root) {
    if(root == nullptr) {
      return 0;
    }
    
    if(root-> value == value) {
      return root-> count;
    }

    int ret = 0;
    
    if(root-> value > value) {
      ret = getEqual(value, root-> left);
    }
    else {
      ret = getEqual(value, root-> right);
    }
    return ret;
  }
  inline void get_inorder(Node* root, vector <T> &ret) {
    // Left root right
    if(root-> left != nullptr) {
      get_inorder(root-> left, ret);
    }
    
    assert(root != nullptr);
    ret.push_back(root-> value);

    if(root-> right != nullptr) {
      get_inorder(root-> right, ret);
    }
  }

  inline void get_preorder(Node* root, vector <T> &ret) {
    // root left right
    assert(root != nullptr);
    ret.push_back(root-> value);
    if(root-> left != nullptr) {
      get_preorder(root-> left, ret);
    }

    if(root-> right != nullptr) {
      get_preorder(root-> right, ret);
    }
  }

  inline void get_postorder(Node* root, vector <T> &ret) {
    // Left right root.
    if(root-> left != nullptr) {
      get_postorder(root-> left, ret);
    }

    if(root-> right != nullptr) {
      get_postorder(root-> right, ret);
    }
    
    assert(root != nullptr);
    ret.push_back(root-> value);
  }

  

  void destroy(Node* root) {

    if(root != nullptr) {
      destroy(root-> left);
      destroy(root-> right);
    }
                                
    delete root;
  }

public:
  AVL() {
    avlRoot = nullptr;
  }

  ~AVL() {
    destroy(avlRoot);
  }
  
  void insert(T insertedValue) {
    avlRoot = avlInsert(insertedValue, avlRoot);
  }

  bool find(T searchValue) {
    return avlSearch(searchValue, avlRoot);
  }

  vector <T> inorder() {
    vector <T> ret;
    get_inorder(avlRoot, ret);
    return ret;
  }

  vector <T> preorder() {
    vector <T> ret;
    get_preorder(avlRoot, ret);
    return ret;
  }

  vector <T> postorder() {
    vector <T> ret;
    get_postorder(avlRoot, ret);
    return ret;
  }

  // TODO
  
  void median() {
  }

  Node* lower_bound(T value) {
    return do_lower_bound(value, avlRoot);
  }

  Node* upper_bound(T value) {
    return do_upper_bound(value, avlRoot);
  }

  int cnt_greater(T value) {
    return getGreater(value, avlRoot);
  }

  int cnt_lower(T value) {
    return getLower(value, avlRoot);
  }

  int cnt_equal(T value) {
    return getEqual(value, avlRoot);
  }

  T begin() {
    assert(avlRoot != nullptr);
    Node* temp = avlRoot;
    while(temp -> left != nullptr) {
      temp = temp-> left;
    }
    return temp-> value;
  }

  T end() {
    assert(avlRoot != nullptr);
    Node* temp = avlRoot;
    while(temp-> right != nullptr) {
      temp = temp-> right;
    }
    return temp-> value;
  }
};



int main() {
  AVL <int> test;
  test.insert(5);
  cerr << test.lower_bound(5)-> value << '\n';
}
