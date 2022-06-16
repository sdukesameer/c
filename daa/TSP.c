#include<stdio.h>
#include<limits.h>
#include<string.h>
#define INF 300000

void printGraph(int* graph, int n){
	int i,j;
	for (i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            if(graph[i*n +j] == INF)
                printf("%s\t", "INF");
			else
                printf ("%d\t", graph[i*n +j]);
		printf("\n");
	}
}

void printPath(int subset, int start, int* last, int n){
	//if the subset is not empty
	if(subset){
		printPath(subset ^ (1 <<(start-1)), last[subset*n + start], last, n);
		printf("(%d) -> ", start);
	}
}

int tspCost(int* graph, int n, int *ops){ // take start city by dfault to 0
	printf("\n\nThe input graph is:\n");
	printGraph((int*)graph, n);
	int dp[(1<<10)+5][10]; // A DP table using bit mask, maximum allowed nodes is 10
	int last[(1<<10)+5][10];
	// create a local map same as graph, it will be easier
	int map[n][n];
	int i, j, ans, k, S_j, start;
	//now update the path with floyd warshal distances between pairs
	for (i = 0; i < n;i++)
        for (j = 0; j < n; j++)
            map[i][j] = (i == j)? 0 : graph[i*n + j];
	memset(dp, 9999999,sizeof(dp));
	// iteracing through all the possibilities starting from i = (1)2 to (1111...1)2(n-1 number of 1s
	for (i = 1; i < (1<<(n-1)); i++)
	    // iteracing through all the nodes for the last visited
        for (j = 0; j < n-1; j++){
    	    // j does not belong to the set i
			if (!(i & 1<<j))
                continue;
			// try all possibilities for the vertex in set i,
			// pick the best among them
			// if the size of the subset is 2, that is, when there is only (n-1) ans (j),
			// i represents here a set with only single element that is vertex (j) itself
			if (i == 1 << j){
				dp[i][j+1] = map[0][j+1];
				last[i][j+1] = j+1;
			}
			else{
				S_j = i ^ (1<<j);
				last[i][j+1] = -1;
				for (k = 0; k < n-1; k++){
					(*ops)++;
					if (!(S_j & 1<<k))
						continue;
					if (dp[S_j][k+1] + map[k+1][j+1] < dp[i][j+1]){
						dp[i][j+1] = dp[S_j][k+1] + map[k+1][j+1];
						last[i][j+1] = k+1;
					}
				}
			}
		}
	ans = INT_MAX;
	start = -1;
	for (i = 0; i<n-1;i++)
		if(map[i+1][0] + dp[ (1<<(n-1))-1][i+1] < ans){
			ans = map[i+1][0] + dp[(1<<(n-1))-1][i+1];
			start = i+1;
		}
	printf("\nThe path for the TSP is (starting from %d):\n",0);
	printf("(%d) ->",0);
	printPath((1<<(n-1))-1, start , (int*)last, 10);
	printf("(%d)\n",0);
	return ans;
}

//Driver code
int main(){
    int n=4;
    int map[4][4] = { { 0, 10, 15, 25 },
                    { 10, 0, 35, 25 },
                    { 15, 35, 0, 30 },
                    { 25, 25, 30, 0 } };
	int ops1=0;
	int cycCost= tspCost((int*)map, n, &ops1);
	printf("\nThe TSP cycle cost is %d\nThe number of ops is %d\n",cycCost,ops1);
	
	int n2=6;
	int map2[6][6] = {{0,10,15,INF,5,20},
					{10, 0, 15, INF, INF, 25},
					{15, 15, 0, 30, 30, 5},
					{INF, INF, 30, 0, 25, 10},
					{5, INF, 30, 25, 0, 35},
					{20, 25, 5, 10, 35, 0}};
	int ops2=0;
	int cycCost2= tspCost((int*)map2, n2, &ops2);
	printf("\nThe TSP cycle cost is %d\nThe number of ops is %d\n",cycCost2,ops2);
	
	int n3 =4;
	int map3[4][4] = { {   0, 1, INF,  8 },
					{   1, 0,   2,  3 },
					{ INF, 2,   0, 30 },
					{   8, 3,  30,  0 } };
	int ops3=0;
	int cycCost3= tspCost((int*)map3, n3, &ops3);
	printf("\nThe TSP cycle cost is %d\nThe number of ops is %d\n",cycCost3,ops3);
	
	int n4 = 5;
	int map4[5][5] = {{0, 5, 30, INF, 10},
					{5, 0, 20, 5, INF},
					{30, 20, 0, 20, 25},
					{INF, 5, 20, 0, 15},
					{10, INF, 25, 15, 0}};
	int ops4=0;
	int cycCost4= tspCost((int*)map4, n4, &ops4);
	printf("\nThe TSP cycle cost is %d\nThe number of ops is %d\n",cycCost4,ops4);

    return 0;
}