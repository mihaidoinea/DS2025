#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256

void main()
{
	FILE* pFile = fopen("Data.txt", "r");
	Vertex* graph=NULL;
	if (pFile != NULL)
	{
		char delimiter[] = { ',','\0' };
		char* token = NULL;
		float income = 0; int group = 0, id =0;
		char name[LINE_SIZE];
		char buffer[LINE_SIZE];

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
			insertVertex(&graph, stud);
		}
		addEdge(graph, 10, 16);
		addEdge(graph, 10, 13);
		addEdge(graph, 10, 24);
		addEdge(graph, 24, 16);
		addEdge(graph, 20, 16);
		addEdge(graph, 20, 6);
		addEdge(graph, 20, 13);
		addEdge(graph, 13, 6);
		addEdge(graph, 13, 16);

		Vertex* tmp = graph;
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
	}
}