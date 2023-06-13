#include <stdio.h>
#include "binary_tree.c"

int main() {
    node* root = new_node(0);
    insert_left(root, 1);
    insert_right(root, 2);

    insert_left(root->left_child, 3);
    insert_left(root->left_child->left_child, 4);

    display_tree(root);

    return 0;
}