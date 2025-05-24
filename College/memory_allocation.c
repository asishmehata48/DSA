#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr_malloc, *ptr_calloc, *ptr_realloc;
    int n = 5, i;

    // malloc: allocates memory (uninitialized)
    ptr_malloc = (int *)malloc(n * sizeof(int));
    if (ptr_malloc == NULL) {
        printf("Memory allocation failed using malloc.\n");
        return 1;
    }

    // calloc: allocates memory (initialized to zero)
    ptr_calloc = (int *)calloc(n, sizeof(int));
    if (ptr_calloc == NULL) {
        printf("Memory allocation failed using calloc.\n");
        return 1;
    }

    // Display malloc memory (uninitialized)
    printf("\nMemory allocated using malloc (%d integers):\n", n);
    for (i = 0; i < n; i++) {
        printf("ptr_malloc[%d] = %d\n", i, ptr_malloc[i]); // garbage values
    }

    // Display calloc memory (initialized to 0)
    printf("\nMemory allocated using calloc (%d integers):\n", n);
    for (i = 0; i < n; i++) {
        printf("ptr_calloc[%d] = %d\n", i, ptr_calloc[i]);
    }

    // Change size of malloc memory using realloc
    int new_size = 8;
    ptr_realloc = (int *)realloc(ptr_malloc, new_size * sizeof(int));
    if (ptr_realloc == NULL) {
        printf("Memory reallocation failed.\n");
        free(ptr_malloc); // Free original block if realloc fails
        return 1;
    }
    ptr_malloc = ptr_realloc;

    // Fill new elements with values
    for (i = n; i < new_size; i++) {
        ptr_malloc[i] = i * 10;
    }

    // Display reallocated memory
    printf("\nReallocated memory using realloc (%d integers):\n", new_size);
    for (i = 0; i < new_size; i++) {
        printf("ptr_malloc[%d] = %d\n", i, ptr_malloc[i]);
    }

    // Free memory
    free(ptr_malloc);
    free(ptr_calloc);

    printf("\nMemory has been freed successfully.\n");

    return 0;
}
