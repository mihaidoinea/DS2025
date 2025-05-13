#include "Shared.h"
BinarySearchTree* createBSTNode(Student* stud)
{
	BinarySearchTree* newNode = malloc(sizeof(BinarySearchTree));
	if (newNode != NULL)
	{
		newNode->data = stud;
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

void upsert(BinarySearchTree** root, Student* stud)
{
	if (*root == NULL)
		*root = createBSTNode(stud);
	else
	{
		if ((*root)->data->reference.intRef >
			stud->reference.intRef)
			upsert(&(*root)->left, stud);
		else if ((*root)->data->reference.intRef <
			stud->reference.intRef)
			upsert(&(*root)->right, stud);
		else
		{
			printf("Key already present, updating it!");
			(*root)->data = stud;
		}

	}
}