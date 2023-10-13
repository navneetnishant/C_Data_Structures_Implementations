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
	int edges[][2] = {{0,1},{0,2},{3,5},{5,4},{1,3}};
	int n=6, source=0, destination=5, res;

	struct Graph * graph = createGraph(n);
	
	for(int i=0; i<n-1; i++){
		addEdge(graph, edges[i][0], edges[i][1]);
	}

	printAdjMtx(graph);

	DFS(graph, 0);
	res=(graph->visited[destination] == 1) ? 1 : 0;
	printf("res: %d", res);
	return 0;
}