#include "monty.h"
#include <string.h>
stack_t *stack = NULL;

void push(stack_t **stack, unsigned int line_number)
{
	if (!stack)
	{
		fprintf(stderr, "Error: Stack is NULL\n");
		exit(EXIT_FAILURE);
	}

	stack_t *new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	stack_t *current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

instruction_t get_instruction(char *opcode)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		/* Add more opcodes and corresponding functions here */
		{NULL, NULL}
	};

	int i = 0;
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return instructions[i];
		i++;
	}

	return instructions[i];  // Return a default instruction if opcode not found
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return EXIT_FAILURE;
	}

	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	char line[100];
	unsigned int line_number = 0;

	stack_t *stack = NULL;
	instruction_t instruction;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;

		// Tokenize the line
		char *opcode = strtok(line, " \t\n");
		if (!opcode)
			continue;  // Empty line, skip to the next iteration

		// Get the corresponding instruction
		instruction = get_instruction(opcode);
		if (!instruction.f)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			return EXIT_FAILURE;
		}

		// Execute the instruction's function
		instruction.f(&stack, line_number);
	}

	fclose(file);
	return EXIT_SUCCESS;
}
