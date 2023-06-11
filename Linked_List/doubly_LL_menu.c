#include <stdio.h>
#include "doubly_LL.c"

int main() {
    while (1) {
        int choice;
        printf("Enter 1 to INSERT at BACK of DLL\n\
Enter 2 to INSERT at FRONT of DLL\n\
Enter 3 to DELETE from BACK\n\
Enter 4 to DELETE from FRONT\n\
Enter 5 to INSERT after a value\n\
Enter 6 to INSERT before a value\n\
Enter 7 to DELETE a certain node\n\
Enter 8 to DISPLAY DLL(Front to Back)\n\
Enter 9 to DISPLAY DLL(Back to Front)\n\
Enter 0 to QUIT: "
        );
        scanf("%d", &choice);
        if (choice == 1) {
            int data;
            printf("Enter value to be INSERTED at BACK: ");
            scanf("%d", &data);
            insert_back(data);
            display_back();
        } else if (choice == 2) {
            int data;
            printf("Enter value to be INSERTED at FRONT: ");
            scanf("%d", &data);
            insert_front(data);
            display_back();
        } else if (choice == 3) {
            delete_back();
            display_back();
        } else if (choice == 4) {
            delete_front();
            display_back();
        } else if(choice == 5) {
            int data_node, data_after;
            printf("Enter value after which data is to be inserted: ");
            scanf("%d", &data_after);
            printf("Enter value to be INSERTED after %d: ", data_after);
            scanf("%d", &data_node);
            insert_after(data_after, data_node);
            display_back();
        } else if (choice == 6) {
            int data_node, data_before;
            printf("Enter value before which data is to be inserted: ");
            scanf("%d", &data_before);
            printf("Enter value to be INSERTED before: %d", data_before);
            scanf("%d", &data_node);
            insert_before(data_before, data_node);
            display_back();
        } else if (choice == 7) {
            int data_node;
            printf("Enter value to be DELETED: ");
            scanf("%d", &data_node);
            delete_element(data_node);
            display_back();
        } else if (choice == 8) {
            display_back();
        } else if (choice == 9) {
            display_front();
        } else if (choice == 0) {
            break;
        }
    }

    return 0;
}