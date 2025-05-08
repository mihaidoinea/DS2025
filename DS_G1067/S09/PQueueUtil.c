#include "Shared.h"

void ReheapUp(Student** items, int childIndex)
{
	if (childIndex > 0)
	{
		int parentIndex = (childIndex - 1) / 2;
		if (items[parentIndex]->income < items[childIndex]->income)
		{
			Student* tmp = items[parentIndex];
			items[parentIndex] = items[childIndex];
			items[childIndex] = tmp;
			ReheapUp(items, parentIndex);
		}
	}
}

void enqueue(PQueue* pQueue, Student* stud)
{
	if (pQueue->items == NULL)
	{
		pQueue->items = malloc(sizeof(Student*) * PQUEUE_SIZE);
		memset(pQueue->items, 0, sizeof(Student*) * PQUEUE_SIZE);
		pQueue->size = PQUEUE_SIZE;
		pQueue->currentIndex = 0;
	}
	if (pQueue->currentIndex < pQueue->size)
	{
		pQueue->items[pQueue->currentIndex] = stud;
		ReheapUp(pQueue->items, pQueue->currentIndex);
		pQueue->currentIndex++;
	}
}