#include <stdio.h>
#include <stdlib.h>
#define ROW 4
#define COLUMN 5

int main() {
    int sparse_matrix[ROW][COLUMN] = {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };

    int size = 0;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            if (sparse_matrix[i][j] != 0) {
                size++;
            }
        }
    }

    int* compact_matrix[3];
    for (int i = 0; i < 3; i++) {
        compact_matrix[i] = (int*)calloc(size, sizeof(int));
    }

    int k = 0;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            if (sparse_matrix[i][j] != 0) {
                compact_matrix[0][k] = i;
                compact_matrix[1][k] = j;
                compact_matrix[2][k] = sparse_matrix[i][j];
                k++;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", compact_matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        free(compact_matrix[i]);
    }
    return 0;
}