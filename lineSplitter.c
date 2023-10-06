#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#define TRUE 1

#include <string.h>

char **lineSplitter(char *string)
{
	char *token;
	char **tokens = NULL;
	int i = 0;

	token = strtok(string, " \t\n");

	while (token != NULL)
	{
		i++;
		tokens = realloc(tokens, sizeof(char *) * i);
		if (tokens == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		tokens[i - 1] = strdup(token);
		if (tokens[i - 1] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " \t\n");
	}

	for (i = 0; tokens[i]; i++)
		printf("%s\n", tokens[i]);

	return (tokens);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	char *lineBuffer = NULL;
	size_t bufferSize = 0;
	int characters;

	char **tokens;

	(void)tokens;

	while (TRUE)
	{
		write(1, "$ ", 2);

		characters = getline(&lineBuffer, &bufferSize, stdin);

		if (characters == EOF)
			perror("getline");

		lineBuffer[characters - 1] = '\0';

		tokens = lineSplitter(lineBuffer);

		/*write(1, lineBuffer, bufferSize);
		write(1, "\n", 1);*/
	}

	/* free(lineBuffer); */

	return (0);
}
