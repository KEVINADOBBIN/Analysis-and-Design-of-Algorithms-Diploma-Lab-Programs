/* 408CS15015
   Experiment – 03
   Obtain the topological ordering of vertices in a given digraph
*/

#include <stdio.h>

#define TRUE  1
#define FALSE 0

int main()
{
    int i, j, k;
    int n = 4;
    int a[10][10], in[10], visit[10];
    int count = 0;

    printf("\nTopological Sorting\n");

    /* Initialize adjacency matrix */
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            a[i][j] = 0;

    /* Create graph */
    printf("\nGraph is created as follows:");
    printf("\nThe node '0' and '1' are connected");
    a[0][1] = 1;

    printf("\nThe node '0' and '2' are connected");
    a[0][2] = 1;

    printf("\nThe node '3' and '2' are connected");
    a[3][2] = 1;

    /* Initialize in-degree and visited array */
    for (i = 0; i < n; i++)
    {
        in[i] = 0;
        visit[i] = FALSE;
    }

    /* Calculate in-degree of each vertex */
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            in[i] = in[i] + a[j][i];

    printf("\n\nThe topological order is: ");

    while (count < n)
    {
        for (k = 0; k < n; k++)
        {
            if (in[k] == 0 && visit[k] == FALSE)
            {
                printf("%d ", k);
                visit[k] = TRUE;

                /* Remove outgoing edges */
                for (i = 0; i < n; i++)
                {
                    if (a[k][i] == 1)
                        in[i]--;
                }
                count++;
            }
        }
    }

    return 0;
}
