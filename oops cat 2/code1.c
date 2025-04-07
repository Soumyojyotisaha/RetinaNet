#include <stdio.h>

int main() {
    // Declare necessary variables
    int n, count = 0, max_len = 0, cur_len = 1;
    
    // Read the number of elements in the array
    scanf("%d", &n);
    int arr[n];
    
    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Iterate through the array to identify segments
    for (int i = 1; i < n; i++) {
        // If the current element is greater than the previous one, extend the segment
        if (arr[i] > arr[i - 1]) {
            cur_len++;
        } else {
            // If the segment ends, increment the segment count
            count++;
            
            // Update the maximum segment length if the current segment is the longest
            if (cur_len > max_len) {
                max_len = cur_len;
            }
            
            // Reset the current segment length for a new segment
            cur_len = 1;
        }
    }
    
    // Count the last segment
    count++;
    
    // Final check for the longest segment length
    if (cur_len > max_len) {
        max_len = cur_len;
    }
    
    // Print the results with proper statements
    printf("Total valid segments: %d\n", count);
    printf("Length of the longest segment: %d\n", max_len);
    
    return 0;
}