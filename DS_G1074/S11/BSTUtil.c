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

int getHeight(BinarySearchTree** node) {
	if (*node == NULL) {
		return 0;
	}
	else {
		return 1 + max(getHeight(&(*node)->left), getHeight(&(*node)->right));
	}
}

BinarySearchTree* leftRotation(BinarySearchTree* pivot) {
	BinarySearchTree* desc = pivot->right;
	pivot->right = desc->left;
	desc->left = pivot;
	return desc;

}
BinarySearchTree* rightRotation(BinarySearchTree* pivot) {
	BinarySearchTree* desc = pivot->left;
	pivot->left = desc->right;
	desc->right = pivot;
	return desc;
}


BinarySearchTree* rebalance(PBinarySearchTree* pivot) {
	(*pivot)->bFactor = getHeight(&(*pivot)->left) -
		getHeight(&(*pivot)->right);

	if ((*pivot)->bFactor == -2) {
		PBinarySearchTree rChildDesc = (*pivot)->right;
		if ((rChildDesc->bFactor == -1)) {
			// left rotation in the pivot
			(*pivot) = leftRotation(*pivot);

		}
		else {
			if (rChildDesc->bFactor == 1) {
				//double rotation
				(*pivot)->right = rightRotation(rChildDesc);
				(*pivot) = leftRotation(*pivot);
			}
		}
	}
	if ((*pivot)->bFactor == 2){
		PBinarySearchTree lChildDesc = (*pivot)->left;
		if (lChildDesc->bFactor == -1) {
			//double rotation
			(*pivot)->left = leftRotation(lChildDesc);
			(*pivot) = rightRotation(*pivot);
		}
		else {
			if (lChildDesc->bFactor = 1)
			{
				//right rotation in the pivot
				(*pivot) = rightRotation(*pivot);
			}
		}
	}

	return *pivot;
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
	*root = rebalance(root);
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

