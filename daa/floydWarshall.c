#include<stdio.h>
#define INF 300000

void floydWarshall (int* graph, int n, int *ops){
    int dist[n][n], i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = *((graph+i*n)+j);
        }
    }
    for (k = 0; k < n; k++){
        // Pick all vertices as source one by one
        for (i = 0; i < n; i++){
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < n; j++){
                (*ops)++;
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    // Print the shortest distance matrix
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int graph1[6][6] = {{0,10,15,INF,5,20},
                        {10, 0, 15, INF, INF, 25},
                        {15, 15, 0, 30, 30, 5},
                        {INF, INF, 30, 0, 25, 10},
                        {5, INF, 30, 25, 0, 35},
                        {20, 25, 5, 10, 35, 0}};
    int ops1=0;
    // Print the solution
    floydWarshall((int*)graph1,6,&ops1);
    printf("\nNumber of ops: %d\n\n",ops1);

    int graph2[4][4] = { { 0, 10, 15, 25 },
                        { 10, 0, 35, 25 },
                        { 15, 35, 0, 30 },
                        { 25, 25, 30, 0 } };
    int ops2=0;
    // Print the solution
    floydWarshall((int*)graph2,4,&ops2);
    printf("\nNumber of ops: %d\n\n",ops2);

    int graph3[4][4] = { {   0, 1, INF,  8 },
                        {   1, 0,   2,  3 },
                        { INF, 2,   0, 30 },
                        {   8, 3,  30,  0 } };
    int ops3=0;
    // Print the solution
    floydWarshall((int*)graph3,4,&ops3);
    printf("\nNumber of ops: %d\n\n",ops3);

    int graph4[5][5] = {{0, 5, 30, INF, 10},
                        {5, 0, 20, 5, INF},
                        {30, 20, 0, 20, 25},
                        {INF, 5, 20, 0, 15},
                        {10, INF, 25, 15, 0}};
    int ops4=0;
    // Print the solution
    floydWarshall((int*)graph4,5,&ops4);
    printf("\nNumber of ops: %d\n\n",ops4);
    return 0;
}
