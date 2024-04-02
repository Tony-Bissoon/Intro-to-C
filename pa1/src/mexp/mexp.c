#include <stdio.h>
#include <stdlib.h>

// Function to allocate a matrix of size k x k
int **allocateMatrix(int k) {
    int **matrix = (int **)malloc(k * sizeof(int *));
    for (int i = 0; i < k; i++) {
        matrix[i] = (int *)malloc(k * sizeof(int));
    }
    return matrix;
}

// Function to free the memory of a matrix
void freeMatrix(int **matrix, int k) {
    for (int i = 0; i < k; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to multiply two matrices and store the result in res
void matrixMultiply(int k, int **A, int **B, int **res) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            res[i][j] = 0;
            for (int l = 0; l < k; l++) {
                res[i][j] += A[i][l] * B[l][j];
            }
        }
    }
}

// Function to compute the matrix power M^n
void matrixExponentiation(int k, int **M, int n, int **result) {
    if (n == 0) {
        // Identity matrix for M^0
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                result[i][j] = (i == j) ? 1 : 0;
            }
        }
    } else if (n == 1) {
        // M^1 is M
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                result[i][j] = M[i][j];
            }
        }
    } else {
        // Compute M^(n-1)
        int **temp = allocateMatrix(k);
        matrixExponentiation(k, M, n - 1, temp);

        // Multiply M^(n-1) by M to get M^n
        matrixMultiply(k, M, temp, result);

        // Free the temporary matrix
        freeMatrix(temp, k);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        
        return EXIT_FAILURE;
    }

    char *input_file = argv[1];
    FILE *file = fopen(input_file, "r");
    if (!file) {
       
        return EXIT_FAILURE;
    }

    int k;
    fscanf(file, "%d", &k);

    int **M = allocateMatrix(k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            fscanf(file, "%d", &M[i][j]);
        }
    }

    int n;
    fscanf(file, "%d", &n);

    fclose(file);

    int **result = allocateMatrix(k);
    matrixExponentiation(k, M, n, result);

    // Print the result matrix
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            printf("%d", result[i][j]);
            if (j < k - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Free the matrices
    freeMatrix(M, k);
    freeMatrix(result, k);

    return EXIT_SUCCESS;
}
