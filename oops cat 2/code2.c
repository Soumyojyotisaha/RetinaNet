#include <stdio.h>

int main() {
    int n, primarySum = 0, secondarySum = 0;
    
    // Read matrix size
    scanf("%d", &n);
    int matrix[n][n];
    
    // Read matrix elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Process matrix: compute diagonal sums and transform non-diagonal elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                primarySum += matrix[i][j]; // Primary diagonal
            }
            if (i + j == n - 1) {
                secondarySum += matrix[i][j]; // Secondary diagonal
            }
            if (i != j && i + j != n - 1) {
                matrix[i][j] *= matrix[i][j]; // Square non-diagonal elements
            }
        }
    }
    
    // Print diagonal sums
    printf("Sum of primary diagonal: %d\n", primarySum);
    printf("Sum of secondary diagonal: %d\n", secondarySum);
    
    // Print transformed matrix
    printf("Transformed matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
