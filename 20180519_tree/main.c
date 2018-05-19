#include <stdio.h>
#include "declare.h"

int main() {

	Tree *root = newTree();
	Tree *root_2 = newTree();
	root->data = 0;
	root->left = root_2;
	root_2->data = -1;
	root_2->up = root;
	filesystem_init(&root_2);


}