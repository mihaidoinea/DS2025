#include "Shared.h"

void ReheapDown(struct PQueue* pQueue, int parentIndex)
{
	if (parentIndex < PQUEUE_SIZE)
	{
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndex = 2 * parentIndex + 2;
		int maxIndex = parentIndex;
		if (leftChildIndex < pQueue->position)
		{
			if (pQueue->items[maxIndex]->group <  pQueue->items[leftChildIndex]->group)
				maxIndex = leftChildIndex;
			if (rightChildIndex < pQueue->position &&
				pQueue->items[maxIndex]->group < pQueue->items[rightChildIndex]->group)
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

Student* dequeue(struct PQueue* pQueue)
{
	Student* result = NULL;
	if (pQueue->position > 0)
	{
		result = pQueue->items[0];
		pQueue->items[0] = pQueue->items[pQueue->position - 1];
		pQueue->position--;
		ReheapDown(pQueue, 0);
	}
	return result;
}

void ReheapUp(Student** items, int currentIndex)
{
	if (currentIndex > 0)
	{
		int parentIndex = (currentIndex - 1) / 2;
		if (items[parentIndex]->group <
			items[currentIndex]->group)
		{
			Student* aux = items[parentIndex];
			items[parentIndex] = items[currentIndex];
			items[currentIndex] = aux;
			ReheapUp(items, parentIndex);
		}
	}
}

void enqueue(struct PQueue* pQueue, Student* info)
{
	if ((*pQueue).items == NULL)
	{
		(*pQueue).items = (Student**)malloc(sizeof(Student*) * PQUEUE_SIZE);
		memset((*pQueue).items, 0, sizeof(Student*) * PQUEUE_SIZE);
		(*pQueue).size = PQUEUE_SIZE;
	}
	if ((*pQueue).size > (*pQueue).position)
	{
		(*pQueue).items[(*pQueue).position] = info;
		pQueue->items[pQueue->position] = info;
		ReheapUp((*pQueue).items, (*pQueue).position);
		(*pQueue).position++;
	}
}