#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE* file1;
	FILE* file2;

	char fileName[50];
	char copyCharacter;

	printf("Please enter the name of a file to be copied.\n"); //print to console
	scanf("%s", fileName); //take in file name

	file1 = fopen(fileName, "r"); //r means read the file

	if(file1 == NULL)//error checking
	{
		printf("Invalid first file name.\n");
		exit(0);
	}

	printf("Please enter the name of the file to recieve the copy.\n");//print to console
	scanf("%s",fileName);
	
	file2 = fopen(fileName, "w");

	if(file2 == NULL)//error checking
	{
		printf("Invalid second file name.\n");
		exit(0);
	}

	printf("\n\nCopying...\n\n");

	copyCharacter = fgetc(file1);
	while(copyCharacter != EOF)
	{
		printf("%c", copyCharacter);
		fputc(copyCharacter, file2);
		copyCharacter = fgetc(file1);
	}

	printf("Contents copied!");

	fclose(file1);
	fclose(file2);

	return(0);

	
}