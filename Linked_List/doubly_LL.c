#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    // Each node stores pointer to previous node and next node.
    struct Node* prev;
    int data;
    struct Node* next;
} node;

// head is used to point to the first node.
// temp points to the address of the last added node.
node* head = NULL;
node* temp = NULL;

// Inserts data to back of the list
// Eg: 1 2 3
// insert_back(4)
// 1 2 3 4
void insert_back(int data) {
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = temp = new_node;
        new_node->prev = NULL;
    } else {
        temp->next = new_node;
        new_node->prev = temp;
        temp = new_node;
    }
}

void insert_front(int data) {
    if (head == NULL) {
        insert_back(data);
    } else {
        node* new_node = malloc(sizeof(node));
        
        new_node->data = data;
        new_node->prev = NULL; // Front push will always put element at the start therefore prev. ptr is NULL

        new_node->next = head; // Next ptr should point to element that was first before this, head points
                               // to the memory location of that node by definition

        head->prev = new_node; // The ex-first node should now store address of the new first node in the prev
                               // pointer 

        head = new_node;       // Head now points to new_node 
    }

}

void insert_after(int data_after, int node_data) {
    if (head == NULL) {
        printf("List is empty, value inserted as first node!\n");
        insert_back(node_data);
    } else {
        node* iter = head; // will point to node after which insertion is to be done.

        while (iter->data != data_after && iter->next != NULL) {
            iter = iter->next;
        }
        if (iter->next == NULL) {
            if (iter->data == data_after) {
                insert_back(node_data);
            } else {
                printf("Data not present in LinkeList!\n");
            }
        } else {
            node* new_node = malloc(sizeof(node));

            new_node->data = node_data;
            new_node->prev = iter;      // new node's prev pointer now points to iter node
            new_node->next = iter->next;// next ptr points to node after iter

            node* orig_temp_next = iter->next;
            iter->next = new_node;
            orig_temp_next->prev = new_node; 
        }
    }
}

void insert_before(int data_before, int node_data) {
    if (head == NULL) {
        printf("List is empty, value inserted as first node!\n");
        insert_back(node_data);
    } else {
        node* iter = head; // will point to node after which insertion is to be done.

        while (iter->data != data_before && iter->next != NULL) {
            iter = iter->next;
        }
        if (iter == head) {
            if (iter->data == data_before) {
                insert_front(node_data);
            } else {
                printf("Data not present in LinkeList!\n");
            }
        } else {
            node* new_node = malloc(sizeof(node));

            new_node->data = node_data;
            new_node->next = iter;      // new node's prev pointer now points to iter node
            new_node->prev = iter->prev;// next ptr points to node after iter

            node* orig_temp_prev = iter->prev;
            iter->prev = new_node;
            orig_temp_prev->next = new_node; 
        }
    }
}

void delete_back() {
    if (head == NULL) {
        printf("Empty list.\n");
    } else if (temp->prev == NULL) {
        free(temp);
        temp = head = NULL;
    } else {
        temp->prev->next = NULL;
        node* now_last_node = temp->prev;
        free(temp);
        temp = now_last_node;
    }
}

void delete_front() {
    if (head == NULL) {
        printf("Empty list.\n");
    } else if (head->next == NULL) {
        free(head);
        temp = head = NULL;
    } else {
        head->next->prev = NULL;
        node* new_first_node = head->next;
        free(head);
        head = new_first_node;
    }
}

void delete_element(int data) {
    if (head == NULL) {
        printf("Empty list.\n");
    } else {
        node* iter = head;
        while (iter->data != data && iter->next != NULL) {
            iter = iter->next;
        }
        if (iter->data != data) {
            printf("Data not present in LinkeList!\n");
        } else {
            if (iter == head) {
                delete_front();
            } else if (iter->next == NULL) {
                delete_back();
            } else {
                iter->next->prev = iter->prev;
                iter->prev->next = iter->next;
                free(iter);
            }
        }

    }
}

void display_back() {
    if (head == NULL) {
        printf("Empty list.\n");
    } else {
        node* iter = head;
        while (iter != NULL) {
            printf("%d ", iter->data);
            iter = iter->next;
        }
        printf("\n");
    }
}

void display_front() {
    if (head == NULL) {
        printf("Empty list.\n");
    } else {
        node* iter = temp;

        while (iter->prev != NULL) {
            printf("%d ", iter->data);
            iter = iter->prev;
        }
        printf("%d", iter->data);
        printf("\n");
    }
}
