#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char *line = NULL;
	size_t line_len = 0;
	ssize_t read;
	unsigned int line_number;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Update line number accordingly */
	line_number= 1;

	while ((read = getline(&line, &line_len, file)) != -1)
	{
		char *opcode = strtok(line, " \t\n");
		if (opcode != NULL)
		{
			instruction_t instruction;
			instruction.opcode = opcode;
			instruction.f = NULL;

			if (strcmp(opcode, "push") == 0)
				instruction.f = push;
			else if (strcmp(opcode, "pall") == 0)
				instruction.f = pall;

			if (instruction.f != NULL)
				instruction.f(&stack, line_number);
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				fclose(file);
				free(line);
				exit(EXIT_FAILURE);
			}
		}

		line_number++;
	}

	fclose(file);
	free(line);

	/* Clean up the stack if needed */

	return EXIT_SUCCESS;
}
