#include "Shared.h"
BinarySearchTree* createBSTNode(Student* stud)
{
	BinarySearchTree* newNode = malloc(sizeof(BinarySearchTree));
	if (newNode != NULL)
	{
		newNode->data = stud;
		newNode->bFactor = 0;
		newNode->left = newNode->right = NULL;
	}
	return newNode;
}

void preOrder(BinarySearchTree* root)
{
	if (root)
	{
		printStudent(root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void inOrder(BinarySearchTree* root)
{
	if (root)
	{
		inOrder(root->left);
		printStudent(root->data);
		inOrder(root->right);
	}
}
void postOrder(BinarySearchTree* root)
{
	if (root)
	{
		postOrder(root->left);
		postOrder(root->right);
		printStudent(root->data);
	}
}
char getHeight(BinarySearchTree* pivot) {
	if (pivot == NULL) {
		return 0;
	}
	else {
		return (1 + max(getHeight(pivot->right), 
			getHeight(pivot->left)));
	}
}

void LeftRotation(PBinarySearchTree* pivot)
{
	BinarySearchTree* desc = (*pivot)->right;
	(*pivot)->right = desc->left;
	desc->left = (*pivot);
	(*pivot) = desc;
}

void RightRotation(PBinarySearchTree* pivot)
{
	BinarySearchTree* desc = (*pivot)->left;
	(*pivot)->left = desc->right;
	desc->right = (*pivot);
	(*pivot) = desc;
}

void rebalance(PBinarySearchTree* pivot)
{
	(*pivot)->bFactor = getHeight((*pivot)->left) 
		- getHeight((*pivot)->right);
	if ((*pivot)->bFactor == -2) {
		BinarySearchTree* descendentRight = (*pivot)->right;
		if (descendentRight->bFactor == -1) {
			LeftRotation(pivot);
		}
		else
		{
			RightRotation(&(*pivot)->right);
			LeftRotation(pivot);
		}
	}
	else {
		if ((*pivot)->bFactor == 2) {
			BinarySearchTree* descendentLeft = (*pivot)->left;
			if (descendentLeft->bFactor == 1) {
				//RRpivot
				RightRotation(pivot);
			}
			else
			{
				LeftRotation(&(*pivot)->left);
				RightRotation(pivot);
			}
		}
	}
	
}
void upsert(PBinarySearchTree* root, Student* stud)
{
	if (*root == NULL)
		*root = createBSTNode(stud);
	else
	{
		if ((*root)->data->id > stud->id)
			upsert(&(*root)->left, stud);
		else if ((*root)->data->id < stud->id)
			upsert(&(*root)->right, stud);
		else
		{
			printf("Key already present, updating it!");
			(*root)->data = stud;
		}
	}
	rebalance(root);
}


void deleteFullNode(BinarySearchTree** root, BinarySearchTree** desc)
{
	if ((*desc)->right)
		deleteFullNode(root, &(*desc)->right);
	else
	{
		deleteStudent((*root)->data);
		(*root)->data = (*desc)->data;
		BinarySearchTree* tmp = *desc;
		*desc = tmp->left;
		free(tmp);
	}
}
void deleteNodeByKey(BinarySearchTree** root, unsigned short key)
{
	if (*root != NULL)
	{
		if ((*root)->data->id > key)
			deleteNodeByKey(&(*root)->left, key);
		else if ((*root)->data->id < key)
			deleteNodeByKey(&(*root)->right, key);
		else
		{
			if ((*root)->left == NULL && (*root)->right == NULL)
			{
				deleteStudent((*root)->data);
				free(*root);
				*root = NULL;
			}
			else if ((*root)->left == NULL || (*root)->right == NULL)
			{
				BinarySearchTree* tmp = (*root);
				(*root) = (*root)->left ? (*root)->left : (*root)->right;
				deleteStudent(tmp->data);
				free(tmp);
			}
			else
			{
				deleteFullNode(root, &(*root)->left);
			}
		}
	}
}

