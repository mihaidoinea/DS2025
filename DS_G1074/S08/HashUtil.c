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
void putStudent(HashTable* hashTable, Student* stud)
{
	//space allocation
	if (hashTable->buckets == NULL)
	{
		hashTable->buckets = (Node**)malloc(sizeof(Node*) * HASH_SIZE);
		memset(hashTable->buckets, 0, sizeof(Node*) * HASH_SIZE);
		hashTable->size = HASH_SIZE;
	}
	//actual insert operation
	int index = fHash(stud->name);
	if (index > -1)
	{
		Node* node = createNode(stud);
		if (node != NULL)
		{
			Node* bucket = hashTable->buckets[index];
			node->next = bucket;
			if(bucket != NULL)
				bucket->prev = node;
			hashTable->buckets[index] = node;
		}
	}
}

Student* getStudent(HashTable hashTable, const char* key)
{
	Student* student = NULL;
	//get the index position
	int index = fHash(key);
	if (index > -1 && hashTable.buckets != NULL)
	{
		//access the bucket
		Node* bucket = hashTable.buckets[index];
		//search for the key
		while (bucket)
		{
			if (strcmp(bucket->info->name, key) == 0)
				return bucket->info;
			bucket = bucket->next;
		}
	}
	return student;
}
void deleteStudentByKey(HashTable hashTable, const char* key)
{

}
void printHashTable(HashTable hashTable)
{
	printf("\n--------------HashTable positions: -------------\n");
	for (int i = 0; i < HASH_SIZE; i++)
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