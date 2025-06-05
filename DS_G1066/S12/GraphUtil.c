#include "Shared.h"

Vertex* CreateVertex(Student* stud)
{
	Vertex* node = NULL;
	node = malloc(sizeof(Vertex));
	node->info = stud;
	node->adjacencyList = NULL;
	node->next = NULL;


	return node;
}
void insertVertex(Vertex** graph, Student* stud,short vertex_id)
{
	Vertex* node=CreateVertex(stud);
	if (node != NULL)
	{
		node->next = *graph;
		*graph = node;
		node->vetex_id = vertex_id;
	}


}

void convertAdjacencyListToMatrix(Vertex* graph, short noVertices, int*** matrix) {
	(*matrix) = malloc(noVertices * sizeof(int*));
	for (int i = 0; i < noVertices; i++) {
		(*matrix)[i] = malloc(noVertices * sizeof(int));
		memset((*matrix)[i], 0, noVertices * sizeof(int));
	}
	while (graph)
	{
		printf("\n");
		printStudent(graph->info);
		printf("Start Neighbours:\n");
		Neighbour* tmpN = graph->adjacencyList;
		while (tmpN)
		{
			printStudent(tmpN->mainVertex->info);
			(*matrix)[graph->vetex_id][tmpN->mainVertex->vetex_id] = 1;
			tmpN = tmpN->next;
		}
		graph = graph->next;
		printf("End Neighbours\n");
	}
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
void addEdge(Vertex* Graph, int src, int dst)
{
	Vertex* srcV = findVertex(Graph, src);
	Vertex* dstV = findVertex(Graph, dst);
	if (srcV != NULL && dstV != NULL) {
		insertNeighbour(&srcV->adjacencyList, dstV);
		insertNeighbour(&dstV->adjacencyList, srcV);
	}
}




