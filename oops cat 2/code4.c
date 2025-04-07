#include <stdio.h>

int main() {
    int n, a, b, count = 0, outsideSum = 0;
    
    // Read the number of elements
    scanf("%d", &n);
    int arr[n];
    
    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Read the range [a, b]
    scanf("%d %d", &a, &b);
    
    // Process the array based on conditions
    for (int i = 0; i < n; i++) {
        if (arr[i] >= a && arr[i] <= b) {
            arr[i] = i;  // Replace in-range numbers with their index
            count++;
        } else {
            outsideSum += arr[i];  // Sum numbers outside the range
        }
    }
    
    // Print the modified array
    printf("Array after operations: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
    
    // Print count and outside sum
    printf("Count=%d\n", count);
    printf("Outside Sum=%d\n", outsideSum);
    
    return 0;
}
