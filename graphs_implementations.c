//Breadth First Search


#include <stdio.h>
#include <stdlib.h>

#define SIZE 40

// defining a node of the linked list where we will store the vertex;
struct Node{
	int vertex;
	struct Node *next;
};


// defining a graph which organises these nodes
struct Graph{
	// number of vertices
	int numVertices;
	//an array to store visited vertices
	int * visited;
	// array of pointers adjacency matrix which will store the linked lists
	struct Node ** adjMtx;
};


// defining a queue
struct Queue{
	int items[SIZE];
	int front;
	int rear;
};


// creating a node
struct Node * createNode(int val){
	struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
	ptr->vertex = val;
	ptr->next = NULL;
	return ptr;
}

// create graph of vertices V
struct Graph * createGraph(int V){
	struct Graph * graph = (struct Graph *) malloc(sizeof(struct Graph));
	graph->numVertices = V;
	graph->visited = (int *) malloc(graph->numVertices*sizeof(int));
	// dynamically allocating adjacency array of size numVertices 
	graph->adjMtx = (struct Node **) malloc(graph->numVertices*sizeof(struct Node *));
	//initializing adjacency array with 'NULL'
	for(int i=0; i<graph->numVertices; i++){
		graph->adjMtx[i] = NULL;
		graph->visited[i]=0;
	}
	return graph;
}

// adding edge between vertex u and vertex v
void addEdge(struct Graph * graph, int u, int v){
	//creating an edge u --> v
	struct Node *ptr=createNode(v);
	//inserting node at begining of linked list
	ptr->next = graph->adjMtx[u];
	graph->adjMtx[u] = ptr;

	// creatign an edge v --> u
	ptr=createNode(u);
	ptr->next = graph->adjMtx[v];
	graph->adjMtx[v]=ptr;
}


// creating a queue
struct Queue * createQueue(){
	struct Queue * q = (struct Queue *) malloc(sizeof(struct Queue));
	q->front = -1;
	q->rear = -1;
	return q;
}


int isQueueEmpty(struct Queue * q){
	if(q->rear == -1){
		return 1;
	}
	else{
		return 0;
	}
}

// adding an item to queue
void enqueue(struct Queue * q, int val){
	if(q->rear == SIZE-1){
		printf("Queue is full\n");
	}
	else{
		if(q->front == -1){
			q->front=0;
		}
		q->rear++;
		q->items[q->rear] = val;
	}
}

// deleting item from queue

int dequeue(struct Queue * q){
	int item;
	if(isQueueEmpty(q) == 1){
		printf("Queue is empty!\n");
		item = -1;
	}
	else{
		item = q->items[q->front];
		q->front++;
		if(q->front > q->rear){
			printf("Resetting queue\n");
			q->front = -1;
			q->rear = -1;
		}
	}
	return item;
}

void BFS(struct Graph * graph, int vtx){
	struct Queue * q = createQueue();	
	// struct Node * ptr = graph->adjMtx[vtx];

	graph->visited[vtx] = 1;
	enqueue(q, vtx);

	while(isQueueEmpty(q) != 1){
		int currVertex = dequeue(q);
		printf("visited: \t %d \n", currVertex);

		struct Node * ptr = graph->adjMtx[currVertex];
		while(ptr!=NULL){
			if(graph->visited[ptr->vertex] == 0){
				int connectedVertex = ptr->vertex;
				graph->visited[connectedVertex] = 1;
				enqueue(q, connectedVertex);
			}
			ptr = ptr->next;
		}
	}
}





//printing adjMtx
void printAdjMtx(struct Graph * graph){
	for(int i=0; i<graph->numVertices; i++){
		struct Node * ptr = graph->adjMtx[i];
		printf("i: %d \t list:", i);
		while(ptr!=NULL){
			printf("%d -> ", ptr->vertex);
			ptr = ptr->next;
		}
		printf("\n");
		// printf("i:%d \t ptr:%d \n", i, graph->adjMtx[i]->vertex);
	}
}





int main(void){
	struct Graph * graph = createGraph(4);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 0, 3);
	addEdge(graph, 1, 2);
	printAdjMtx(graph);

	BFS(graph, 0);
	return 0;
}


/*
	 0----3		
   /  \  
  1	-- 2

index
0 ------> 1 -> 2 -> 3 -> 
1 ------> 0 -> 2 -> 
2 ------> 0 -> 1 ->
3 ------> 0 ->

DFS(graph, 2) -> DFS(graph, 0) -> DFS(graph, 1)

visited = {1,1,1,0}
		   0 1 2 3
*/


























/*

//Depth First Search - DFS (recursive)

#include <stdio.h>
#include <stdlib.h>




// defining a node of the linked list where we will store the vertex;
struct Node{
	int vertex;
	struct Node *next;
};


struct Node * createNode(int val){
	struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
	ptr->vertex = val;
	ptr->next = NULL;
	return ptr;
}

// defining a graph which organises these nodes
struct Graph{
	// number of vertices
	int numVertices;
	//an array to store visited vertices
	int * visited;
	// array of pointers adjacency matrix which will store the linked lists
	struct Node ** adjMtx;
};


// create graph of vertices V
struct Graph * createGraph(int V){
	struct Graph * graph = (struct Graph *) malloc(sizeof(struct Graph));
	graph->numVertices = V;
	graph->visited = (int *) malloc(graph->numVertices*sizeof(int));
	// dynamically allocating adjacency array of size numVertices 
	graph->adjMtx = (struct Node **) malloc(graph->numVertices*sizeof(struct Node *));
	//initializing adjacency array with 'NULL'
	for(int i=0; i<graph->numVertices; i++){
		graph->adjMtx[i] = NULL;
		graph->visited[i]=0;
	}
	return graph;
}

// adding edge between vertex u and vertex v
void addEdge(struct Graph * graph, int u, int v){
	//creating an edge u --> v
	struct Node *ptr=createNode(v);
	//inserting node at begining of linked list
	ptr->next = graph->adjMtx[u];
	graph->adjMtx[u] = ptr;

	// creatign an edge v --> u
	ptr=createNode(u);
	ptr->next = graph->adjMtx[v];
	graph->adjMtx[v]=ptr;
}

void DFS(struct Graph * graph, int vtx){
	
	struct Node * ptr = graph->adjMtx[vtx];
	graph->visited[vtx] = 1;
	printf("visited: \t %d \n", vtx);
	while(ptr!=NULL){
		// finding adjacent vertices of 'vertex' which are not visited
		if(graph->visited[ptr->vertex] == 0){
			int connectedVertex = ptr->vertex;
			DFS(graph, connectedVertex);
		}
		ptr = ptr->next;
	}
}





//printing adjMtx
void printAdjMtx(struct Graph * graph){
	for(int i=0; i<graph->numVertices; i++){
		struct Node * ptr = graph->adjMtx[i];
		printf("i: %d \t list:", i);
		while(ptr!=NULL){
			printf("%d -> ", ptr->vertex);
			ptr = ptr->next;
		}
		printf("\n");
		// printf("i:%d \t ptr:%d \n", i, graph->adjMtx[i]->vertex);
	}
}





int main(void){
	struct Graph * graph = createGraph(4);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 0, 3);
	addEdge(graph, 1, 2);
	printAdjMtx(graph);

	DFS(graph, 0);
	return 0;
}
*/

/*
	 0----3		
   /  \  
  1	-- 2

index
0 ------> 1 -> 2 -> 3 -> 
1 ------> 0 -> 2 -> 
2 ------> 0 -> 1 ->
3 ------> 0 ->

DFS(graph, 2) -> DFS(graph, 0) -> DFS(graph, 1)

visited = {1,1,1,0}
		   0 1 2 3
*/


/*

// Graph using adjacency list

#include <stdio.h>
#include <stdlib.h>




// defining a node of the linked list where we will store the vertex;
struct Node{
	int vertex;
	struct Node *next;
};


struct Node * createNode(int val){
	struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
	ptr->vertex = val;
	ptr->next = NULL;
	return ptr;
}

// defining a graph which organises these nodes
struct Graph{
	// number of vertices
	int numVertices;
	// array of pointers adjacency matrix which will store the linked lists
	struct Node ** adjMtx;
};


// create graph of vertices V
struct Graph * createGraph(int V){
	struct Graph * graph = (struct Graph *) malloc(sizeof(struct Graph));
	graph->numVertices = V;
	// dynamically allocating adjacency array of size numVertices 
	graph->adjMtx = (struct Node **) malloc(graph->numVertices*sizeof(struct Node *));
	//initializing adjacency array with 'NULL'
	for(int i=0; i<graph->numVertices; i++){
		graph->adjMtx[i] = NULL;
	}
	return graph;
}

// adding edge between vertex u and vertex v
void addEdge(struct Graph * graph, int u, int v){
	//creating an edge u --> v
	struct Node *ptr=createNode(v);
	//inserting node at begining of linked list
	ptr->next = graph->adjMtx[u];
	graph->adjMtx[u] = ptr;

	// creatign an edge v --> u
	ptr=createNode(u);
	ptr->next = graph->adjMtx[v];
	graph->adjMtx[v]=ptr;
}



//printing adjMtx
void printAdjMtx(struct Graph * graph){
	for(int i=0; i<graph->numVertices; i++){
		struct Node * ptr = graph->adjMtx[i];
		printf("i: %d \t list:", i);
		while(ptr!=NULL){
			printf("%d -> ", ptr->vertex);
			ptr = ptr->next;
		}
		printf("\n");
		// printf("i:%d \t ptr:%d \n", i, graph->adjMtx[i]->vertex);
	}
}





int main(void){
	struct Graph * graph = createGraph(4);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 0, 3);
	addEdge(graph, 1, 2);
	printAdjMtx(graph);
	return 0;
}

*/















/*
	 0----3		
   /  \  
  1	-- 2

adjacency list:

it is an array of pointers

we store all vertices connected with a vertex in linked list
index of array is the vertex whose adjacency we are defining

index
0 ------> 1 -> 2 -> 3 -> 
1 ------> 0 -> 2 -> 
2 ------> 0 -> 1 ->
3 ------> 0 ->


*/







/*
// Graph using adjacency matrix

//defining number of vertices
#define V 4

// initialising adjacency matrix with 0s
void initAdjMtx(int adjMtx[][V]){
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			adjMtx[i][j]=0;
		}
	}
}


// Adding edges 
void addEdge(int adjMtx[][V], int u, int v){
	// u and v are vertices
	//since it is a unidirected graph, we add edges in both direction ie., u ---> v and v ---> u
	adjMtx[u][v] = 1;
	adjMtx[v][u] = 1;
}


// print adjacency matrix
void printAdjMtx(int adjMtx[][V]){
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			printf("i:%d \t j:%d \t", i, j);
			printf("edge:%d\n", adjMtx[i][j]);
		}
	}
}

int main(void){
	int adjMtx[V][V];
	
	initAdjMtx(adjMtx);

	addEdge(adjMtx, 0, 1);
	addEdge(adjMtx, 0, 2);
	addEdge(adjMtx, 0, 3);
	addEdge(adjMtx, 1, 2);

	printAdjMtx(adjMtx);

	return 0;
}

*/

/*

Star graph (not using now)
  4
  | 
  2	
 / \
1   3


Using now:

	 0----3		
   /  \  
  1	-- 2

adjacency matrix:
  0 1 2 3
0 0 1 1 1
1 1 0 1 0
2 1 1 0 0       j_
3 1 0 0 0     i|

*/

