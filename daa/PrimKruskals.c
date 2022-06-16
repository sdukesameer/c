#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 30000

int minKey(int keySet[], int mstSet[], int V, int *ops){
    // Initialize min value
    int min = INT_MAX, min_index;
    int v;
    for (v = 0; v < V; v++){
        (*ops)++;
        if (mstSet[v] == 0 && keySet[v] < min){
            min = keySet[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int *graph, int V, int *ops){
    int select_V[V], value[V], parent[V], i, j, minCost = 0;
    for (i = 0; i < V; i++){
        select_V[i] = 0;
        value[i] = INT_MAX;
        *ops += 1;
    }
    value[0] = 0, parent[0] = -1;
    for (i = 0; i < V - 1; i++){
        int u = minKey(value, select_V, V, ops);
        select_V[u] = 1;
        *ops += 1;
        for (j = 0; j < V; j++){
            if (*((graph + u * V) + j) != 0 && select_V[j] == 0 && *((graph + u * V) + j) < value[j]){
                parent[j] = u, value[j] = *((graph + V * u) + j);
                *ops += 1;
            }
        }
    }
    printf("Edge \tWeight\n");
    for (i = 1; i < V; i++){
        printf("\n%d ----- %d \t%d \n", parent[i], i, *(graph + i * V + parent[i]));
        minCost += *(graph + i * V + parent[i]);
    }
    printf("Minimum cost = %d \n", minCost);
}

int find(int subsets[], int i, int *ops){
    // find root and make root as parent of i
    // (path compression)
    if (subsets[i] != i)
        subsets[i] = find(subsets, subsets[i], ops);
    *ops += 1;
    return subsets[i];
}

typedef struct Edge{
    int src, dest, weight;
}Edge;

void swap(Edge *a, Edge *b){
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Edge value[], int low, int high){
    int pivot = value[high].weight;
    int i = low - 1, j;
    for (j = low; j < high; j++){
        if (value[j].weight < pivot){
            i++;
            swap(&value[i], &value[j]);
        }
    }
    swap(&value[i + 1], &value[high]);
    return i + 1;
}

void QuickSort(Edge value[], int low, int high){
    if (high > low){
        int pi = partition(value, low, high);
        QuickSort(value, low, pi - 1);
        QuickSort(value, pi + 1, high);
    }
}

//One can store edge as i*V+j in one dimension, nodes are just indices
void unionSet(int A[], int *A_size, int newItem){
    int i;
    int isPresent = 0;
    for (i = 0; i < (*A_size); i++){
        if (A[i] == newItem)
            isPresent = 1;
    }
    if (!isPresent){
        A[(*A_size)] = newItem;
        (*A_size)++;
    }
}

void Union(int subset[], int x, int y, int *ops){
    int a = find(subset, x, ops);
    int b = find(subset, y, ops);
    *ops += 1;
    subset[a] = b;
}

void kruskalMST(int *graph, int V, int *ops){
    int cost = 0, i, j, e = 0, c = 0, count = 0;
    int subset[V], result[V - 1];
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            if (*(graph + i * V + j) != 0)
                e++;
    Edge edge[e];
    int edgeCounter = 0;
    for (i = 0; i < V; i++){
        for (j = 0; j < V; j++){
            if ((*((graph + i * V) + j)) != 0){
                edge[edgeCounter].src = i;
                edge[edgeCounter].dest = j;
                edge[edgeCounter].weight = (*((graph + i * V) + j));
                *ops += 1;
                edgeCounter++;
            }
        }
    }
    QuickSort(edge, 0, e - 1);
    for (i = 0; i < V; i++)
        subset[i] = i;
    i = 0;
    while (count < V - 1 && i < e){
        Edge e = edge[i++];
        int x = find(subset, e.src, ops);
        int y = find(subset, e.dest, ops);
        *(ops) += 1;
        if (x != y){
            result[c++] = i - 1;
            Union(subset, x, y, ops);
        }
    }
    printf("Edge \t weight \n ");
    for (i = 0; i < V - 1; i++){
        printf("\n %d --- %d    %d  \n", edge[result[i]].src, edge[result[i]].dest, edge[result[i]].weight);
        cost += edge[result[i]].weight;
    }
    printf("Minimum cost = %d", cost);
}

void printGraph(int *graph, int V){
    printf("\n\nInput Graph is:\n\n");
    int i, j;
    for (i = 0; i < V; i++){
        for (j = 0; j < V; j++)
            printf("%6d", *((graph + i * V) + j));
        printf("\n");
    }
    printf("\n\n");
}

int main(){
    int graph[9][9] = {{0, 28, 15, 0, 0, 0, 0, 8, 0},
                        {28, 0, 18, 0, 0, 0, 0, 16, 0},
                        {15, 18, 0, 9, 0, 4, 0, 0, 2},
                        {0, 0, 9, 0, 12, 14, 0, 0, 0},
                        {0, 0, 0, 12, 0, 10, 0, 0, 0},
                        {0, 0, 4, 14, 10, 0, 2, 0, 0},
                        {0, 0, 0, 0, 0, 2, 0, 1, 16},
                        {8, 16, 0, 0, 0, 0, 1, 0, 19},
                        {0, 0, 2, 0, 0, 0, 16, 19, 0}};
    int V = 9, ops_p = 0, ops_k = 0;
    printGraph((int *)graph, V);
    primMST((int *)graph, V, &ops_p);
    printf("\n** Number of Ops Prims: %d\n\n", ops_p);
    kruskalMST((int *)graph, V, &ops_k);
    printf("\n** Number of Ops Kruskals: %d\n\n", ops_k);

    int graph2[6][6] = {{0, 30, 15, 35, 5, 20},
                        {30, 0, 15, 5, 35, 25},
                        {15, 15, 0, 40, 30, 5},
                        {35, 5, 40, 0, 25, 5},
                        {5, 35, 30, 25, 0, 25},
                        {20, 25, 5, 5, 25, 0}};
    int V2 = 6, ops_p2 = 0, ops_k2 = 0;
    printGraph((int *)graph2, V2);
    primMST((int *)graph2, V2, &ops_p2);
    printf("\n** Number of Ops Prims: %d\n\n", ops_p2);
    kruskalMST((int *)graph2, V2, &ops_k2);
    printf("\n** Number of Ops Kruskals: %d\n\n", ops_k2);

    return 0;
}