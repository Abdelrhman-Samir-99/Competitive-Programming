#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
class List {
  
  private:
    struct node {
      node* next;
      T data;
    };
    
    node* current; // We use this variable as an iterator.
    node* head; // The start of our list.
    node* tail; // The end of our list.

    
  public:
    int Length;
    
    List() {
      current = NULL;
      head = NULL;
      tail = NULL;
      Length = 0;
    }
    ~List() {
      clear();
    }
    void add(T Data) {
      // Creating a new node.
      node* new_node = new node;
      new_node-> next = NULL; // making it point to null cause this is our last current node.
      new_node-> data = Data;
    
      if(head != NULL) {
        // IFF the last have at least one item;
        tail-> next = new_node;
        tail = new_node;
      }
      else {
        //the first item added to the list.
        //Initialize the address of the head pointer.
        head = new_node;
        tail = new_node;
      }
      ++Length;
    }

    void erase(T Data, int count = 1) {
      // IFF count < 0 that's mean a negative number, which makes no sense.
      assert(count >= 0);
      current = head;
      while(current != NULL && count > 0) {
        if(current == head && current-> data == Data) {
          // IFF the head should be deleted.
          node* temp = current;
          current = current-> next;
          head = current;
          delete temp;
          --Length;
          --count;
        }
        else if(current-> next != NULL && (current-> next)-> data == Data) {
          // IFF the next node will be deleted.
          node* temp = current-> next;
          current-> next = (current-> next)-> next;
          delete temp;
          --Length;
          --count;
        }
        else {
          current = current-> next;
        }
      }
      
      current = head;

      // Just to keep-track of the tail, in the worst case still the same O(N),
      // But in the best case this is not sufficient.
      while(current != NULL) {
        if(current-> next == NULL)
          tail = current;
        current = current-> next;
      }
      if(Length == 0)
        tail = NULL;
    }

    void insert(T Data, int position) {

      assert(position >= 0); // assertion when we insert a negative index.
      int current_pos = 0;
      // our new node.
      node* new_node = new node;
      new_node-> data = Data;
      new_node-> next = NULL;

      current = head; // getting the address to insert to.
      while(current != NULL && current_pos != position) {
        current = current-> next;
        ++current_pos;
      }

      // Keeping track of the head & tail.
      if(current == NULL) {
        tail-> next = new_node;
        tail = new_node;
      }
      else if(current == head) {
        new_node-> next = head;
        head = new_node;
      }
      else {
        node* temp = current-> next;
        current-> next = new_node;
        new_node-> next = temp;
      }
      ++Length;
    }
    
    void print() {
      current = head;
      while(current != NULL) {
        cout << current-> data << " ";
        current = current-> next;
      }
      puts("");
    }

    void clear() {
      // Deleting the whole list since there's no garbage collector in C++.
      current = head;
      while(current != NULL) {
        node* temp = current;
        current = current-> next;
        delete temp;
      }
    }
};
