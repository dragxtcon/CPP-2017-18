// Waylon Peng, Period 1
// 6Dec2017
// Linked List Assignment
// Computes several values using loops.

#include <iostream>
#include <cmath>
using namespace std;

struct node {
    int node_data = 0;
    node* next_node = NULL;
};

node* root = NULL;

void add_node(int data) {
    node* temp_node = root;
    root = new node;
    root->node_data = data;
    root->next_node = temp_node;
}

int delete_node() {
    node* temp_node = root;
    root = temp_node->next_node;
    int temp_value = temp_node->node_data;
    delete temp_node;
    return temp_value;
}

int main() {
    add_node(30);
    add_node(300);
    add_node(50);
    cout << delete_node();
}
