#include <stdio.h>
#include <stdlib.h>
#define INF 30000

///common print path code
void printMinPaths(int dist[], int V){
    printf("\nVertex \t\t Distance from Source\n");
    int i;
    for (i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

///following structures are for the Bellman Ford, it is better to implement in a dynamic graph manner
///as that is one of the plus points of Bellman Ford
struct Edge {
  int u;  //start vertex of the edge
  int v;  //end vertex of the edge
  int w;  //weight of the edge (u,v)
};

//Graph - it consists of edges
struct Graph {
  int V;        //total number of vertices in the graph
  int E;        //total number of edges in the graph
  struct Edge *edge;  //array of edges
};

void bellmanford(struct Graph **gIn, int source, int *ops) {
    int i,j;
    int V= (*gIn)->V;
    int E= (*gIn)->E;
    int dist[V];
    for(i=0;i<V;i++){
        //(*ops)++;
        dist[i]=__INT_MAX__;
    }
    dist[source]=0;
    for(i=0;i<V-1;i++){
        for(j=0;j<E;j++){
            (*ops)++;
            int u=(*gIn)->edge[j].u;
            int v=(*gIn)->edge[j].v;
            int weight =(*gIn)->edge[j].w;
            if(dist[u]!=__INT_MAX__ && dist[u]+weight<dist[v])
                dist[v]=dist[u]+weight;
        }
    }
    for(i=0;i<E;i++){
        (*ops)++;
        int u=(*gIn)->edge[i].u;
        int v=(*gIn)->edge[i].v;
        int weight=(*gIn)->edge[i].w;
        if(dist[u]!=__INT_MAX__ && dist[u]+weight < dist[v]){
            printf("**Negative weight cycle detected! **");
            return;
        }
    }
    printMinPaths(dist,V);
    return;
}

///Stuff for Dijkstra
//sureSet[i] will be 1 if vertex i is included in shortest
//path tree or shortest distance from src to i is finalized
int minDist(int dist[], int sureSet[], int V, int *ops){
    int min=__INT_MAX__,min_index;
    int i;
    for( i=0;i<V;i++){
        (*ops)++;
        if(sureSet[i]==0 && dist[i]<=min){
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}

//put the input adjacency graph printing code inside
void dijkstra(int* inGraph, int src, int V, int *ops){
    printf("The input graph is:\n\n");
    int a,b;
    for(a=0;a<V;a++){
        for(b=0;b<V;b++){
            printf("%d\t",inGraph[a*V+b]);
        }
        printf("\n");
    }
    printf("\n\n** Dijkstra **\n");
    int i;
    int dist[V];
    int sureset[V];
    for(i=0;i<V;i++){
        //(*ops)+=2;
        dist[i]=__INT_MAX__;
        sureset[i]=0;
    }
    dist[src]=0;
    int count;
    for(count=0;count<V;count++){
        int u=minDist(dist,sureset,V,ops);
        sureset[u]=1;
        for(i=0;i<V;i++){
            (*ops)++;
            if(!sureset[i] && inGraph[u*V+i] && dist[u]!=__INT_MAX__ && dist[u]+inGraph[u*V+i]<dist[i])
                dist[i]=dist[u]+inGraph[u*V+i];
        }
    }
    printMinPaths(dist,V);
}

///utility function for converting static graph to dynamic
///you may skip its use if you want, then change the input parameters to bellmanford function
struct Graph *convertGraph(int *inGraph, int V){
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    g->V = V;  //total vertices
    g->E = 0;  //total edges
    int i,j;
    for (i = 0; i < V; i++){
        for (j = 0; j < V; j++){
            if( (*((inGraph+i*V) + j)) != 0 )
                g->E = g->E + 1;
        }
    }
    //printf("\n G edges: %d",g->E);
    //array of edges for graph
    g->edge = (struct Edge *)malloc(g->E * sizeof(struct Edge));
    int edgeCounter=0;
    for (i = 0; i < V; i++){
        for (j = 0; j < V; j++){  ///seems weird but not including back edge may cause problem in bellman ford
            if( (*((inGraph+i*V) + j)) != 0 ){
                g->edge[edgeCounter].u = i;
                g->edge[edgeCounter].v = j;
                g->edge[edgeCounter].w = (*((inGraph+i*V) + j));
                //printf("\n %d -> %d : %d",g->edge[edgeCounter].u,g->edge[edgeCounter].v,g->edge[edgeCounter].w);
                edgeCounter++;
                //printf("\n edgeCounter: %d",edgeCounter);
            }
        }
    }
    return g;
}

int main(){
    int V=9;
    int graph[9][9] = { { 0, 28, 15, 0, 0, 0, 0, 8, 0 },
                        { 28, 0, 18, 0, 0, 0, 0, 16, 0 },
                        { 15, 18, 0, 9, 0, 4, 0, 0, 2 },
                        { 0, 0, 9, 0, 12, 14, 0, 0, 0 },
                        { 0, 0, 0, 12, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 16 },
                        { 8, 16, 0, 0, 0, 0, 1, 0, 19 },
                        { 0, 0, 2, 0, 0, 0, 16, 19, 0 } };
    int ops_d=0;
    int ops_bf=0;
    dijkstra((int*)graph, 0, V, &ops_d);
    printf("\n\n***** Number of ops: %d\n\n",ops_d);
    struct Graph *inGraph;
    inGraph = convertGraph((int*)graph,V);
    printf("\n\n**** Bellman Ford ****\n\n");
    bellmanford(&inGraph,0, &ops_bf);
    printf("\n\n***** Number of ops: %d\n\n",ops_bf);

    int V2=9;
    int graph2[9][9] = { { 0, 14, 10, 0, 0, 0, 0, 8, 0 },
                        { 14, 0, -18, 0, 0, 0, 0, 16, 0 },
                        { 10, -18, 0, 9, 0, 4, 0, 0, -2 },
                        { 0, 0, 9, 0, 12, 14, 0, 0, 0 },
                        { 0, 0, 0, 12, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, -16 },
                        { 8, 16, 0, 0, 0, 0, 1, 0, 17 },
                        { 0, 0, -2, 0, 0, 0, -16, 17, 0 } };
    int ops_d2=0;
    int ops_bf2=0;
    dijkstra((int*)graph2, 0, V2, &ops_d2);
    printf("\n\n***** Number of ops: %d\n\n",ops_d2);
    struct Graph *inGraph2;
    inGraph2 = convertGraph((int*)graph2,V2);
    printf("\n\n**** Bellman Ford ****\n\n");
    bellmanford(&inGraph2,0, &ops_bf2);
    printf("\n\n***** Number of ops: %d\n\n",ops_bf2);

    int V3=6;
    int graph3[6][6] = {
        {0,30,15,35,5,20},
        {30, 0, 15, 5, 35, 25},
        {15, 15, 0, 40, 30, 5},
        {35, 5, 40, 0, 25, 5},
        {5, 35, 30, 25, 0, 25},
        {20, 25, 5, 5, 25, 0}
        };
    int ops_d3=0;
    int ops_bf3=0;
    dijkstra((int*)graph3, 0, V3, &ops_d3);
    printf("\n\n***** Number of ops: %d\n\n",ops_d3);
    struct Graph *inGraph3;
    inGraph3 = convertGraph((int*)graph3,V3);
    printf("\n\n**** Bellman Ford ****\n\n");
    bellmanford(&inGraph3,0, &ops_bf3);
    printf("\n\n***** Number of ops: %d\n\n",ops_bf3);

    int V4=6;
    int graph4[6][6] = {
        {0,30,-15,35,5,20},
        {30, 0, -15, 5, 35, 25},
        {-15, -15, 0, 40, 30, 5},
        {35, 5, 40, 0, 25, 5},
        {5, 35, 30, 25, 0, 25},
        {20, 25, 5, 5, 25, 0}
        };
    int ops_d4=0;
    int ops_bf4=0;
    dijkstra((int*)graph4, 0, V4, &ops_d4);
    printf("\n\n***** Number of ops: %d\n\n",ops_d4);
    struct Graph *inGraph4;
    inGraph4 = convertGraph((int*)graph4,V4);
    printf("\n\n**** Bellman Ford ****\n\n");
    bellmanford(&inGraph4,0, &ops_bf4);
    printf("\n\n***** Number of ops: %d\n\n",ops_bf4);
    return 0;
}