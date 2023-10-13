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



// function to merge the lists
struct Node * mergeLists(struct Node ** hd1, struct Node ** hd2){
	struct Node *ptr1, *ptr2, *temp1, *temp2;
	ptr1 = *hd1;
	ptr2 = *hd2;	


	if(*hd1 != NULL && *hd2 != NULL){
		// printf("Entered if in merge");
		while(ptr1 != NULL && ptr2 != NULL){
			// printf("%d\n", ptr2->data);
			temp2=ptr2->next;
			ptr2->next = ptr1->next;
			temp1 = ptr1->next;
			ptr1->next = ptr2;
			ptr2=temp2; //incrementing ptr2 to point to next node
			ptr1=temp1;
			if(ptr1->next == NULL){
				ptr1->next=ptr2;
				// printf("%d", ptr1->data);
				break;
			}
		}

		// printf("%d", ptr2->data);
		return *hd1;
	}
	else{
		return (*hd1 == NULL) ? *hd2 : *hd1;
	}

}











int main(){
	//header to linked list stores first node's address
	struct Node * head1 = NULL;
	struct Node * head2 = NULL;
	// adding elements to a linked list at the end
	/* since head is already a pointer, 
	in order to modify it from another function, we pass its address
	*/

	//insertNodeAtEnd(&head, value)
	int list1[]={};
	int list2[]={0};
	int len1 = (int) sizeof(list1)/sizeof(list1[0]);
	int len2 = (int) sizeof(list2)/sizeof(list2[0]);
	
	for(int i=0; i<len1; i++){
		insertNodeAtEnd(&head1, list1[i]);	
	}

	for(int i=0; i<len2; i++){
		insertNodeAtEnd(&head2, list2[i]);	
	}
	// printList(head1);
	// printList(head2);

	// mergeLists(&head1, &head2);

	printList(mergeLists(&head1, &head2));
}




















/*

1 -> 2  -> 4 -> NULL

1 -> 3 -> 4 -> NULL



ptr1->data == ptr2->data => true => 
temp1=ptr1->next;
ptr1->next = ptr2
temp2=ptr2->next;
ptr2->next = temp1;
ptr1=temp1;
ptr2=temp2;

----
temp2=ptr2->next;
ptr2->next = ptr1->next;
temp1 = ptr1->next;
ptr1->next = ptr2;
ptr2=temp2; //incrementing ptr2 to point to next node
ptr1=temp1; // incrementing ptr1 to point to next node
*/