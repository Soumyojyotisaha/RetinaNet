#include <stdio.h>

// Function to calculate the sum of digits of a number
int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int rows, cols;
    
    // Read matrix dimensions
    scanf("%d %d", &rows, &cols);
    int matrix[rows][cols];
    
    // Read matrix elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Process matrix row-wise to calculate the sum of digits for each row
    printf("Sum of digits for each row:\n");
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += sumOfDigits(matrix[i][j]);
        }
        printf("%d\n", rowSum);
    }
    
    return 0;
}
