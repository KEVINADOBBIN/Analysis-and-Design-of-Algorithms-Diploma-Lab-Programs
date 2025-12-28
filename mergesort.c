/* 408CS15015
   EXPERIMENT – 02

   Sort a given set of integer elements using Merge Sort method
   and compute the time taken for sorting.
*/

#include <stdio.h>
#include <time.h>

void mergesort(int A[], int low, int high);
void merge(int A[], int low, int mid, int high);
void display(int A[], int n);

int main()
{
    int i, n;
    int A[100];
    int low, high;
    clock_t start, end;
    double time_taken;

    printf("\nMerge Sort\n");
    printf("How many elements are there? ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    low = 0;
    high = n - 1;

    start = clock();
    mergesort(A, low, high);
    end = clock();

    display(A, n);

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime required = %f seconds\n", time_taken);

    return 0;
}

void mergesort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

void merge(int A[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int temp[100];

    while (i <= mid && j <= high)
    {
        if (A[i] <= A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }

    while (i <= mid)
        temp[k++] = A[i++];

    while (j <= high)
        temp[k++] = A[j++];

    for (i = low; i <= high; i++)
        A[i] = temp[i];
}

void display(int A[], int n)
{
    int i;
    printf("\nSorted elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", A[i]);
    printf("\n");
}
