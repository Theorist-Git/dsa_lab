#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

typedef struct Node {
    int data;
    struct Node* left_child;
    struct Node* right_child;
} node;

// O(1)
node* new_node(int data) {
    node* new_node = malloc(sizeof(node));
    new_node->data = data;

    new_node->left_child = NULL;
    new_node->right_child = NULL;

    return new_node;
}

// O(1)
node* insert_left(node* parent, int data) {
    parent->left_child = new_node(data);

    return parent->left_child;
}

node* insert_right(node* parent, int data) {
    parent->right_child = new_node(data);

    return parent->right_child;
}

// left root right
// O(n) where n = number of nodes. (Each node is traversed once)
void inorder(node* root) {
    if (root == NULL) {
        return;
    } else {
        inorder(root->left_child);
        printf("%d ", root->data);
        inorder(root->right_child);
    }
}

// root left right
// O(n) where n = number of nodes. (Each node is traversed once)
void preorder(node* root) {
    if (root == NULL) {
        return;
    } else {
        printf("%d ", root->data);
        preorder(root->left_child);
        preorder(root->right_child);
    }
}

// left right root
// O(n) where n = number of nodes. (Each node is traversed once)
void postorder(node* root) {
    if (root == NULL) {
        return;
    } else {
        postorder(root->left_child);
        postorder(root->right_child);
        printf("%d ", root->data);
    }
} 

void display_util(node* root, int space) {
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    display_util(root->left_child, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 
    // Process left child
    display_util(root->right_child, space);
}

// Wrapper over display_util()
void display_tree(struct Node* root) {
    // Pass initial space count as 0
    display_util(root, 0);
}
