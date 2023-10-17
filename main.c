#include "monty.h"

instruction_t get_instruction(char *opcode)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	int i = 0;
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return instructions[i];
		i++;
	}

	/* Return a default instruction if opcode not found */
	return (instructions[i]);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	char line[100];
	unsigned int line_number = 0;

	stack_t *stack = NULL;
	instruction_t instruction;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;

		/* Tokenize the line */
		char *opcode = strtok(line, " \t\n");
		if (!opcode)
			/* Empty line, skip to the next iteration */
			continue;

		/* Get the corresponding instruction */
		instruction = get_instruction(opcode);
		if (!instruction.f)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			return (EXIT_FAILURE);
		}

		/* Executes the instruction's function */
		instruction.f(&stack, line_number);
	}

	fclose(file);
	return (EXIT_SUCCESS);
}
