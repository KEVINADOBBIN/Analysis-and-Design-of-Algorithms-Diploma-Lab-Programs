/* 408CS15015
   EXPERIMENT – 06
   Print all the nodes reachable from a given starting node
   in a digraph using BFS method
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define TRUE  1
#define FALSE 0

int g[SIZE][SIZE];
int visit[SIZE];
int Q[SIZE];
int front, rear;
int n;

void create();
void bfs(int start);

int main()
{
    int i, j, start;
    char ans = 'y';

    create();

    printf("\nThe adjacency matrix for the graph is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", g[i][j]);
        printf("\n");
    }

    do
    {
        for (i = 0; i < n; i++)
            visit[i] = FALSE;

        printf("\nEnter the vertex from which you want to traverse: ");
        scanf("%d", &start);

        if (start >= n)
            printf("Invalid vertex\n");
        else
        {
            printf("The Breadth First Search of the graph is:\n");
            bfs(start);
        }

        printf("\nDo you want to traverse from any other node? (y/n): ");
        scanf(" %c", &ans);

    } while (ans == 'y' || ans == 'Y');

    return 0;
}

void create()
{
    int i, j, v1, v2;
    char ans = 'y';

    printf("\nThis is a program to create a graph");
    printf("\nThe display is in breadth first manner");
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g[i][j] = FALSE;

    printf("\nEnter the vertices number starting from 0");

    do
    {
        printf("\nEnter the vertices v1 and v2: ");
        scanf("%d%d", &v1, &v2);

        if (v1 >= n || v2 >= n)
            printf("Invalid vertex value\n");
        else
        {
            g[v1][v2] = TRUE;
            g[v2][v1] = TRUE;
        }

        printf("Add more edges? (y/n): ");
        scanf(" %c", &ans);

    } while (ans == 'y' || ans == 'Y');
}

void bfs(int start)
{
    int i;
    front = rear = -1;

    visit[start] = TRUE;
    Q[++rear] = start;

    while (front != rear)
    {
        start = Q[++front];
        printf("%d ", start);

        for (i = 0; i < n; i++)
        {
            if (g[start][i] == TRUE && visit[i] == FALSE)
            {
                Q[++rear] = i;
                visit[i] = TRUE;
            }
        }
    }
    printf("\n");
}
