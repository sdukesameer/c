#include <stdio.h>
#include <stdlib.h>

typedef struct vertex{
    int idx;
    int degree;
}vertex;

///the complexity becomes O(V^2 + E) by using this, but for adjacency matrix input
///one has to check this anyway. To attain O(VlogV) complexity this has to be implemented
///as a hash map (quite complicated in C!)
int neighbourHasColor(int* graph, int currentVertex, int color, int vertexColor[], int V, int *ops){
    int hasColor=0;
    int i;
    for(i=0;i<V;i++){
        (*ops)++;
        if(*((graph+currentVertex*V) + i)){
            if(vertexColor[i]==color)
                hasColor=1;
        }
    }
    return hasColor;
}

void sorted_degree(int *graph , int V , int *ops , vertex arr[]){
	int i , j ;
	vertex temp;
	for(i = 0 ; i < V ; i++){
		arr[i].degree = 0;
		arr[i].idx = i;
        for(j = 0; j < V ; j++){
            if(*(graph + i*V +j)  !=0)
                arr[i].degree += 1;
        }
    }
    // A function to implement bubble sort
    for (i = 0; i < V-1; i++)
        // Last i elements are already in place
        for (j = 0; j < V-i-1; j++)
            if (arr[j].degree < arr[j+1].degree){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            for(i = 0 ; i < V ; i++)
                printf("%d - %d \t", arr[i].idx , arr[i].degree);
        printf("\n");
}

void colorGraph(int* graph, int V, int *ops){
        //keep the functions to make output uniform
    int i;
    printf("\n\nSorted degree\n");
    vertex arr[V];
    sorted_degree((int*)graph , V , ops , arr);
	int vertexColor[V];
	int color, count, j, flag;
	for(i = 0 ; i < V ; i++){
		vertexColor[i] = 0;
	    *ops += 1;
    }
    color  = 1;
    vertexColor[arr[0].idx] = color;
    for(i = 1 ; i < V ; i++){
		flag = 0;
        for(j = 0 ; j < color ; j++){
            if(neighbourHasColor((int*)graph, arr[i].idx,  j+1, vertexColor,  V, ops) == 0){
                vertexColor[arr[i].idx ] = j+1;
                flag = 1;
			}
			*ops += 1;
		}
        if(flag == 0)
            vertexColor[arr[i].idx] = ++color;
		*ops += 1;
	}
    printf("\n\nAssigned colors\n\n");
    printf("  ");
    for(i=0;i<V;i++){
        if(vertexColor[i] != 0)
            printf("%d ",vertexColor[i]);
    }
    printf("\n\n");
    for(i=0;i<V;i++){
        if(vertexColor[i] != 0){
            printf("%d ",vertexColor[i]);
            for(j=0;j<V;j++){
                if(*((graph+i*V) + j))
                    printf("X ");
                else
                    printf(". ");
            }
            printf("\n");
        }
    }
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
    int graph[9][9] = { { 0, 1, 0, 1, 1, 1, 0, 0, 0 },
                        { 1, 0, 0, 0, 0, 1, 1, 1, 0 },
                        { 0, 0, 0, 0, 0, 1, 1, 0, 0 },
                        { 1, 0, 0, 0, 0, 0, 0, 1, 0 },
                        { 1, 0, 0, 0, 0, 1, 0, 0, 1 },
                        { 1, 1, 1, 0, 1, 0, 1, 0, 1 },
                        { 0, 1, 1, 0, 0, 1, 0, 1, 1 },
                        { 0, 1, 0, 1, 0, 0, 1, 0, 1 },
                        { 0, 0, 0, 0, 1, 1, 1, 1, 0 },};
    int V=9;
    int ops=0;
    printGraph((int*)graph, V);
    colorGraph((int*)graph, V, &ops);
    printf("\n\n*** number of ops: %d",ops);


    int graph2[5][5] = { {0, 1, 0, 0, 1},
                        { 1, 0, 1, 0, 0},
                        { 0, 1, 0, 1, 0},
                        { 0, 0, 1, 0, 1},
                        { 1, 0, 0, 1, 0}
                        };
    int V2=5;
    int ops2=0;
    printGraph((int*)graph2, V2);
    colorGraph((int*)graph2, V2, &ops2);
    printf("\n\n*** number of ops: %d",ops2);

    int graph3[4][4] = { {0, 1, 0, 1},
                        { 1, 0, 1, 0},
                        { 0, 1, 0, 1},
                        { 1, 0, 1, 0}
                        };
    int V3=4;
    int ops3=0;
    printGraph((int*)graph3, V3);
    colorGraph((int*)graph3, V3, &ops3);
    printf("\n\n*** number of ops: %d",ops3);

    int graph4[5][5] = { {0, 0, 1, 1, 1},
                        { 0, 0, 1, 1, 1},
                        { 1, 1, 0, 0, 0},
                        { 1, 1, 0, 0, 0},
                        { 1, 1, 0, 0, 0}
                        };
    int V4=5;
    int ops4=0;
    printGraph((int*)graph4, V4);
    colorGraph((int*)graph4, V4, &ops4);
    printf("\n\n*** number of ops: %d",ops4);

    int graph5[5][5] = { {0, 1, 1, 1, 1},
                        { 1, 0, 1, 1, 1},
                        { 1, 1, 0, 1, 1},
                        { 1, 1, 1, 0, 1},
                        { 1, 1, 1, 1, 0}
                        };
    int V5=5;
    int ops5=0;
    printGraph((int*)graph5, V5);
    colorGraph((int*)graph5, V5, &ops5);
    printf("\n\n*** number of ops: %d",ops5);

    return 0;
}
