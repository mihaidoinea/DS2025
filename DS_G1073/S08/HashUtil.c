#include "Shared.h"
int fHash(const char* key)
{
	int position = -1;
	if (key != NULL)
	{
		position = key[0] % HASH_SIZE;
	}
	return position;
}
SNode* createNode(Student* info)
{
	SNode* node = malloc(sizeof(SNode));
	if (node != NULL)
	{
		node->info = info;
		node->next = NULL;
	}
	return node;
}
void putStudent(HashTable* hashTable, Student* stud)
{
	if (hashTable->buckets == NULL)
	{
		hashTable->buckets = malloc(sizeof(SNode*) * HASH_SIZE);
		memset(hashTable->buckets, 0, sizeof(SNode*) * HASH_SIZE);
		hashTable->size = HASH_SIZE;
	}
	else
	{
		int index = fHash(stud->name);
		if (index > -1)
		{
			SNode* node = createNode(stud);
			if (node != NULL)
			{
				node->next = hashTable->buckets[index];
				hashTable->buckets[index] = node;
			}
		}
	}
}

Student* getStudent(HashTable hashTable, const char* key)
{
	//calculate the index
	//get the bucket
	//search for the key
}