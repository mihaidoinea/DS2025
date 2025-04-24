#include "Shared.h"

int fHash(const char* key)
{
	int position = -1;
	if (key != NULL)
	{
		position = (key[0] & 223) % HASH_SIZE;
	}
	return position;
}
Node* createNode(Student* stud)
{
	Node* node = malloc(sizeof(Node));
	if (node != NULL)
	{
		node->info = stud;
		node->next = node->prev = NULL;
	}
	return node;
}
void putStudentByKey(HashTable* hashTable, Student* stud)
{
	if (hashTable->buckets == NULL)
	{
		hashTable->buckets = malloc(sizeof(Node*) * HASH_SIZE);
		memset(hashTable->buckets, 0, sizeof(Node*) * HASH_SIZE);
		hashTable->size = HASH_SIZE;
	}
	int index = fHash(stud->name);

	if (index > -1)
	{
		Node* node = createNode(stud);
		Node* bucket = hashTable->buckets[index];
		node->next = bucket;
		if (bucket != NULL)
			bucket->prev = node;
		hashTable->buckets[index] = node;
	}
}

Student* getStudentByKey(HashTable hashTable, const char* key)
{
	Student* result = NULL;
	//get position in array
	int index = fHash(key);
	if (index > -1 && hashTable.buckets != NULL)
	{
		//access the collision list (bucket)
		Node* bucket = hashTable.buckets[index];
		//search for the key
		while (bucket)
		{
			if (strcmp(bucket->info->name, key) == 0)
				return bucket->info;
			bucket = bucket->next;
		}
	}
	return result;
}