typedef struct tree {
	int data;
	int type;		//0 = File, 1 = Folder
	struct tree *up, *left, *right;
}Tree;

typedef struct stack {
	int data;
	struct stack *next, *before;
}Stack;

//function from system_init.c
void show_menu();
void filesystem_init(Tree **root);
void add(Tree **root);
void del(Tree **root);
void cd(Tree **root, Stack *cur_pos);

//function from tree.c
Tree *newTree();
void add_left(Tree **root, int data);
void add_right(Tree **root, int data);
void goto_right(Tree **root, int num);
int goto_endright(Tree **root);
int check_samenum(Tree *root, int checknum);
void goto_up(Tree **root, int num);
void free_tree(Tree *root);
void postorder_print(Tree *root);
void preorder_print(Tree *root);

//function from stack.c
Stack *newStack();
void stack_push(Stack *head, int num);
void stack_pop(Stack *head);
void stack_gotolast(Stack **head);
void stack_print(Stack *head);

//function from filesystem.c
void add_node(Tree **cur, int data, int type);
void del_node(Tree **cur);
void show_curfolder(Tree **cur);
void show_onlyfolder(Tree *cur);
void goto_num(Tree **cur, int num);

