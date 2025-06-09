#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256

void main()
{
	FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		short noVertices = 0;
		char delimiter[] = { ',','\0' };
		char* token = NULL;
		float income = 0; int group = 0, id =0;
		char name[LINE_SIZE];
		char buffer[LINE_SIZE];
		Vertex* Graph = NULL;

		while (fgets(buffer, LINE_SIZE, pFile))
		{
			token = strtok(buffer, delimiter);
			id = atoi(token);

			token = strtok(NULL, delimiter);
			strcpy(name, token);

			token = strtok(NULL, delimiter);
			group = atoi(token);

			token = strtok(NULL, delimiter);
			income = (float)atof(token);

			Student* stud = createStudent(name, group, income, id);

			insertVertex(&Graph, stud, noVertices++);
		}

		addEdge(Graph, 10, 16);
		addEdge(Graph, 10, 13);
		addEdge(Graph, 10, 24);
		addEdge(Graph, 24, 16);
		addEdge(Graph, 20, 16);
		addEdge(Graph, 20, 6);
		addEdge(Graph, 20, 13);
		addEdge(Graph, 13, 6);
		addEdge(Graph, 13, 16);

		Vertex* tmp = Graph;
		while (tmp)
		{
			printStudent(tmp->info);
			printf("Start Neighbours:\n");
			Neighbour* tmpN = tmp->adjacencyList;
			while (tmpN)
			{
				printStudent(tmpN->mainVertex->info);
				tmpN = tmpN->next;
			}
			tmp = tmp->next;
			printf("End Neighbours\n");
		}

		int** matrix = NULL;
		convertAdjacencyListToMatrix(Graph, noVertices, &matrix);
		for (int i = 0; i < noVertices; i++)
		{
			for (int j = 0; j < noVertices; j++)
			{
				printf("%3d", matrix[i][j]);
			}
			printf("\n");
		}

		graphTraversal(matrix, noVertices, 0);
		graphTraversal(matrix, noVertices, 1);
		graphTraversal(matrix, noVertices, 2);
		graphTraversal(matrix, noVertices, 3);
		graphTraversal(matrix, noVertices, 4);
		graphTraversal(matrix, noVertices, 5);
	}
}