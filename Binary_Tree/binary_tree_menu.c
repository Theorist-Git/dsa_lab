#include <stdio.h>
#include "bst.c"

int main() {

    node* root = new_node(5);
    insert_left(root, 3);
    insert_right(root, 6);

    insert_left(root->left_child, 1);
    insert_right(root->left_child, 4);

    // insert_left(root->left_child->right_child, 2);

    insert_right(root->right_child, 10);

    /*
         5
        / \
      3    6
     /  \   \
    1    4   10
    */

    printf("Inorder: "); inorder(root);printf("\n");
    printf("Preorder: "); preorder(root);printf("\n");
    printf("Postorder: "); postorder(root);printf("\n");

    printf("Is BST: %d\n", isBST(root));

    printf("Found at mem loc: %p\n", search_recursive(root, 5));
    printf("Found at mem loc: %p\n", search_iterative(root, 5));

    insertBST(root, 12);
    printf("Is BST: %d\n", isBST(root));
    /*
         5
        / \
      3    6
     /  \   \
    1    4   10
              \  
               12
    */

    printf("Inorder: "); inorder(root);printf("\n");

    delete(root, 5);

    printf("Inorder: "); inorder(root);printf("\n");

    inorder(root);printf("\n");
    display_tree(root);

    return 0;
}