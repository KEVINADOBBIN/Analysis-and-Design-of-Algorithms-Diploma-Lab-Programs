#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void quick(int A[], int low, int high);
int partition(int A[], int low, int high);
void swap(int A[], int i, int j);

int main()
{
    int i, n;
    int A[SIZE];
    clock_t start, end;
    double time_taken;

    printf("Sorting using Quick Sort\n");
    printf("Enter the total number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    start = clock();
    quick(A, 0, n - 1);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", A[i]);

    printf("\n\nTime taken to sort = %f seconds\n", time_taken);

    return 0;
}

void quick(int A[], int low, int high)
{
    int m;
    if (low < high)
    {
        m = partition(A, low, high);
        quick(A, low, m - 1);
        quick(A, m + 1, high);
    }
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high && A[i] <= pivot)
            i++;
        while (A[j] > pivot)
            j--;
        if (i < j)
            swap(A, i, j);
    }
    swap(A, low, j);
    return j;
}

void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
