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
SNode* createNode(Student* stud)
{
	SNode* node = malloc(sizeof(SNode));
	if (node != NULL)
	{
		node->info = stud;
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
		//for having O(1) for the PUT operation we would have insert 
		//at the begining of the list
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
	Student* stud = NULL;
	int index = fHash(key);
	if (index > -1)
	{
		SNode* aux = hashTable.buckets[index];
		while (aux && strcmp(aux->info->name, key) != 0)
			aux = aux->next;
		if (aux != NULL)
			stud = aux->info;
	}
	return stud;
}

void deleteStud(HashTable hashTable, const char* key)
{
	int index = fHash(key);
	if (index > -1 && hashTable.buckets != NULL)
	{
		SNode* bucket = hashTable.buckets[index];
		SNode* prev = NULL;
		while (bucket != NULL && strcmp(bucket->info->name, key) != 0)
		{
			prev = bucket;
			bucket = bucket->next;
		}
		if (bucket != NULL)
		{
			if (prev == NULL)
				hashTable.buckets[index] = bucket->next;
			else
				prev->next = bucket->next;
			deleteStudent(bucket->info);
			free(bucket);
		}
	}
}