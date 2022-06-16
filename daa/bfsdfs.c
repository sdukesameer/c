#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

//utility functions for queue, already implemented
    struct queue {
    int items[SIZE];
    int front;
    int rear;
};

struct node {
    int vertex;
    struct node* next;
};

struct Graph {
    int numVertices;
    struct node** adjLists;
    int* visited;
};

// Creating a node
struct node* createNode(int v) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Creating a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void resetVisited(struct Graph* graph){
    int vertices = graph->numVertices;
    int i;
    for (i = 0; i < vertices; i++) {
        graph->visited[i] = 0;
    }
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Create a queue
struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// Adding elements into queue
void enqueue(struct queue* q, int value) {
    if (q->rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
        q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Removing elements from queue
int dequeue(struct queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
        printf("Resetting queue ");
        q->front = q->rear = -1;
        }
    }
    return item;
}

// Print the queue
void printQueue(struct queue* q) {
    int i = q->front;
    if (isEmpty(q)) {
        printf("Queue is empty");
    } else {
        printf("\nQueue contains \n");
        for (i = q->front; i < q->rear + 1; i++) {
        printf("%d ", q->items[i]);
        }
    }
}

void printGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < graph->numVertices; v++) {
        struct node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp) {
        printf("%d -> ", temp->vertex);
        temp = temp->next;
        }
        printf("\n");
    }
}

void bfs(struct Graph* graph, int startVertex, int *ops) {
    struct queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);
    while (!isEmpty(q)) {
        (*ops)++;
        printQueue(q);
        int currentVertex = dequeue(q);
        printf("\n  *** Visited %d\n", currentVertex);
        struct node* curr = graph->adjLists[currentVertex];
        while (curr) {
            (*ops)++;
            int adjVertex = curr->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            curr = curr->next;
        }
    }
}

//use recursive algo or implement stack with help from queue codes
void dfs(struct Graph* graph, int vertex, int *ops) {
    struct node* adjList = graph->adjLists[vertex];
    struct node* curr = adjList;
    graph->visited[vertex] = 1;
    printf("\nVisited %d \n", vertex);
    while (curr != NULL) {
        (*ops)++;
        int linkedVertex = curr->vertex;
        if (graph->visited[linkedVertex] == 0) {
            dfs(graph, linkedVertex,ops);
        }
        curr = curr->next;
    }
}

int main(){
    struct Graph* graph1 = createGraph(7);
    int ops_bfs=0;
    int ops_dfs=0;
    addEdge(graph1, 0, 1);
    addEdge(graph1, 0, 2);
    addEdge(graph1, 0, 4);
    addEdge(graph1, 1, 2);
    addEdge(graph1, 1, 3);
    addEdge(graph1, 2, 4);
    addEdge(graph1, 2, 5);
    addEdge(graph1, 3, 4);
    addEdge(graph1, 3, 5);
    addEdge(graph1, 4, 5);
    addEdge(graph1, 5, 6);
    printf("\n**** Input Graph *****\n");
    printGraph(graph1);
    printf("\n***** BREADTH FIRST TRAVERSAL *****\n");
    bfs(graph1, 0, &ops_bfs);
    printf("\n\n**** Number of Ops in BFS: %d\n\n",ops_bfs);
    resetVisited(graph1);
    printf("\n***** DEPTH FIRST TRAVERSAL *****\n");
    dfs(graph1, 0, &ops_dfs);
    printf("\n\n**** Number of Ops in DFS: %d\n\n",ops_dfs);

    struct Graph* graph2 = createGraph(10);
    int ops_bfs2=0;
    int ops_dfs2=0;
    addEdge(graph2, 0, 2);
    addEdge(graph2, 1, 2);
    addEdge(graph2, 2, 3);
    addEdge(graph2, 2, 4);
    addEdge(graph2, 2, 5);
    addEdge(graph2, 3, 4);
    addEdge(graph2, 3, 6);
    addEdge(graph2, 3, 7);
    addEdge(graph2, 4, 5);
    addEdge(graph2, 4, 6);
    addEdge(graph2, 5, 6);
    addEdge(graph2, 5, 7);
    addEdge(graph2, 6, 7);
    addEdge(graph2, 7, 8);
    addEdge(graph2, 7, 9);
    addEdge(graph2, 8, 9);
    addEdge(graph2, 1, 7);
    addEdge(graph2, 1, 8);
    printf("\n**** Input Graph *****\n");
    printGraph(graph2);
    printf("\n***** BREADTH FIRST TRAVERSAL *****\n");
    bfs(graph2, 2, &ops_bfs2);
    printf("\n\n**** Number of Ops in BFS: %d\n\n",ops_bfs2);
    resetVisited(graph2);
    printf("\n***** DEPTH FIRST TRAVERSAL *****\n");
    dfs(graph2, 2, &ops_dfs2);
    printf("\n\n**** Number of Ops in DFS: %d\n\n",ops_dfs2);
    return 0;
}
