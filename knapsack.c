#include <stdio.h>

int main()
{
    int p[20], w[20], kn[20][100], x[20];
    int i, j, n, weight;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the price/value of each item:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter the weight of each item:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("Enter the maximum weight of the knapsack: ");
    scanf("%d", &weight);

    // Initialize the DP table
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= weight; j++)
        {
            if (i == 0 || j == 0)
                kn[i][j] = 0;
            else if (w[i - 1] > j)
                kn[i][j] = kn[i - 1][j];
            else
            {
                int include = kn[i - 1][j - w[i - 1]] + p[i - 1];
                int exclude = kn[i - 1][j];
                kn[i][j] = (include > exclude) ? include : exclude;
            }
        }
    }

    printf("\nOptimal solution (maximum profit) = %d\n", kn[n][weight]);

    // Backtracking to find items included in knapsack
    i = n;
    j = weight;
    while (i > 0)
    {
        if (kn[i][j] != kn[i - 1][j])
        {
            x[i - 1] = 1; // Item included
            j -= w[i - 1];
        }
        else
        {
            x[i - 1] = 0; // Item not included
        }
        i--;
    }

    printf("Items included in the knapsack:\n");
    for (i = 0; i < n; i++)
        printf("Item %d: %s\n", i + 1, x[i] ? "Included" : "Not included");

    return 0;
}
