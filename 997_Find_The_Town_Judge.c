#include <stdio.h>
#include <stdlib.h>

#define SIZE 10


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
	// ptr=createNode(u);
	// ptr->next = graph->adjMtx[v];
	// graph->adjMtx[v]=ptr;
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


int hashFunc(int key){
	return key % 10;
}


int main(void){
	int n=3, trust[][2]={{1,3},{2,3}};
	int t = (int) (sizeof(trust)/sizeof(trust[0]));
	int res=-1;

	struct Graph * graph = createGraph(n+1);
	
	for(int i=0; i<t; i++){
		addEdge(graph, trust[i][0], trust[i][1]);
	}

	if(t == 1){
		res = trust[0][1];
	}
	else{
		int hashMap[SIZE];
	

		for(int i=0; i<SIZE; i++){
			hashMap[i]=0;
		}

		for(int i=0; i<t; i++){
			hashMap[hashFunc(trust[i][0])]+=1;
			hashMap[hashFunc(trust[i][1])]+=1;
		}

		for(int i=0; i<SIZE; i++){
			if(hashMap[i] > 1){
				if(graph->adjMtx[i] == NULL){
				res = i; 
				}
			}
		}
	}
	

	printAdjMtx(graph);
	printf("res: %d", res);
	// DFS(graph, 0);
	return 0;
}

/*
  3
1   2
*/