/* 408CS150153
   EXPERIMENT – 04
   Implement Travelling Salesman Problem
*/

#include <stdio.h>

#define MAX 10

typedef struct
{
    int nodes[MAX];
    int vertex;
    int min;
} path_nodes;

/* Function Prototype */
path_nodes TSP(int source, path_nodes list, int cost[MAX][MAX], int n);

/* Display Function */
void display(path_nodes path)
{
    int i;
    printf("\nThe minimum cost is %d\n", path.min);
    printf("The path is: ");
    for (i = 0; i < path.vertex; i++)
        printf("%d -> ", path.nodes[i]);
    printf("%d\n", path.nodes[0]);
}

/* TSP Recursive Function */
path_nodes TSP(int source, path_nodes list, int cost[MAX][MAX], int n)
{
    int i, j;
    path_nodes new_list, new_path, best_path;

    if (list.vertex == 0)
    {
        best_path.min = cost[source][0];
        best_path.nodes[n - 1] = source;
        best_path.vertex = n;
        return best_path;
    }

    for (i = 0; i < list.vertex; i++)
    {
        new_list.vertex = 0;
        for (j = 0; j < list.vertex; j++)
        {
            if (i != j)
                new_list.nodes[new_list.vertex++] = list.nodes[j];
        }

        new_path = TSP(list.nodes[i], new_list, cost, n);
        new_path.min += cost[source][list.nodes[i]];
        new_path.nodes[n - list.vertex - 1] = source;

        if (i == 0 || new_path.min < best_path.min)
            best_path = new_path;
    }
    return best_path;
}

int main()
{
    int i, j, n;
    int cost[MAX][MAX];
    path_nodes graph, result;

    printf("How many cities are there? ");
    scanf("%d", &n);

    if (n <= 1)
    {
        printf("Error: Not enough cities to process TSP.\n");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                cost[i][j] = 0;
            else
            {
                printf("Enter distance from city %d to %d: ", i + 1, j + 1);
                scanf("%d", &cost[i][j]);
            }
        }
    }

    graph.vertex = n - 1;
    for (i = 1; i < n; i++)
        graph.nodes[i - 1] = i;

    result = TSP(0, graph, cost, n);
    display(result);

    return 0;
}
