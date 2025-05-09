#include "Shared.h"

void ReheapDown(PQueue* pQueue, int parentIndex)
{
	if (parentIndex < PQUEUE_SIZE)
	{
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndex = 2 * parentIndex + 2;
		int maxIndex = parentIndex;
		if (leftChildIndex < pQueue->currentIndex)
		{
			if (pQueue->items[maxIndex]->income < pQueue->items[leftChildIndex]->income)
				maxIndex = leftChildIndex;
			if (rightChildIndex < pQueue->currentIndex &&
				pQueue->items[maxIndex]->income < pQueue->items[rightChildIndex]->income)
				maxIndex = rightChildIndex;
			if (maxIndex != parentIndex)
			{
				Student* aux = pQueue->items[maxIndex];
				pQueue->items[maxIndex] = pQueue->items[parentIndex];
				pQueue->items[parentIndex] = aux;
				ReheapDown(pQueue, maxIndex);
			}
		}
	}
}

Student* dequeue(PQueue* pQueue)
{
	Student* result = NULL;
	if (pQueue->currentIndex > 0)
	{
		result = pQueue->items[0];
		pQueue->items[0] = pQueue->items[pQueue->currentIndex - 1];
		pQueue->currentIndex--;
		ReheapDown(pQueue, 0);
	}
	return result;
}

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