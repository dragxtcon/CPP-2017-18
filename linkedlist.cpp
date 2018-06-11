// Waylon Peng, Period 1
// 6Dec2017
// Linked List Assignment
// Implements a linked list (similar to a stack).

#include <iostream>
#include <cmath>
using namespace std;

//struct used to symbolize each element in linked list
struct node {
    int node_data = 0; //data stored in node
    node* next_node = NULL; //next node
};

//a pointer to the first (root) element in the linked list
node* root = NULL;

//adds a node to the beginning of the list with data
void add_node(int data) {
    node* temp_node = root; //creates temporary pointer pointing to former first node
    root = new node; //creates new first node
    root->node_data = data; //places data in new node
    root->next_node = temp_node; //points node to next node (former first node)
}

//deletes a node from the beginning of the list, and returns the value it held
int delete_node() {
    node* temp_node = root; //stores pointer of to-be-deleted node
    root = temp_node->next_node; //sets second node as first node
    int temp_value = temp_node->node_data; //stores data from to-be-deleted node
    delete temp_node; //the node is now gone from the list. this deletes it from memory
    return temp_value; //returns previously saved value
}

int main() {
    add_node(30);
    add_node(300);
    add_node(50);
    cout << delete_node();
}
