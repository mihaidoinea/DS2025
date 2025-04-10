#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256
#define MAX_STUDENTS 10
void main()
{
	Node* list = NULL;
	Student** vector = NULL;

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		char buffer[LINE_SIZE], name[LINE_SIZE];
		char* token; float income; int group;
		int noStuds = 0;

		char delimiter[] = { ',','\0' };
		while (fgets(buffer, LINE_SIZE, pFile))
		{
			token = strtok(buffer, delimiter);
			strcpy(name, token);

			token = strtok(NULL, delimiter);
			group = atoi(token);

			token = strtok(NULL, delimiter);
			income = (float)atof(token);

			Student* stud = createStudent(name, group, income);
			insertStud(&vector, stud, &noStuds);
		}

		//1. compute the income amplitude for the elements in the array
		//float amplitude = 0.0;
		//computeAmplitude(vector, &amplitude);
		//printf("Amplitude value: %.2f\n", amplitude);

		//2. compute the number of times the maximum value appears in the
		// array in O(n) complexity
		//int frequency = 0;
		//frequency = computeMaxFrequency(vector);
		//printf("Maximum frequency: %.2f\n", frequency);

		//1. & 2.
		//convert the array into a circular simple linked list 
		//and display the list afterwards

	}
}

