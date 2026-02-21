#include <stdio.h>

int main() {
    int r, c;
    
    // Input rows and columns
    scanf("%d %d", &r, &c);
    
    int matrix[r][c];
    
    // Input matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;
    
    // Spiral traversal
    while(top <= bottom && left <= right) {
        
        // Traverse top row (left → right)
        for(int j = left; j <= right; j++) {
            printf("%d ", matrix[top][j]);
        }
        top++;
        
        // Traverse right column (top → bottom)
        for(int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;
        
        // Traverse bottom row (right → left)
        if(top <= bottom) {
            for(int j = right; j >= left; j--) {
                printf("%d ", matrix[bottom][j]);
            }
            bottom--;
        }
        
        // Traverse left column (bottom → top)
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
    
    return 0;
}