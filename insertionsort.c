/* 408CS15015
   EXPERIMENT – 09
   Implement Insertion Sort using Decrease and Conquer technique
*/

#include <stdio.h>

void Insert_sort(int A[], int n);

int main()
{
    int A[10], n, i;

    printf("\nInsertion Sort\n");
    printf("How many elements are there? ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    Insert_sort(A, n);

    return 0;
}

void Insert_sort(int A[], int n)
{
    int i, j, temp;

    for (i = 1; i < n; i++)
    {
        temp = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > temp)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }

    printf("\nThe sorted list of elements is:\n");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
