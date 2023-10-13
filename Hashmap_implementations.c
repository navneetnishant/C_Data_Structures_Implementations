/*

Keys are mapped to array positions using a hash function


searching in O(1)




*/


#include <stdio.h>
#include <string.h>


int hashFunc(int key, int len){
	return ;
}

int main(void){
	char ch[]={'A','B','C','D','E','F','G','H','\0'};
	int len = (int) strlen(ch);
	int hashMap[len];
	int key;
	//initialize hashmap with -1 at every index
	for(int i=0; i<len; i++){
		hashMap[i] = -1;
	}
	//inserting elements in hashmap 
	for(int i=0; i<len; i++){
		key = (int) ch[i];
		// hashMap[hashFunc(key)] = ch[i];
		printf("%d", hashFunc(key, len));
		
	}
	// printf("%d", (int) ch[0]);


}

/* ---------------------------------------------------*/

/* Hash Function Methods */


/* 
Hashing - Division Method 

h(x) = x % M;
best to choose 'M' to be a prime number

*/



/* 
Hashing - Multiplication Method
h(k) = (k*A % 1)*m

A => 0 < A < 1 (best value of A: (sqrt 5 -1)/2 = 0.61800339887)

k => key

m => size of hashmap

*/

/* 
Hashing - Mid-Square Method

square the key => k*k

take r digits from the middle of k*k => s

h(k) = s

eg
keys 1234 and 5642 if mapped on hashmap of size 100

k*k=1234*1234 = 1522756 => h(1234) = 27
k*k=5642*5642 = 31832164 => h(5642) = 21 
(3rd and 4th digit is chosen from the last)

since size of hashmap = 100
so two digits are enough for index, r=2


*/


/* 
Folding Method
keys 5678, 321, and 34567
hashmap size 100

we break the numbers in two digit parts except the last digit 

5678 => 56+78 => 134 => drop the last carry => h(5678) = 34
321 => 32+1 => h(321)=33 
34567 => 34+56+7 => h(k)=97

*/


/* ------------------------------------------------------- */


/* Hash Map Collision Resolution - Open Addressing */

/*

Linear Probing
if space is empty
h'(k) = k % m;

on collision: new hash function
h(k, i) = (h'(k)+i)%m;

here I have used j instead of i in the program
*/

#include <stdio.h>
#include <math.h>

// hash function using Multiplication Method
int hashFunc(int k, int m){
	return k % m;
}

int main(void){
	int keys[] = {72, 27, 36, 24, 63, 81, 92, 101};
	int len = (int) (sizeof(keys)/sizeof(keys[0]));
	int m = 10;
	int hashMap[m];
	int newHash;
	//initialize hashmap
	for(int i=0; i<m; i++){
		hashMap[i] = -1;
	}


	for(int i=0; i<len; i++){
		if(hashMap[hashFunc(keys[i], m)] == -1){
			hashMap[hashFunc(keys[i], m)] = keys[i];
			// printf("index: %d \t value: %d\n", hashFunc(keys[i], m), keys[i]);
		}
		else{
			//linear probing when collision happens 
			for(int j=0; j<m; j++){
				newHash = (hashFunc(keys[i], m)+j)%m;
				// printf("%d\n", newHash);
				if(hashMap[newHash] == -1){
					printf("%d\n", newHash);
					hashMap[newHash] = keys[i];
					break;
				}
			}
		}
		// printf("%d\n", hashFunc(keys[i], m));	
	}
	// printing hashMap
	for(int i=0; i<m; i++){
		printf("index: %d \t value: %d\n", i, hashMap[i]);
	}
	return 0;
}


/* -------------------------------------------------------- */


/* Hash Map Collision Resolution - Open Addressing */

/*

Quadratic Probing

h'(k) = k % m

on collision we use this new Hash Function h(k, i)
h(k, i) = (h'(k) + c1*i + c2*i*i) % m

i=probe number => i varies from 0 to m-1

m=size of hashMap

=>Please read why Quadratic probing is needed.

*/

#include <stdio.h>
#include <math.h>


int hashFunc(int k, int m){
	return k % m;
}

int main(void){
	int keys[] = {72, 27, 36, 24, 63, 81, 101};
	int len = (int) (sizeof(keys)/sizeof(keys[0]));
	// m => size of hashMap
	int m = 10;
	int c1 = 1, c2=3;
	int hashMap[m];
	int newHash;
	//initialize hashmap
	for(int i=0; i<m; i++){
		hashMap[i] = -1;
	}

	//inserting values in hashMap
	for(int i=0; i<len; i++){
		if(hashMap[hashFunc(keys[i], m)] == -1){
			hashMap[hashFunc(keys[i], m)] = keys[i];
			printf("index: %d \t value: %d\n", hashFunc(keys[i], m), keys[i]);
		}
		else{
			//linear probing when collision happens 
			for(int j=0; j<m; j++){
				newHash = (hashFunc(keys[i], m)+(c1*j)+(c2*j*j))%m;
				// printf("%d\n", newHash);
				if(hashMap[newHash] == -1){
					printf("%d\n", newHash);
					hashMap[newHash] = keys[i];
					break;
				}
			}
		}
		// printf("%d\n", hashFunc(keys[i], m));	
	}
	// printing hashMap
	for(int i=0; i<m; i++){
		printf("index: %d \t value: %d\n", i, hashMap[i]);
	}
	return 0;
}

/* ------------------------------------------------------ */

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
