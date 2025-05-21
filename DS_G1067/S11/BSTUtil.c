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

int calculInaltime(BinarySearchTree* root) {
	if (root == NULL) {
		return 0;
	}
	else {
		return 1 + max(calculInaltime(root->left), calculInaltime(root->right));
	}
}

PBinarySearchTree leftRotation(PBinarySearchTree pivot) {
	PBinarySearchTree descDr = pivot->right;
	pivot->right = descDr->left;
	descDr->left = pivot;
	return descDr;
}
PBinarySearchTree rightRotation(PBinarySearchTree pivot) {
	PBinarySearchTree descSt = pivot->left;
	pivot->left = descSt->right;
	descSt->right = pivot;
	return descSt;
}
BinarySearchTree* rebalance(PBinarySearchTree pivot) {
	pivot->bFactor = calculInaltime(pivot->left) - calculInaltime(pivot->right);

	if (pivot->bFactor == -2)
	{
		PBinarySearchTree descDreapta = pivot->right;
		if (descDreapta->bFactor == -1) //Left rotation in the pivot
			pivot = leftRotation(pivot);
		else {
			pivot->right= rightRotation(descDreapta);
			pivot = leftRotation(pivot);
		}
	}
	else if (pivot->bFactor == 2)
	{
		PBinarySearchTree descStanga = pivot->left;
		if (descStanga->bFactor == 1) //Right rotation in the pivot
			pivot = rightRotation(pivot);
		else {
			pivot->left= leftRotation(descStanga);
			pivot = rightRotation(pivot);
		}
	}
	
	return pivot;
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

	*root = rebalance(*root);

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

