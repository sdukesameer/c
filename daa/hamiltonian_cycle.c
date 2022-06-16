#include<stdlib.h>
#include<stdio.h>

void printCycle(int pathVertices[], int V){
    printf ("The following Hamiltonian cycle is found: \n");
    for (int i = 0; i < V; i++)
        printf("%d -> ", pathVertices[i]);
    printf("%d ", pathVertices[0]);
    printf("\n");
}

///check whether checkV can be chosen provided the path pos-1 -> checkV exists
///and checkV is not in the pathVertices already
///use a marker say -1 (as node starts from 0) to designate no node is in position
///index of path
int checkSelection(int* graph, int V, int checkV, int pathVertices[], int pos){
    /* Check if this vertex is an adjacent vertex of the previously
        added vertex. */
    if (*((graph+V*pathVertices[pos-1])+checkV) == 0)
        return 0;
    /* Check if the vertex has already been included.
        This step can be optimized by creating an array of size V */
    for (int i = 0; i < pos; i++)
        if (pathVertices[i] == checkV)
            return 0;
    return 1;
}

///tries to add new path to pathVerices using checkSelection on different vertices
///If returns true or 1 if pos is V that is all vertices are covered and the last vertex
///is connected to the first. Else it checks all vertices to add in path, if it can be
///added then it calls itself recursively with next position returns the output else
///it removes the position as deadend is reached
int nextValueFound(int* graph, int V, int pathVertices[], int pos){
        /* base case: If all vertices are included in Hamiltonian Cycle */
    if (pos == V){
        // And if there is an edge from the last included vertex to the
        // first vertex
        if (*((graph+V*pathVertices[pos-1])+pathVertices[0]) == 1 )
            return 1;
        else
            return 0;
    }
    // Try different vertices as a next candidate in Hamiltonian Cycle.
    // We don't try for 0 as we included 0 as starting point in hamCycle()
    for (int v = 1; v < V; v++){
        /* Check if this vertex can be added to Hamiltonian Cycle */
        if (checkSelection(graph,V,v, pathVertices, pos)){
            pathVertices[pos] = v;
            /* recur to construct rest of the path */
            if (nextValueFound (graph,V,pathVertices, pos+1) == 1)
                return 1;
            /* If adding vertex v doesn't lead to a solution,
                then remove it */
            pathVertices[pos] = -1;
        }
    }
    /* If no vertex can be added to Hamiltonian Cycle constructed so far,
        then return false */
    return 0;
}

///This function solves the Hamiltonian Cycle problem using Backtracking.
///mainly nextValueFound is used. It will return 0 if no hamiltonian cycle
///is possible, but that is printed internally as well. It returns 1 and
///calls the printCycle function if a path is found
int hamiltonianCycle(int* graph, int V){
    int path[V];
    //int *path = new int[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
    /* Let us put vertex 0 as the first vertex in the path. If there is
        a Hamiltonian Cycle, then the path can be started from any point
        of the cycle as the graph is undirected */
    path[0] = 0;
    if ( nextValueFound(graph,V, path, 1) == 0 ){
        printf("\nNo Hamiltonian cycle exists!");
        return 0;
    }
    printCycle(path,V);
    return 1;
}

void printGraph(int* graph, int V){
    printf("\nInput Graph is\n\n");
    int i,j;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            printf("%3d",*((graph+i*V) + j));
        }
        printf("\n");
    }
    printf("\n\n");
}

int main(){
    int graph1[6][6] = {{0, 1, 0, 1, 1, 0},
                        {1, 0, 1, 0, 1, 0},
                        {0, 1, 0, 0, 1, 0},
                        {1, 0, 0, 0, 0, 1},
                        {1, 1, 1, 0, 0 ,1},
                        {0, 0, 0, 1, 1 ,0}};
    printGraph((int*)graph1,6);
    hamiltonianCycle((int*)graph1,6);

    int graph2[6][6] = {{0, 1, 0, 0, 1, 0},
                        {1, 0, 1, 0, 1, 0},
                        {0, 1, 0, 0, 1, 0},
                        {0, 0, 0, 0, 1, 1},
                        {1, 1, 1, 1, 0 ,1},
                        {0, 0, 0, 1, 1 ,0}};
    printGraph((int*)graph2,6);
    hamiltonianCycle((int*)graph2,6);

    int graph3[9][9] = {{0,0,0,0,0,0,0,1,1},
                        {0,0,0,0,1,0,0,0,1},
                        {0,0,0,1,1,0,0,0,0},
                        {0,0,1,0,1,1,0,0,0},
                        {0,1,1,1,0,1,0,0,1},
                        {0,0,0,1,1,0,1,0,1},
                        {0,0,0,0,0,1,0,1,1},
                        {1,0,0,0,0,0,1,0,1},
                        {1,1,0,0,1,1,1,1,0}};
    printGraph((int*)graph3,9);
    hamiltonianCycle((int*)graph3,9);

    int graph4[9][9] = {{0,0,0,0,0,0,0,0,1},
                        {0,0,0,0,0,0,0,0,1},
                        {0,0,0,1,1,0,0,0,0},
                        {0,0,1,0,1,1,0,0,0},
                        {0,0,1,1,0,1,0,0,1},
                        {0,0,0,1,1,0,1,0,1},
                        {0,0,0,0,0,1,0,1,1},
                        {0,0,0,0,0,0,1,0,1},
                        {1,1,0,0,1,1,1,1,0}};
    printGraph((int*)graph4,9);
    hamiltonianCycle((int*)graph4,9);

    return 0;
}