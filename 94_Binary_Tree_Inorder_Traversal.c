#include <stdio.h>
#include <stdlib.h>

struct Node{
	struct Node * left;
	int data;
	struct Node * right;
};

void inorderTraversal(struct Node *root){
	struct Node *ptr = root;
	if(ptr!=NULL){
		inorderTraversal(ptr->left);
		printf("%d\t", ptr->data);
		inorderTraversal(ptr->right);
	}
}

struct Node * createNode(int val){
	struct Node * temp = (struct Node *) malloc(sizeof(struct Node));
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;  
}

// void insertVal(struct Node ** root, int val){
// 	struct Node * ptr = *root;
// 	struct Node *prev = NULL;
// 	if(*root == NULL){
// 		*root = createNode(val);
// 	}
// 	else if(ptr->data < val){
// 		ptr->right = insertVal(ptr->right, val);
// 	}
// 	else if(ptr->data > val){
// 		ptr->left = insertVal(ptr->left, val);
// 	}
// }

int main(void){
	struct Node * root = NULL;
 	// int tree[] = {1,NULL,2,3};
 	// insertVal(&root, 1);
 	// insertVal(&root, 2);
 	// insertVal(&root, 3);

 	root = createNode(1);
 	root->right = createNode(2);
 	root->right->left = createNode(3);

 	inorderTraversal(root);

}