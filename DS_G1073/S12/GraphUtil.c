#include "Shared.h"

Vertex* createVertex(Student* stud)
{
	Vertex* newNode = NULL;
	newNode = malloc(sizeof(Vertex));
	if (newNode != NULL)
	{
		newNode->info = stud;
		newNode->adjacencyList = NULL;
		newNode->next = NULL;
	}
	return newNode;
}

void insertVertex(Vertex** graph, Student* stud)
{
	Vertex* node = createVertex(stud);
	node->next = *graph;
	*graph = node;

}
Vertex* findVertex(Vertex* graph, int id) {
	Vertex* tmp = graph;
	while (tmp != NULL) {
		if (tmp->info->id == id) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}
Neighbour* createNeighbour(Vertex* vertex) {
	Neighbour* neighbour = NULL;
	neighbour = malloc(sizeof(Neighbour));
	neighbour->mainVertex = vertex;
	neighbour->next = NULL;

	return neighbour;
}

void insertNeighbour(Neighbour** adjList, Vertex* vert) {
	Neighbour* neighbour = createNeighbour(vert);
	neighbour->next = (*adjList);
	(*adjList) = neighbour;
};

void addEdge(Vertex** graph, int src, int dst)
{
	Vertex* srcV = findVertex(*graph, src);
	Vertex* destV = findVertex(*graph, dst);
	if (srcV != NULL && destV != NULL) {
		insertNeighbour(&(srcV->adjacencyList), destV);
		insertNeighbour(&(destV->adjacencyList), srcV);
		
	}

}



