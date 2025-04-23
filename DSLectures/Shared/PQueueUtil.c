#include "Shared.h"
void ReheapUp(Student** items, int currentIndex)
{
	if (currentIndex > 0)
	{
		int parentIndex = (currentIndex - 1) / 2;
		if (strlen(items[parentIndex]->name) <
			strlen(items[currentIndex]->name))
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