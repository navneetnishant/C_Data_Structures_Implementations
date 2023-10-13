/* Hash Map Collision Resolution - Chaining */

/*
Chained Hash Table

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// defining a node

struct Node{
	// value stored in the node
	int data;
	// next pointer points to next node
	struct Node * next;
};




//function to create a node

struct Node * createNode(int val){
	// a pointer to point to new node being created
	struct Node * ptr;
	//creating new node and storing address in ptr
	//malloc by default return void * type pointer which we typecast
	ptr = (struct Node *) malloc(sizeof(struct Node));
	
	ptr->data  = val;
	ptr->next = NULL;
	
	return ptr;
}

void insertNodeAtEnd(struct Node ** hd, int val){
	
	if(*hd == NULL){
		//list empty
		*hd = createNode(val);
	}
	else{
		// list has elements
		// we traverse till last element to insert new node
		struct Node *ptr = *hd;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		// when loop ends, ptr will point to last node
		// time to insert the new node
		ptr->next = createNode(val);
	}
}


// function to print a linked list
/* for printing we dont need to modify the nodes
   hence passing just value of head
*/

void printList(struct Node * hd){
	struct Node *ptr = hd;
	if(hd == NULL){
		printf("Empty List");
	}
	else{	
		while(ptr!=NULL){
			printf("%d -> ", ptr->data);
			ptr = ptr->next;
		}
		printf("\n");	
	}
}


int hashFunc(int k, int m){
	return k % m;
}

int main(void){
	int keys[] = {7, 24, 18, 52, 36, 54, 11, 23};
	int len = (int) (sizeof(keys)/sizeof(keys[0]));
	// m => size of hashMap
	int m = 9;
	struct Node * hashMap[m];
	int newHash;

	struct Node * head;
	int val;
	//initialize hashmap with NULL
	for(int i=0; i<m; i++){
		hashMap[i] = NULL;
	}

	//inserting values in hashMap
	for(int i=0; i<len; i++){
		head = hashMap[hashFunc(keys[i], m)];
		val=keys[i];
		insertNodeAtEnd(&head, val);
		hashMap[hashFunc(keys[i], m)] = head;	
	}

	// printing hashMap after insertion
	for(int i=0; i<m; i++){
		printf("\nindex: %d \t value: \t", i);
		printList(hashMap[i]);
		printf("\n");
	}
	// return 0;

	
}
