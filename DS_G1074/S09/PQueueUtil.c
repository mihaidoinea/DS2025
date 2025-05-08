#include "Shared.h"

void enqueue(PQueue* pQueue, Student* stud)
{
	if (pQueue->items == NULL)
	{
		pQueue->items = malloc(sizeof(Student*) * PQUEUE_SIZE);
		memset(pQueue->items, 0, sizeof(Student*) * PQUEUE_SIZE);
		pQueue->size = PQUEUE_SIZE;
		pQueue->currentIndex = 0;
	}
}