#include <stdio.h>

// Recursive function to find nth Fibonacci number
int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;

    // Input statement with message
    printf("Enter a number: ");
    scanf("%d", &n);

    // Output
    printf("The %d-th Fibonacci number is: %d", n, fib(n));

    return 0;
}