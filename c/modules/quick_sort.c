#include <stdio.h>


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for(int j=low; j<=high - 1; ++j) {
        if(arr[j] < pivot) {
            printf("j: %d, arr[j]: %d, pivot: %d\n", j, arr[j], pivot);
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    printf("i: %d, high: %d, arr[i]: %d, arr[high]: %d\n",i, high, arr[i], arr[high]);
    swap(&arr[i], &arr[high]);
    return i;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high) {
        printf("low: %d, high: %d\n", low, high);
        int pivot = partition(arr, low, high);
        printf("arr: %d, %d\n",arr[0], arr[1]);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

#define MAX_SIZE 2

int main()
{
    int i = 0;
    // int list[MAX_SIZE] = {4, 5, 6, 9, 3, 2, 1, 8, 7, 0};
    int size = 2;
    int list[MAX_SIZE] = {2,3};

    quickSort(list, 0, MAX_SIZE-1);

    for(int i=0; i<MAX_SIZE; ++i) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}
