#include "Shared.h"

void ReheapDown(Student** items, int currentIndex)
{
	if (currentIndex < PQUEUE_SIZE)
	{
		int leftD = 2 * currentIndex + 1;
		int rightD = 2 * currentIndex + 2;

	}
}

Student* dequeue(PQueue* pQueue)
{
	Student* result = NULL;
	if (pQueue->currentPosition >= 0)
	{
		result = pQueue->items[0];
		pQueue->items[0] = pQueue->items[pQueue->currentPosition - 1];
		ReheapDown(pQueue->items, 0);
		pQueue->currentPosition--;
	}
	return result;
}

void ReheapUp(Student** items, int index)
{
	if (index > 0)
	{
		int parent = (index - 1) / 2;
		if (items[index]->income < items[parent]->income)
		{
			Student* tmp = items[index];
			items[index] = items[parent];
			items[parent] = tmp;
			ReheapUp(items, parent);
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
		pQueue->currentPosition = 0;
	}

	if (pQueue->currentPosition < pQueue->size)
	{
		pQueue->items[pQueue->currentPosition] = stud;
		ReheapUp(pQueue->items, pQueue->currentPosition);
		pQueue->currentPosition++;
	}
}