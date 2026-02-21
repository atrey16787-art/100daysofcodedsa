#include <stdio.h>

int main() {
    int n;
    
    // Input size
    scanf("%d", &n);
    
    int matrix[n][n];
    
    // Input matrix elements
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int isIdentity = 1;
    
    // Check identity condition
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            
            // Diagonal elements must be 1
            if(i == j && matrix[i][j] != 1) {
                isIdentity = 0;
                break;
            }
            
            // Non-diagonal elements must be 0
            if(i != j && matrix[i][j] != 0) {
                isIdentity = 0;
                break;
            }
        }
        if(isIdentity == 0)
            break;
    }
    
    // Output result
    if(isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");
    
    return 0;
}