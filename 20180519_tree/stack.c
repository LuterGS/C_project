#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

Stack *newStack() {
	Stack *output = (Stack *)malloc(sizeof(Stack));
	output->next = NULL;
	output->before = NULL;
	return output;
}

void stack_push(Stack *head, int num) {

	Stack *temp = head;
	stack_gotolast(&temp);
	temp->next = newStack();
	temp->next->before = temp;
	temp->next->data = num;
}

void stack_pop(Stack *head) {

	Stack *temp = head;
	stack_gotolast(&temp);
	temp = temp->before;
	free(temp->next);
	temp->next = NULL;
}


void stack_gotolast(Stack **head) {

	while ((*head)->next != NULL) {
		(*head) = (*head)->next;
	}
}


void stack_print(Stack *head) {

	while (head != NULL) {
		printf("%d/", head->data);
		head = head->next;
	}
}