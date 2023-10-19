#include "monty.h"
#include <string.h>

int queue_mode = 0;
int stack_mode = 0;

void stack(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;

    /* Set mode to stack (LIFO) */
    queue_mode = 0;
}

void queue(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;

    /* Set mode to queue (FIFO) */
    queue_mode = 1;

    /* Swap elements to reflect queue behavior */
    if (*stack != NULL && (*stack)->next != NULL)
    {
        stack_t *temp = *stack;
        while (temp->next != NULL)
            temp = temp->next;
        rear = temp;

        /* Swap top and rear */
        temp->next = *stack;
        (*stack)->prev = temp;
        *stack = rear;
        rear = rear->prev;
        (*stack)->prev = NULL;
        temp->next->next = NULL;
    }
}
