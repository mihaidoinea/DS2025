#include "Shared.h"

int fHash(const char* key)
{
	int position = -1;
	if (key != NULL)
	{
		position = (key[0] & 223) % HASHT_SIZE;
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
		hashTable->buckets = malloc(sizeof(Node*) * HASHT_SIZE);
		memset(hashTable->buckets, 0, sizeof(Node*) * HASHT_SIZE);
		hashTable->size = HASHT_SIZE;
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
	Student* value = NULL;
	//get index
	int index = fHash(key);
	if (index > -1)
	{
		//access the bucket based on index
		Node* bucket = hashTable.buckets[index];
		//search for the key
		while (bucket)
		{
			if (strcmp(bucket->info->name, key) == 0)
				return bucket->info;
			bucket = bucket->next;
		}
	}
	return value;
}

void printHashTable(HashTable hashTable)
{
	printf("\n--------------HashTable positions: -------------\n");
	for (int i = 0; i < HASHT_SIZE; i++)
	{
		printf("Key %d:\n", i);
		Node* bucket = hashTable.buckets[i];
		while (bucket)
		{
			printStudent(bucket->info);
			bucket = bucket->next;
		}
	}
}