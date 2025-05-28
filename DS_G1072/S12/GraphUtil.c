#include "Shared.h"

Vertex* createNode(Student* info) {
	Vertex* newNode = malloc(sizeof(Vertex));
	if (newNode != NULL) {
		newNode->info = info;
		newNode->next = NULL;
		newNode->adjacentList = NULL;
	}
	return newNode;
}

void insertVertex(Vertex** graph, Student* info)
{
	Vertex* node = createNode(info);
	node->next = (*graph);
	(*graph) = node;
}

Vertex* findVertex(Vertex* graph,int dst)
{
	while (graph)
	{
		if (graph->info->id == dst)
			return graph;
		
		graph = graph->next;
	}
	return NULL;
}

void addEdge(Vertex** graph,int src, int dst)
{
	Vertex* srcV = findVertex(*graph, src);
	Vertex* dstV = findVertex(*graph, dst);
	if (srcV != NULL && dstV != NULL)
	{
		Neighbour* newNode = malloc(sizeof(Neighbour));
		newNode->mainVertex = dstV;
		newNode->nextNeighbour = srcV->adjacentList;
		srcV->adjacentList = newNode;

		newNode = malloc(sizeof(Neighbour));
		newNode->mainVertex = srcV;
		newNode->nextNeighbour = dstV->adjacentList;
		dstV->adjacentList = newNode;
	}
}



