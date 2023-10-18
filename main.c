#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	stack_t *stack = NULL;
	char *line = NULL;
	size_t line_len = 0;
	ssize_t read;

	while ((read = getline(&line, &line_len, file)) != -1)
	{
		unsigned int line_number = 1; // Update line number accordingly

		char *opcode = strtok(line, " \t\n");
		if (opcode != NULL)
		{
			instruction_t instruction;

			instruction.opcode = opcode;
			instruction.f = NULL; // Set the function pointer to NULL initially

			// Determine the appropriate function pointer based on opcode
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

		line_number++; // Increment line number for each line read
	}

	fclose(file);
	free(line);

	// Clean up the stack if needed

	return EXIT_SUCCESS;
}
