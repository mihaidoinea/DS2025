#include "Shared.h"

Vertex* createNode(Student* info, short id) {
	Vertex* newNode = malloc(sizeof(Vertex));
	if (newNode != NULL) {
		newNode->info = info;
		newNode->next = NULL;
		newNode->adjacentList = NULL;
		newNode->identifier = id;
	}
	return newNode;
}

void insertVertex(Vertex** graph, Student* info, short id)
{
	Vertex* node = createNode(info, id);
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

void graphTraversal(int** mat, int dim, int startVertex)
{
	int last = -1, first = 0;
	int* visited = (int*)malloc(sizeof(int) * dim);
	memset(visited, 0, sizeof(int) * dim);
	int* queue = (int*)malloc(sizeof(int) * dim);

	visited[startVertex] = 1;
	queue[++last] = startVertex;

	while (first <= last)
	{
		for (int i = 0; i < dim; i++)
		{
			if (visited[i] == 0 && mat[queue[first]][i] == 1)
			{
				queue[++last] = i;
				visited[i] = 1;
			}
		}
		printf("%3d", ++queue[first++]);
	}
	printf("\n");
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
		Neighbour* tmpN = graph->adjacentList;
		while (tmpN)
		{
			printStudent(tmpN->mainVertex->info);
			(*matrix)[graph->identifier][tmpN->mainVertex->identifier] = 1;
			tmpN = tmpN->nextNeighbour;
		}
		graph = graph->next;
		printf("End Neighbours\n");
	}
}


