#include <stdio.h>
#include "binary_tree.c"

/*
Complexity Summary:
(N = number of nodes)

Operation 	Worst Case 	Average Case 	Best Case 	Space
Search 	        O(N) 	 O(logN) 	      O(1) 	     O(N)
Insert 	        O(N) 	 O(logN) 	      O(1) 	     O(N)
Delete 	        O(N) 	 O(logN) 	      O(N) 	     O(N)
*/

int isBST(node* root) {
    /*
    Traverses the entire binary tree and returns whether its a BST or not
    Mimics inorder traversal algorithm. (BSTs return inorder traversal in ascending order)
    
    In-order, Pre-order, and Post-order traversals are Depth-First traversals.

    For a Graph, the complexity of a Depth First Traversal is O(n + m), where n is the number of nodes, 
    and m is the number of edges.
    Since a Binary Tree is also a Graph, the same applies here. 
    The complexity of each of these Depth-first traversals is O(n+m).

    Since the number of edges that can originate from a node is limited to 2 in the case of a Binary Tree, 
    the maximum number of total edges in a Binary Tree is n-1, where n is the total number of nodes.

    The complexity then becomes O(n + n-1), which is O(n).
    Time Complexity = O(n)

    */
    static node* prev = NULL; // Will store the last element in inorder traversal
                              // static so different functions don't make different copies. 
    if (root != NULL) {
        if (!isBST(root->left_child)) {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data) {
            return 0;   
        }
        prev = root;
        return isBST(root->right_child);
    } else {
        // If root is NULL, empty tree is treated as a BST.
        return 1;
    }
}

void insertBST(node* root, int key) {
    /*
    Time complexity = O(h)
    also, log(n) <= h <= n where n is the number of nodes,
    therefore in the best case: Balanced BST insertion = O(logn)
                    worst case: Skewed BST insertion = O(n)
    */
    node* prev = NULL;
    while (root != NULL) {
        prev = root;
        if (key == root->data) {
            printf("BST cannot have duplicate elements. %d found at %p.", key, root);
            return;
        } else if (key > root->data) {
            root = root->right_child;
        } else {
            root = root->left_child;
        }
    }
    if (key > prev->data) {
        insert_right(prev, key);
    } else {
        insert_left(prev, key);
    }
}


/*
For searching, we have to make 'h + 1' comparisons in the worst case.
Therefore Time complexity = O(h)
also, log(n) <= h <= n where n is the number of nodes,
therefore in the best case: Balanced BST search = O(logn)
                worst case: Skewed BST search = O(n)
*/
node* search_recursive(node* root, int key) {
    if (root == NULL) {
        printf("Element not found");
        return NULL;
    }

    if (key == root->data) {
        return root;
    } else if (key > root->data) {
        return search_recursive(root->right_child, key);
    } else {
        return search_recursive(root->left_child, key);
    }
}

node* search_iterative(node* root, int key) {
    while (root != NULL) {
        if (key == root->data) {
            return root;
        } else if (key > root->data) {
            root = root->right_child;
        } else {
            root = root->left_child;
        }
    }
    printf("Element not found");
    return NULL;
}

node* inorder_predecessor(node* root) {
    root = root->left_child;
    while (root->right_child != NULL) {
        root = root->right_child;
    }

    return root;
} 

node* delete(node* root, int key) {
    node* in_pre = NULL;

    if (root == NULL) {
        return NULL;
    }

    if (root->left_child == NULL && root->right_child == NULL) {
        free(root);
        return NULL;
    }

    if (key > root->data) {
        root->right_child = delete(root->right_child, key);
    } else if (key < root->data) {
        root->left_child = delete(root->left_child, key);
    } else {
        in_pre = inorder_predecessor(root);
        root->data = in_pre->data;
        root->left_child = delete(root->left_child, in_pre->data);
    }

    return root;
}
