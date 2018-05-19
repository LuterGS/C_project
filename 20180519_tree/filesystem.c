#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

void add_node(Tree **cur, int data, int type) {

	int count = 0;

	if (check_samenum((*cur), data) == 1) {
		printf("같은 숫자가 존재합니다.\n");
		return NULL;
	}
	count = goto_endright(cur, data);
	add_right(cur, data);
	(*cur)->right->data = data;
	(*cur)->right->type = type;

	if (type == 0) {
	}
	else if (type == 1) {
		add_left(&((*cur)->right), -1);
	}
	goto_up(cur, count);
}

void del_node(Tree **cur) {

	Tree *middle, *right;

	middle = (*cur);
	right = (*cur)->right;

	(*cur) = (*cur)->up;
	(*cur)->right = right;

	if (right != NULL) {
		right->up = (*cur);
	}

	if (middle->left != NULL) {
		free_tree(middle->left);
	}
	free(middle);
}

void show_curfolder(Tree **cur) {
	
	Tree *temp = (*cur);
	int i = 0;

	while (temp != NULL) {
		printf("%d, ", i);
		if (temp->left != NULL) {
			printf("Type : Folder");
		}
		else {
			printf("Type : File");
		}
		printf(", Data : %d\n", temp->data);
		i++;
		temp = temp->right;
	}
}


void show_onlyfolder(Tree *cur) {

	int i = 0;
	while (cur->right != NULL) {
		if (cur->left != NULL) {
			printf("%d, Folder, Data : %d\n", i, cur->data);
		}
		i++;
		cur = cur->right;
	}
}


void goto_num(Tree **cur, int num) {

	int a;
	for (a = 0; a < num; a++) {
		(*cur) = (*cur)->right;
	}
	(*cur) = (*cur)->left;
}