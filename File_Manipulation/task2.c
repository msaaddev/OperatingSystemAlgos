/* ==============================================
        Author: Muhammad Saad
        Section: A
        Registration Number: 2018-CS-7
        Programming Language: C
=================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char arr[40] = {' '};
	int fileDescriptor;

	fileDescriptor = open("file.txt", O_RDONLY);

	if (fileDescriptor < 0)
	{
		printf("\nError in reading file \n");
		exit(0);
	}

	printf("\n");
	while (read(fileDescriptor, arr, sizeof(arr)) > 0)
	{
		write(1, arr, sizeof(arr));
	}
	printf("\n");

	close(fileDescriptor);
	return 0;
}
