/* 408CS15015
   EXPERIMENT – 08
   Implement Binary Search using Divide and Conquer technique
*/

#include <stdio.h>

#define SIZE 10

int Binsearch(int A[], int n, int key);

int main()
{
    int A[SIZE], key, i, n, pos;

    printf("How many elements in the array? ");
    scanf("%d", &n);

    printf("Enter %d elements in sorted order:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    pos = Binsearch(A, n, key);

    if (pos == -1)
        printf("The element is not present\n");
    else
        printf("The element is at A[%d] location\n", pos);

    return 0;
}

int Binsearch(int A[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
