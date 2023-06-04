#include <stdio.h>
#include "singly_LL.c"

int main() {
    while (1) {
        int choice;
        printf("Enter 1 to INSERT at BACK of SLL\n\
Enter 2 to INSERT at FRONT of SLL\n\
Enter 3 to INSERT at SPECIFIED POS. of SLL\n\
Enter 4 to DELETE from BACK\n\
Enter 5 to DELETE from FRONT\n\
Enter 6 to DELETE from SPECIFIED POS.\n\
Enter 7 to DISPLAY SLL\n\
Enter 0 to QUIT: "
        );
        scanf("%d", &choice);
        if (choice == 1) {
            int data;
            printf("Enter value to be INSERTED at BACK: ");
            scanf("%d", &data);
            insert_back(data);
            display(1);
        } else if (choice == 2) {
            int data;
            printf("Enter value to be INSERTED at FRONT: ");
            scanf("%d", &data);
            insert_front(data);
            display(1);
        } else if (choice == 3) {
            int data, pos;
            printf("Enter value to be INSERTED: ");
            scanf("%d", &data);

            printf("Where should %d be INSERTED(Range: [0 - %d]): ", data, len);
            scanf("%d", &pos);

            insert_pos(data, pos);
            display(1);
        } else if (choice == 4) {
            delete_back();
            display(1);
        } else if (choice == 5) {
            delete_front();
            display(1);
        } else if (choice == 6) {
            int pos;
            printf("Where should element be DELETED from(Range: [0 - %d]): ", len - 1);
            scanf("%d", &pos);

            delete_at_pos(pos);
            display(1);
        }
        else if (choice == 7) {
            display(1);
        } else if (choice == 0) {
            break;
        }
    }

    return 0;
}