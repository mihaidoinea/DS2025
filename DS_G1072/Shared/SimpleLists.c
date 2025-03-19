#include "Shared.h"
Node* createNode(Student* pStud)
{
	Node* node = NULL;
	node = (Node*)malloc(sizeof(Node));
	if (node != NULL)
	{
		node->info = pStud;
		node->next = NULL;
	}
	return node;
}
//void insertHeadList(Node** head, Student* pStud)
//{
//	Node* node = createNode(pStud);
//	//1. connect the node to the structure
//	node->next = *head;
//	//2. connect the structure to the node
//	*head = node;
//}
void insertHeadList(PNode* head, Student* pStud)
{
	Node* node = createNode(pStud);
	//1. connect the node to the structure
	node->next = *head;
	//2. connect the structure to the node
	*head = node;
}