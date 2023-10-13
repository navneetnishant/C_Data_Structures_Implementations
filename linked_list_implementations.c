/* Linked List in C */

#include <stdio.h>
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

int main(){
	//header to linked list stores first node's address
	struct Node * head = NULL;

	// adding elements to a linked list at the end
	/* since head is already a pointer, 
	in order to modify it from another function, we pass its address
	*/

	//insertNodeAtEnd(&head, value)
	int list[]={1,2,4};
	int len = (int) sizeof(list)/sizeof(list[0]);
	for(int i=0; i<len; i++){
		insertNodeAtEnd(&head, list[i]);	
	}
	printList(head);
}


