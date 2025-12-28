/* Reg No: 408CS15015
   EXPERIMENT – 11
   Shortest Path using Dijkstra's Algorithm
*/

#include <stdio.h>

#define MAX 10
#define INFINITY 999

int cost[MAX][MAX], dist[MAX], visited[MAX], path[MAX];
int nodes;

void create_graph();
void dijkstra(int source);
void display_path(int source, int destination);

int main()
{
    int source, i;

    printf("\nCreation of Graph\n");
    create_graph();

    for (source = 0; source < nodes; source++)
    {
        printf("\n\nWhen source = %d\n", source);
        dijkstra(source);

        for (i = 0; i < nodes; i++)
        {
            if (i != source)
                display_path(source, i);
        }
    }
    return 0;
}

void create_graph()
{
    int edges, i, j, v1, v2, w;

    printf("Enter total number of nodes: ");
    scanf("%d", &nodes);

    for (i = 0; i < nodes; i++)
        for (j = 0; j < nodes; j++)
            cost[i][j] = (i == j) ? 0 : INFINITY;

    printf("Enter total number of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++)
    {
        printf("Enter v1 v2 and cost: ");
        scanf("%d %d %d", &v1, &v2, &w);
        cost[v1][v2] = w;
        cost[v2][v1] = w;
    }
}

void dijkstra(int source)
{
    int i, j, min, u;

    for (i = 0; i < nodes; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
        path[i] = source;
    }

    dist[source] = 0;
    visited[source] = 1;

    for (i = 1; i < nodes; i++)
    {
        min = INFINITY;
        u = -1;

        for (j = 0; j < nodes; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1) return;

        visited[u] = 1;

        for (j = 0; j < nodes; j++)
        {
            if (!visited[j] && dist[u] + cost[u][j] < dist[j])
            {
                dist[j] = dist[u] + cost[u][j];
                path[j] = u;
            }
        }
    }
}

void display_path(int source, int destination)
{
    int i = destination;

    printf("\nStep by step shortest path is...\n");

    while (i != source)
    {
        printf("%d <- ", i);
        i = path[i];
    }
    printf("%d", source);

    printf("\nThe length = %d\n", dist[destination]);
}
