// 
// CSE3081-2 Sogang University
//

#include <stdio.h>
#include <stdlib.h>

#define PRINT_SPACES(N) printf("%*s", 5 * (N), "");

void try_recursive_version(int, int);
void try_iterative_version(int, int);

void main(void) {
	try_recursive_version(0, 31);
	try_iterative_version(0, 31);
}

//////////////////// Recursive ///////////////////////////

void recursive_merge(int low, int high, int level) {
	if (low == high) {
		PRINT_SPACES(level);
		printf("(L%d) Do nothing [%d,%d]\n", level, low, high);
	}
	else {
		int mid;

		mid = (low + high) / 2;
		
		PRINT_SPACES(level);
		printf("(L%d) Divide [%d, %d] --> [%d, %d] and [%d, %d]\n", level, low, high, low, mid, mid+1, high);
		recursive_merge(low, mid, level+1);
		recursive_merge(mid + 1, high, level + 1);	
		PRINT_SPACES(level);
		printf("(L%d) Merge [%d, %d] and [%d, %d] --> [%d, %d]\n", level, low, mid, mid + 1, high, low, high);
	}
}

void try_recursive_version(int low, int high) {
	printf("\n***** START OF RECURSIVE VERSION *****\n\n");
	recursive_merge(low, high, 0);
	printf("\n***** END OF RECURSIVE VERSION *****\n\n");
}

//////////////////// Iterative using stack ///////////////////////////

#define BEFORE_DIVIDE	0
#define AFTER_DIVIDE	1

#define MAX_STACK_ELEMENTS 32
typedef struct {
	int low, high;
	int state; // 0: Before divide, 1: After divide
	int level;
} STACK_ELEMENT;

STACK_ELEMENT stack[MAX_STACK_ELEMENTS];
static int stack_pointer;

void initialize_stack(void) {
	stack_pointer = -1;
}

bool is_stack_empty(void) {
	if (stack_pointer < 0)
		return true;
	else
		return false;
}

void push(int low, int high, int state, int level) {
	if (++stack_pointer >= MAX_STACK_ELEMENTS) {
		printf("*** Error: Stack overflow...\n");
		exit(-1);
	}
	stack[stack_pointer].low = low;
	stack[stack_pointer].high = high;
	stack[stack_pointer].state = state;
	stack[stack_pointer].level = level;
}

void pop(STACK_ELEMENT *stack_element) {
	stack_element->low = stack[stack_pointer].low;
	stack_element->high = stack[stack_pointer].high;
	stack_element->state = stack[stack_pointer].state;
	stack_element->level = stack[stack_pointer].level;
	stack_pointer--;
}

void iterative_merge(int low, int high, int level) {
	STACK_ELEMENT s_e;

	initialize_stack();
	push(low, high, BEFORE_DIVIDE, level);
	while (!is_stack_empty()) {
		pop(&s_e);

		if (s_e.low == s_e.high) {
			PRINT_SPACES(s_e.level);
			printf("(L%d) Do nothing [%d, %d]\n", s_e.level, s_e.low, s_e.high);
		}
		else {
			int mid;

			if (s_e.state == BEFORE_DIVIDE) {
				push(s_e.low, s_e.high, AFTER_DIVIDE, s_e.level);

				mid = (s_e.low + s_e.high) / 2;
				PRINT_SPACES(s_e.level);
				printf("(L%d) Divide [%d, %d] --> [%d, %d] and [%d, %d]\n", s_e.level, s_e.low, s_e.high, s_e.low, mid, mid + 1, s_e.high);

				push(mid + 1, s_e.high, BEFORE_DIVIDE, s_e.level + 1);
				push(s_e.low, mid, BEFORE_DIVIDE, s_e.level + 1); // CAN YOU GET RID OF THIS PUSH OPERATION? IF YES, HOW?
			}
			else { // s_e.state == AFTER_DIVIDE
				mid = (s_e.low + s_e.high) / 2;
				PRINT_SPACES(s_e.level);
				printf("(L%d) Merge [%d, %d] and [%d, %d] --> [%d, %d]\n", s_e.level, s_e.low, mid, mid + 1, s_e.high, s_e.low, s_e.high);
			}
		}
	}
}

void try_iterative_version(int low, int high) {
	printf("\n***** START OF ITERATIVE VERSION *****\n\n");
	iterative_merge(low, high, 0);
	printf("\n***** END OF ITERATIVE VERSION *****\n\n");
}
