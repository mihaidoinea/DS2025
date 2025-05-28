#include "Shared.h"

struct Vertex* createVertex(Student* stud)
{
	Vertex* node = malloc(sizeof(Vertex));
	node->info = stud;
	node->adjacencyList = NULL;
	node->next = NULL;
	return node;
}

void insertVertex(Vertex** Graph, Student* stud)
{
	Vertex* element = createVertex(stud);
	element->next = *Graph;
	*Graph = element;
}

Neighbour* createNeighbour(Vertex* mainVertex) {
	Neighbour* n = (Neighbour*)malloc(sizeof(Neighbour));
	n->mainVertex = mainVertex;
	n->next = NULL;
	return n;

}

void insertNeighbour(Neighbour** adjancecyList, Vertex* V) {
	Neighbour* n = createNeighbour(V);
	n->next = *adjancecyList;
	*adjancecyList = n;

}

Vertex* findVertex(Vertex* graph, int src) {

	while (graph) {
		if (graph->info->id == src) {
			return graph;
		}
		graph = graph->next;
	}
	return NULL;
}

void addEdge(Vertex* Graph, int src, int dst)
{
	Vertex* srcV = findVertex(Graph, src);
	Vertex* dstV = findVertex(Graph, dst);
	if (srcV != NULL && dstV != NULL) {
		insertNeighbour(&srcV->adjacencyList, dstV);
		insertNeighbour(&dstV->adjacencyList, srcV);
	}
}