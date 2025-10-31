#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    arr = (int *)malloc(5 * sizeof(int));

    if (arr == NULL) // Always good to check if malloc succeeded
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]); // Correct way to read input
    }

    printf("You entered: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // Free the dynamically allocated memory
    return 0;
}
