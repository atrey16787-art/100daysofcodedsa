#include <stdio.h>
#include <string.h>

// Recursive function to print string in reverse
void mirror(char str[], int index)
{
    // Base case
    if (index < 0)
        return;

    // Print current character
    printf("%c", str[index]);

    // Recursive call
    mirror(str, index - 1);
}

int main()
{
    char str[100];

    // Input
    printf("Enter the code name: ");
    scanf("%s", str);

    int length = strlen(str);

    // Output
    mirror(str, length - 1);

    return 0;
}