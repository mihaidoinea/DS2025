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
		pQueue->position = 0;
	}
	if ((*pQueue).size <= (*pQueue).position)
	{
		Student** oldItems = NULL;
		pQueue->items = realloc(oldItems = pQueue->items, 2 * pQueue->size * sizeof(Student*));
		if (pQueue->items == NULL)
		{
			pQueue->items = oldItems;
		}
		pQueue->size *= 2;
	}
	//(*pQueue).items[(*pQueue).position] = info;
	pQueue->items[pQueue->position] = info;
	ReheapUp((*pQueue).items, (*pQueue).position);
	(*pQueue).position++;
}

void changePrio(struct PQueue* pQueue, int index, int newPrio)
{
	if (index < pQueue->position)
	{
		int oldGroup = pQueue->items[index]->group;
		pQueue->items[index]->group = newPrio;
		if (newPrio > oldGroup)
			ReheapUp(pQueue->items, index);
		else
			ReheapDown(pQueue, index);
	}
}