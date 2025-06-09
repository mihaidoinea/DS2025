#include "Shared.h"

Vertex* createVertex(Student* stud)
{
	Vertex* node = malloc(sizeof(Vertex));
	node->info = stud;
	node->adjacencyList = NULL;
	node->next = NULL;
	return node;
}

void insertVertex(Vertex** Graph, Student* stud, short vertexId)
{
	Vertex* node = createVertex(stud);
	node->next = *Graph;
	node->vertexId = vertexId;
	*Graph = node;
}

Vertex* findVertex(Vertex* graph, int src){
	
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
void addEdge(Vertex** Graph, int src, int dst)
{
	Vertex* srcV = findVertex(*Graph, src);
	Vertex* dstV = findVertex(*Graph, dst);
	if (srcV != NULL && dstV != NULL) {
		insertNeighbour(&srcV->adjacencyList, dstV);
		insertNeighbour(&dstV->adjacencyList, srcV);
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
			(*matrix)[graph->vertexId][tmpN->mainVertex->vertexId] = 1;
			tmpN = tmpN->next;
		}
		graph = graph->next;
		printf("End Neighbours\n");
	}
}

void graphTraversal(int** matrix, short noVertices, short startVertex)
{

	int last = -1, first = 0;
	int* queue = (int*)malloc(sizeof(int) * noVertices);
	int* visited = (int*)malloc(sizeof(int) * noVertices);
	memset(visited, 0, sizeof(int) * noVertices);

	queue[++last] = startVertex;
	visited[startVertex] = 1;
	printf("\n");

	while (last >= first)
	{
		for (int i = 0; i < noVertices; i++)
		{
			if (visited[i] == 0 && matrix[queue[first]][i] == 1)
			{
				queue[++last] = i;
				visited[i] = 1;
			}
		}
		printf("%3d ", queue[first++]);
	}
}