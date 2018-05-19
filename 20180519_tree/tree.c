#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

Tree *newTree() {
	Tree *output = (Tree *)malloc(sizeof(Tree));
	output->left = NULL;
	output->right = NULL;
	return output;
}

void add_left(Tree **root, int data) {

	Tree *add = newTree();
	add->up = (*root);
	add->data = data;
	(*root)->left = add;
}

void add_right(Tree **root, int data) {

	Tree *add = newTree();
	add->up = (*root);
	add->data = data;
	(*root)->right = add;
}

void goto_right(Tree **root, int num) {

	int a;

	for (a = 0; a < num; a++) {
		(*root) = (*root)->right;
	}
}

int goto_endright(Tree **root) {

	int count = 0;

	while ((*root)->right != NULL) {
		count++;
		(*root) = (*root)->right;
	}
	return count;
}

int check_samenum(Tree *root, int checknum) {

	int check = 0;
	while (root != NULL) {
		if (root->data == checknum) {
			check = 1;
			break;
		}
		root = root->right;
	}
	return check;
}


void goto_up(Tree **root, int num) {

	int a;

	for (a = 0; a < num; a++) {
		(*root) = (*root)->up;
	}
	while ((*root)->data != -1) {
		(*root) = (*root)->up;
	}
}


void free_tree(Tree *root) {

	if (root->left != NULL) {
		free_tree(root->left);
	}
	if (root->right != NULL) {
		free_tree(root->right);
	}
	free(root);
}


void postorder_print(Tree *root) {

	if (root->left == NULL && root->right == NULL) {
		printf("post_print, %d\n", root->data);
		return NULL;
	}

	if (root->left != NULL) {
		postorder_print(root->left);
	}
	if (root->right != NULL) {
		postorder_print(root->right);
	}
	printf("post_print, %d\n", root->data);	
}

void preorder_print(Tree *root) {

	printf("pre_print, %d\n", root->data);

	if (root->left != NULL) {
		preorder_print(root->left);
	}
	if (root->right != NULL) {
		preorder_print(root->right);
	}
}




