#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int deg;
    struct Node* next;
} node;

typedef struct Polynomial {
    node* head;
    node* temp;
    int deg;
} polynomial;

polynomial insert(int coeff, int deg, polynomial poly_data) {
    polynomial data = {NULL, NULL, deg};
    node* head = poly_data.head;
    node* temp = poly_data.temp;

    node* new_node = malloc(sizeof(node));
    new_node->coeff = coeff;
    new_node->deg = deg;
    new_node->next = NULL;

    if (head == NULL) {
        head = temp = new_node;
    } else {
        temp->next = new_node;
        temp = new_node;
    }

    data.head = head;
    data.temp = temp;

    return data;
}

polynomial create_polynomial(int deg) {
    int coeff;
    printf("Enter %d deg. term's coefficient: ", deg);
    scanf("%d", &coeff);
    polynomial data = {NULL, NULL, deg};
    data = insert(coeff, deg, data);

    for (int i = 1; i <= deg; i++) {
        printf("Enter %d deg. term's coefficient: ", deg - i);
        scanf("%d", &coeff);

        data = insert(coeff, deg - i, data);
    }

    data.deg = deg;

    return data;

}

void display_polynomial(polynomial poly) {
    node* iter = poly.head;
    if (poly.head == NULL) {
        printf("Empty List\n");
    } else {
        while (iter != NULL) {
            if (iter->deg == 0) {
                break;
            }
            if (iter->coeff != 0) {
                printf("%dx^%d", iter->coeff, iter->deg);
                printf(" + ");
            }
            iter = iter->next;
        }    
        printf("%d", iter->coeff);
        printf("\n");
    }
}

polynomial add_polynomials(polynomial poly1, polynomial poly2) {
    if (poly1.head == NULL) {
        return poly2;
    } else if (poly2.head == NULL) {
        return poly1;
    }
    node* iter_poly1 = poly1.head;
    node* iter_poly2 = poly2.head;

    polynomial addn = {NULL, NULL, 0};

    while (iter_poly1 != NULL && iter_poly2 != NULL) {
        if (iter_poly1->deg == iter_poly2->deg) {
            addn = insert(iter_poly1->coeff + iter_poly2->coeff, iter_poly1->deg, addn);
            iter_poly1 = iter_poly1->next;
            iter_poly2 = iter_poly2->next;
        } else if (iter_poly1->deg > iter_poly2->deg) {
            addn = insert(iter_poly1->coeff, iter_poly1->deg, addn);
            iter_poly1 =  iter_poly1->next;
        } else {
            addn = insert(iter_poly2->coeff, iter_poly2->deg, addn);
            iter_poly2 =  iter_poly2->next;
        }
    }

    while (iter_poly1 != NULL) {
        addn = insert(iter_poly1->coeff, iter_poly1->deg, addn);
        iter_poly1 =  iter_poly1->next;
    }

    while (iter_poly2 != NULL) {
        addn = insert(iter_poly2->coeff, iter_poly2->deg, addn);
        iter_poly2 =  iter_poly2->next;
    }
    return addn;

}

int main() {
    polynomial poly_1 = create_polynomial(2);
    polynomial poly_2 = create_polynomial(4);

    printf("Polynomial 1: "); display_polynomial(poly_1);
    printf("Polynomial 2: "); display_polynomial(poly_2);

    polynomial addn = add_polynomials(poly_1, poly_2);
    printf("Poly1 + Poly2: "); display_polynomial(addn);

    return 0;
}