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

