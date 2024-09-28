#include "Delimited.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable:4996)


void readFile(const char* fileName)
{
	FILE* filePointer = fopen(fileName, "r");

	if (filePointer == NULL)
	{
		printf("\nThere was an error in opening the file");
		exit(2);
	}

	printf("\n\nID, Name, Category, Quantity, Price\n");
	char tempString[MAXCHARCOUNT];


	while (fgets(tempString, MAXCHARCOUNT, filePointer))
	{
		printf("%s", tempString);
	}


	fclose(filePointer);
}



void appendFile(struct productData* content, const char* fileName)
{

	FILE* filePointer = fopen(fileName, "a+");

	if (filePointer == NULL)
	{
		printf("\nThere was an error in opening the file");
		exit(2);
	}


	fprintf(filePointer, "%i%s%s%s%s%s%i%s%lf\n", content->id, DELIMITER, content->name, DELIMITER, content->category, DELIMITER, content->quantity, DELIMITER, content->price);


	fclose(filePointer);
}

void updateFileById(struct productData* content, const char* fileName, int id)
{
	FILE* filePointer = fopen(fileName, "r+");

	char tempString[MAXCHARCOUNT];

	if (filePointer == NULL)
	{
		printf("\nThere was an error in opening the file");
		exit(2);
	}

	while (fgets(tempString, MAXCHARCOUNT, filePointer))
	{

		if (tempString[0] == id)
		{
			fseek(filePointer, -36, SEEK_CUR);
			fwrite("", sizeof(""), 1, filePointer);
			fclose(filePointer);

			FILE* filePointer = fopen(fileName, "a+");
			if (filePointer == NULL)
			{
				printf("\nThere was an error in opening the file");
				exit(2);
			}
			fprintf(filePointer, "%i%s%s%s%s%s%i%s%lf\n", content->id, DELIMITER, content->name, DELIMITER, content->category, DELIMITER, content->quantity, DELIMITER, content->price);
			fclose(filePointer);

			break;
		}
	}


	fclose(filePointer);
}

void deleteFileContentsById(const char* fileName, int id)
{
	FILE* filePointer = fopen(fileName, "r+");

	char tempString[MAXCHARCOUNT];


	if (filePointer == NULL)
	{
		printf("\nThere was an error in opening the file");
		exit(2);
	}



	while (fgets(tempString, MAXCHARCOUNT, filePointer))
	{

		if (tempString[0] == id)
		{
			fseek(filePointer, -36, SEEK_CUR);
			fwrite("", sizeof(""), 1, filePointer);

			break;
		}
	}

	fclose(filePointer);
}

void deleteFile(const char* fileName)
{
	char userInput[3];
	printf("\n\nDelete File: %s (y/n) ", fileName);
	fgets(userInput, 3, stdin);


	if (strcmp(userInput, "y\n") == 0 || strcmp(userInput, "Y\n") == 0)
	{
		if (remove(fileName) == 0)
		{
			printf("\n\nFile Deleted\n\n");
		}

	}
}

\