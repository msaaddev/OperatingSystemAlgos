/* ==============================================
        Author: Muhammad Saad
        Section: A
        Registration Number: 2018-CS-7
        Programming Language: C
=================================================*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *readFilePtr, *writeFilePtr;

	// char arrays to store data
	char fileName[50];
	char bufferArr[1000];

	printf("Name of the file from where you wish to read data: ");
	scanf("%s", fileName);

	// Opening the file for reading data
	readFilePtr = fopen(fileName, "r");
	if (readFilePtr == NULL)
	{
		printf("ERROR: \n Cannot open file %s .....\n", fileName);
		exit(0);
	}

	printf("Name of the file from where you want to write data: ");
	scanf("%s", fileName);

	// Opening the file for writing data
	writeFilePtr = fopen(fileName, "w");
	if (writeFilePtr == NULL)
	{
		printf("ERROR: \n Cannot open file %s \n", fileName);
		exit(0);
	}

	// writing data into file
	while (fgets(bufferArr, 1000, readFilePtr) != NULL)
	{
		fputs(bufferArr, writeFilePtr);
	}

	printf("\nSuccessfuly copied content into %s \n", fileName);

	fclose(readFilePtr);
	fclose(writeFilePtr);

	return 0;
}
