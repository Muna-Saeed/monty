#include "monty.h"

void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    (void)line_number;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        return;
    }

    temp = temp->next;


    temp->prev->next = NULL;


    while (temp->next != NULL)
    {
        temp = temp->next;
    }


    temp->next = *stack;
    (*stack)->prev = temp;

    *stack = temp->next;

}
