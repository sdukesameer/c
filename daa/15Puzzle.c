#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define N 4

//returns a unique value for each state, is used to make queue a union set to avoid redundancy
int stateVal(int mat[N][N]){
    int i,j,k=0;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            k+= mat[i][j]*((i*N)+j);
    return k;
}

// state space tree nodes
struct Node{
	// stores the parent node of the current node
	// helps in tracing path when the answer is found
	struct Node* parent;
	// stores matrix
	int mat[N][N];
	// stores blank tile coordinates
	int x, y;
	// stores the number of misplaced tiles
	int cost;
	// stores the number of moves so far
	int level;
};

struct Node* pQueue[1000];
int qSize=-1; //initiating queue size

void enqueue(struct Node* inNode){
    //check for duplicate, it happens when child tries to go back to parent
    int stateValCurrentNode = stateVal(inNode->mat);
    int i, flag=0;
    for(i=0;i<=qSize;i++){
        if(stateVal(pQueue[i]->mat)==stateValCurrentNode)
            flag=1;
    }
    if(flag==0){
        qSize++;
        // Insert the element
        pQueue[qSize] = inNode;
    }
}

//function to get the node with least cost, loc gives the location of its index in the queue array
struct Node* peek(int *loc){
    int lowest_cost = __INT_MAX__;
    int ind = -1;
    // Check for the element with
    // highest priority
    int i;
    for (i = 0; i <= qSize; i++){
        // If priority is same choose
        // the element with the
        // lowest value
        if (lowest_cost == (pQueue[i]->cost) && ind > -1 && (pQueue[ind]->cost) > (pQueue[i]->cost)){
            lowest_cost = (pQueue[i]->cost);
            ind = i;
        }
        else if (lowest_cost > (pQueue[i]->cost)) {
            lowest_cost = (pQueue[i]->cost);
            ind = i;
        }
    }
    // Return position of the element
    *loc = ind;
    return pQueue[ind];
}

// Function to remove the element with
// the highest priority
void dequeue(int ind){
    // Find the position of the element
    // with highest priority
    //int ind;
    //peek(&ind);
    int i;
    //free(pQueue[ind]);
    // Shift the element one index before
    // from the position of the element
    // with highest priority is found
    for (i = ind; i < qSize; i++) {
        pQueue[i] = pQueue[i + 1];
    }
    // Decrease the size of the
    // priority queue by one
    qSize--;
}

// Function to print N x N matrix
void printMatrix(int mat[N][N]){
    int i,j;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++)
			printf("%3d", mat[i][j]);
		printf("\n");
	}
}

// Function to allocate a new node
struct Node* newNode(int mat[N][N], int x, int y, int newX,
			int newY, int level,struct Node* parent){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

	// set pointer for path to root
	node->parent = parent;

	// copy data from parent node to current node
	memcpy(node->mat, mat, sizeof(node->mat));

	// move tile by 1 position
	int temp;
	temp = node->mat[x][y];
	node->mat[x][y] = node->mat[newX][newY];
	node->mat[newX][newY] = temp;
	//swap(node->mat[x][y], node->mat[newX][newY]);

	// set number of misplaced tiles
	node->cost = __INT_MAX__;

	// set number of moves so far
	node->level = level;

	// update new blank tile cordinates
	node->x = newX;
	node->y = newY;

	return node;
}

// bottom, left, top, right moves array
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

//calculate cost by counting number of non zero tiles out of place
int calculateCost(int initialState[N][N], int finalState[N][N]){
    int count = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (initialState[i][j] && initialState[i][j] != finalState[i][j])
				count++;
	return count;
}

// Function to check if (x, y) is a valid matrix cordinate
int isSafe(int x, int y){
	return (x >= 0 && x < N && y >= 0 && y < N);
}

// print path from root node to destination node
void printPath(struct Node* root){
	if (root == NULL){
		return;
    }
	printPath(root->parent);
	printMatrix(root->mat);
	printf("\n");
}

// function for solving 15 puzzle, x, y are initial empty tile position
void solve(int initialState[N][N], int x, int y,int finalState[N][N]){
    struct Node* root = newNode(initialState, x, y, x, y, 0, NULL);
	root->cost = calculateCost(initialState, finalState);

	// Add root to list of live nodes;
	enqueue(root);

	// Finds a live node with least cost,
	// add its childrens to list of live nodes and
	// finally deletes it from the list.
	while (qSize!=-1){
		// Find a live node with least estimated cost
        int *loc;
		struct Node* min = peek(loc);

		// The found node is deleted from the list of
		// live nodes
		dequeue((intptr_t)&loc);

		// if min is an answer node
		if (min->cost == 0){
			// print the path from root to destination;
			printPath(min);
			return;
		}

		// do for each child of min
		// max 4 children for a node
		for (int i = 0; i < 4; i++){
			if (isSafe(min->x + row[i], min->y + col[i])){
				// create a child node and calculate
				// its cost
				struct Node* child = newNode(min->mat, min->x,
							min->y, min->x + row[i],
							min->y + col[i],
							min->level + 1, min);
				child->cost = calculateCost(child->mat, finalState);
				// Add child to list of live nodes
				enqueue(child);
			}
		}
	}
}

// Driver code
int main(){
	// Initial configuration
	// Value 0 is used for empty space
	int initialState[N][N] = {  {1, 2, 3, 4},
                                {5, 10, 6, 8},
                                {0, 14, 7, 11},
                                {9, 13, 15, 12} };

	// Solvable Final configuration
	// Value 0 is used for empty space
	int finalState[N][N] = {{1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12},
                            {13, 14, 15, 0}};

	// Blank tile coordinates in initial
	// configuration
	int x,y;
	int i,j;
	for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(!initialState[i][j])
                x=i, y=j;
	solve(initialState, x, y, finalState);
	return 0;
}
