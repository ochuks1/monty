#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
  * main - monty code interpreter
  * @argc: number of arguments
  * @argv: monty file location
  * Return: 0 on success
  */
int main(int argc, char *argv[])
{
	char *content = NULL;
	FILE *file;
	ssize_t read_line;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read_line > clean_line(content)) != -1)
	{
		if (read_line == 0)
	{
		continue;
	}
		 content = malloc(read_line + 1);
        if (!content) 
	{
            fprintf(stderr, "Error: Unable to allocate memory\n");
            exit(EXIT_FAILURE);
	}
	 if (fgets(content, read_line + 1, file) == NULL) 
	 {
            fprintf(stderr, "Error: Unable to read line from file\n");
            free(content);
            exit(EXIT_FAILURE);
	 }
		counter++;
		execute(content, &stack, counter, file);
		free(content);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
