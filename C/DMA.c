// Dynamic Allocation in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // -------------------- malloc example --------------------
    int *ptr = (int*)malloc(100 * sizeof(int)); // allocate memory for 100 integers
    printf("%d", ptr[0]); // Prints garbage value (malloc does not initialize memory)
    printf("\n");

    // -------------------- calloc example --------------------
    int *ptr_calloc = (int*)calloc(100, sizeof(int)); // allocate and initialize to 0
    printf("%d \n", ptr_calloc[0]); // Prints 0

    // -------------------- malloc for user input --------------------
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("You entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);  // Free dynamically allocated memory
    arr = NULL; // Avoid dangling pointer

    // -------------------- realloc example --------------------
    int *realloc_ptr = (int*)malloc(5 * sizeof(int));
    if (realloc_ptr == NULL) {
        printf("Initial memory allocation failed\n");
        return 1;
    }

    printf("Initial memory allocated for 5 integers.\n");

    realloc_ptr = (int*)realloc(realloc_ptr, 10 * sizeof(int)); // resize to 10 integers
    if (realloc_ptr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    printf("Memory successfully reallocated for 10 integers.\n");

    free(realloc_ptr); // free reallocated memory
    realloc_ptr = NULL;

    // -------------------- free malloc/calloc pointers --------------------
    free(ptr);
    free(ptr_calloc);
    ptr = NULL;
    ptr_calloc = NULL;

    return 0;
}
