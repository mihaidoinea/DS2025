#include "Shared.h"
int fHash(const char* key)
{
	int position = -1;
	if (key != NULL)
	{
		position = toupper(key[0]) % HASH_SIZE;
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

Student* getStudent(HashTable hashTable, const char* key)
{
	Student* result = NULL;
	//calculate the index
	int index = fHash(key);
	if (index > -1 && hashTable.buckets != NULL)
	{
		//get the bucket
		SNode* bucket = hashTable.buckets[index];
		//search for the key
		while (bucket != NULL && strcmp(bucket->info->name, key) != 0)
			bucket = bucket->next;
		if (bucket != NULL)
			result = bucket->info;
	}
	return result;
}
void deleteStud(HashTable hashTable, const char* key)
{
	//calculate the index
	int index = fHash(key);
	if (index > -1 && hashTable.buckets != NULL)
	{
		//get the bucket
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