#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE* link;
} node;

node* head = NULL; 
node* temp = NULL;
int len = 0;

void insert_back(int data) {
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->link = NULL;

    if (head == NULL) {
        head = temp = new_node;
        len++;
    } else {
        temp->link = new_node;
        temp = new_node;
        len++;
    }
}

void insert_front(int data) {
    if (head == NULL) {
        insert_back(data);
        len++;
    } else {
        node* new_node = malloc(sizeof(node));
        new_node->data = data;
        new_node->link = head;
        head = new_node;
        len++;
    }
}

void insert_pos(int data, int pos) {
    if (head == NULL || pos == len) {
        insert_back(data);
    } else if (pos == 0) {
        insert_front(data);
    } else if (pos >= len) {
        printf("List index out of range.\n");
    } else {
        node* new_node = malloc(sizeof(node));
        new_node->data = data;
        node* iter = head;
        int i = 1;
        while (i != pos) {
            iter = iter->link;
            i++;
        }
        new_node->link = iter->link;
        iter->link = new_node;
        len++;
    }
}

void delete_back() {
    if (head == NULL) {
        printf("Empty List.\n");
    } else {
        int i = 0;
        if (len == 1) {
            free(head);
            head = temp = NULL;
            len = 0;
        } else {
            node* iter = head;
            while (i != len - 2) {
                i++;
                iter = iter->link;
            }
            node* last = iter->link;
            last = last->link;
            free(last);
            iter->link = NULL;
            len--;
            temp = iter;            
        }
    }
}

void delete_front() {
    if (head == NULL) {
        printf("Empty List.\n");
    } else {
        int i = 0;
        if (len == 1) {
            free(head);
            head = temp = NULL;
            len = 0;
        } else {
            node* new_head = head->link;
            free(head);
            head = new_head;
            len--;         
        }
    }
}

void delete_at_pos(int pos) {
    if (head == NULL) {
        printf("Empty list.\n");
    } else if (pos == 0) {
        delete_back();
    } else if (pos == len - 1) {
        delete_front();
    } else {
        node* iter = head;
        int i = 1;
        while (i != pos) {
            iter = iter->link;
            i++;
        }
        node* del = iter->link;
        iter->link = del->link;
        free(del);
        len--;
    }
}


void display(int display_indices) {
    node* iter = head;
    if (head == NULL) {
        printf("Empty List\n");
    } else {
        if (!display_indices) {
            while (iter != NULL) {
                printf("%d ", iter->data);
                iter = iter->link;
            }
            printf("\n");
        } else {
            int i = 0;
            while (iter != NULL) {
                printf("[%d]: %d ", i++, iter->data);
                iter = iter->link;
            }
            printf("\n");
        }
    }
}