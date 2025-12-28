/* 408CS15015
   EXPERIMENT – 07
   Check whether the given graph is connected using DFS
*/

#include <stdio.h>

#define SIZE 20
#define TRUE  1
#define FALSE 0

int g[SIZE][SIZE];
int visit[SIZE];
int n;

void create();
void DFS(int v);
int isConnected();

int main()
{
    int i, j;

    create();

    printf("\nThe adjacency matrix for the graph is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", g[i][j]);
        printf("\n");
    }

    for (i = 0; i < n; i++)
        visit[i] = FALSE;

    printf("\nDFS Traversal:\n");
    DFS(0);

    if (isConnected())
        printf("\n\nThe given graph is CONNECTED\n");
    else
        printf("\n\nThe given graph is NOT CONNECTED\n");

    return 0;
}

void create()
{
    int i, j, dist;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g[i][j] = 0;

    printf("\nEnter the distance between JPNAGAR and JAYANAGAR: ");
    scanf("%d", &dist);
    g[0][1] = g[1][0] = dist;

    printf("Enter the distance between JAYANAGAR and BTM: ");
    scanf("%d", &dist);
    g[1][2] = g[2][1] = dist;

    printf("Enter the distance between BTM and VVPURAM: ");
    scanf("%d", &dist);
    g[2][3] = g[3][2] = dist;

    printf("Enter the distance between VVPURAM and JAYANAGAR: ");
    scanf("%d", &dist);
    g[3][1] = g[1][3] = dist;

    printf("Enter the distance between BTM and JPNAGAR: ");
    scanf("%d", &dist);
    g[2][0] = g[0][2] = dist;
}

void DFS(int v)
{
    int i;

    visit[v] = TRUE;

    printf("Visited city: ");
    switch (v)
    {
        case 0: printf("JPNAGAR\n"); break;
        case 1: printf("JAYANAGAR\n"); break;
        case 2: printf("BTM\n"); break;
        case 3: printf("VVPURAM\n"); break;
        case 4: printf("KRPURAM\n"); break;
        default: printf("CITY %d\n", v);
    }

    for (i = 0; i < n; i++)
    {
        if (g[v][i] != 0 && visit[i] == FALSE)
            DFS(i);
    }
}

int isConnected()
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (visit[i] == FALSE)
            return 0;
    }
    return 1;
}
