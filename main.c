#include "monty.h"
#include <string.h>


/**
 * get_instruction - function gets instructions
 * @opcode: str type opcode
 * Return: fucction of type instructions
 */
instruction_t get_instruction(char *opcode)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"nop", nop},
		{"stack", stack},
		{"queue", queue},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return (instructions[i]);
		i++;
	}
	if (*opcode == '#')
		return (instructions[12]);
	/* Return a default instruction if opcode not found */
	return (instructions[i]);
}
/**
 * free_mem - frees memory
 * @stack: adress of the stack list
 */
void free_mem(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
		return;

	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
/**
 * main - main function of the program
 * @argc: the size
 * @argv: array of inputs
 * Return: status
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char line[100], *opcode;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t instruction;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t$\n");
		if (!opcode)
			continue;

		instruction = get_instruction(opcode);
		if (!instruction.f)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			return (EXIT_FAILURE);
		}
		instruction.f(&stack, line_number);
	}

	fclose(file);
	free_mem(&stack);
	return (EXIT_SUCCESS);
}
