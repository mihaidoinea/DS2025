#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256

void main()
{
	Vertex* graph = NULL;

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		short index = 0;
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

			//O(1)
			insertVertex(&graph, stud, index++);
		}
		
		addEdge(&graph, 2, 34);
		addEdge(&graph, 2, 18);
		addEdge(&graph, 18, 12);
		addEdge(&graph, 18, 23);
		addEdge(&graph, 23, 12);
		addEdge(&graph, 23, 34);
		addEdge(&graph, 34, 12);

		Vertex* tmp = graph;
		while (tmp)
		{
			printStudent(tmp->info);
			printf("Start Neighbours:\n");
			Neighbour* tmpN = tmp->adjacentList;
			while (tmpN)
			{
				printStudent(tmpN->mainVertex->info);
				tmpN = tmpN->nextNeighbour;
			}
			tmp = tmp->next;
			printf("End Neighbours\n");
		}



		graphTraversal(graph, index, 0);
		graphTraversal(graph, index, 1);
		graphTraversal(graph, index, 2);
		graphTraversal(graph, index, 3);
		graphTraversal(graph, index, 4);

	}
}