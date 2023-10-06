#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#define TRUE 1

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	char *lineBuffer = NULL;
	size_t bufferSize = 0;
	int characters;

	/*while (TRUE)
	{*/
	write(1, "$ ", 2);

	characters = getline(&lineBuffer, &bufferSize, stdin);

	if (characters == EOF)
		perror("getline");

	lineBuffer[characters - 1] = '\0';

	write(1, lineBuffer, bufferSize);
	write(1, "\n", 1);
	/* } */

	/* free(lineBuffer); */

	return (0);
}
