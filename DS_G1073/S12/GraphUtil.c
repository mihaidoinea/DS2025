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

void insertVertex(Vertex** graph, Student* stud, short vertexId)
{
	Vertex* node = createVertex(stud);
	node->next = *graph;
	node->vertexId = vertexId;
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

