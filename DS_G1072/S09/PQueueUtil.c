#include "Shared.h"

void ReheapDown(PQueue* pQueue, int parentIndex)
{
	if (parentIndex < PQUEUE_SIZE)
	{
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndex = 2 * parentIndex + 2;
		int minIndex = parentIndex;
		if (leftChildIndex < pQueue->currentPosition)
		{
			if (pQueue->items[minIndex]->income > pQueue->items[leftChildIndex]->income)
				minIndex = leftChildIndex;
			if (rightChildIndex < pQueue->currentPosition &&
				pQueue->items[minIndex]->income > pQueue->items[rightChildIndex]->income)
				minIndex = rightChildIndex;
			if (minIndex != parentIndex)
			{
				Student* aux = pQueue->items[minIndex];
				pQueue->items[minIndex] = pQueue->items[parentIndex];
				pQueue->items[parentIndex] = aux;
				ReheapDown(pQueue, minIndex);
			}
		}
	}
}

Student* dequeue(PQueue* pQueue)
{
	Student* result = NULL;
	if (pQueue->currentPosition > 0)
	{
		result = pQueue->items[0];
		pQueue->items[0] = pQueue->items[pQueue->currentPosition - 1];
		pQueue->currentPosition--;
		ReheapDown(pQueue, 0);
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