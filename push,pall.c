#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1; // Initialize stack pointer

/** Function
 * To push an element onto the stack
 */

void push(int value) {
	    if (top == STACK_SIZE - 1) {
		            fprintf(stderr, "Stack overflow\n");
			            exit(EXIT_FAILURE);
				        }
	        stack[++top] = value;
}

/** Function 
 * To print all elements in the stack
 */

void pall()
{
	for (int i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
}

int main() {
/** Example bytecode:
 * push 1, push 2, push 3, pall
 */
	push(1);
	push(2);
        push(3);
	pall();
		    
        return 0;
}
