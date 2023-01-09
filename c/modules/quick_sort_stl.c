#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 6

int comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main() {
    int arr[] = {3, 5, 6, 1, 8, 0};
    
    printf("Befor Qsort\n");
    for(int i=0; i<MAX_SIZE; ++i) {
        printf("%d ",arr[i]);
    }
    printf("\n");

    qsort(arr, MAX_SIZE, sizeof(int), comp);

    printf("After Qsort\n");
    for(int i=0; i<MAX_SIZE; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
