Monty Language - README.md
This is the README file for the Monty language implementation.

Table of Contents
Introduction
Getting Started
Supported Opcodes
push
pall
pint
pop
swap
add
nop
Examples
Introduction
Monty is an interpreter for the Monty language, which is a simple stack-based programming language. This README provides an overview of the language's supported opcodes and their usage.

Getting Started
To use the Monty interpreter, follow these steps:

Clone the GitHub repository: monty.
Compile the source code using a C compiler.
Run the Monty interpreter, providing a file containing Monty bytecode instructions as input.
Supported Opcodes
The Monty interpreter supports the following opcodes:

push
The push opcode pushes an element to the stack.

Usage: push <int>

<int>: An integer value to be pushed onto the stack.
If <int> is not an integer or no argument is given to push, the interpreter will print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE.

pall
The pall opcode prints all the values on the stack, starting from the top of the stack.

Usage: pall

If the stack is empty, the pall opcode does not print anything.

pint
The pint opcode prints the value at the top of the stack, followed by a new line.

Usage: pint

If the stack is empty, the pint opcode prints the error message L<line_number>: can't pint, stack empty, followed by a new line, and exits with the status EXIT_FAILURE.

pop
The pop opcode removes the top element of the stack.

Usage: pop

If the stack is empty, the pop opcode prints the error message L<line_number>: can't pop an empty stack, followed by a new line, and exits with the status EXIT_FAILURE.

swap
The swap opcode swaps the top two elements of the stack.

Usage: swap

If the stack contains less than two elements, the swap opcode prints the error message L<line_number>: can't swap, stack too short, followed by a new line, and exits with the status EXIT_FAILURE.

add
The add opcode adds the top two elements of the stack.

Usage: add

If the stack contains less than two elements, the add opcode prints the error message L<line_number>: can't add, stack too short, followed by a new line, and exits with the status EXIT_FAILURE.

The result of the addition is stored in the second top element of the stack, and the top element is removed. At the end of the operation, the top element of the stack contains the result, and the stack is one element shorter.

nop
The nop opcode does not perform any operation.

Usage: nop

Examples
Here are some examples of Monty bytecode files and their expected output:

Example: bytecodes/00.m
Copy
push 1
push 2
push 3
pall
```
Output:
3
2
1
Copy
Example: bytecodes/06.m
Copy
push 1
pint
push 2
pint
push 3
pint
```
Output:
1
2
3
Copy
Example: bytecodes/07.m
Copy
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
```
Output:
3
2
1
2
1
1
Copy
For more examples, refer to the bytecodes directory in the monty repository.
