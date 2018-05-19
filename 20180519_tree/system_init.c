#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

void show_menu() {
	printf("���ο� ����/���� 1��, ���� 2��, ls 3��, cd[����] 4��, cd .. 5��\n");
	printf("preorder ����� 6��, postorder ����� 7��, �ٽ� ���÷��� 8��, ����� 9���� �����ּ���\n");
}


void filesystem_init(Tree **root) {

	int chose;
	Stack *cur_pos = newStack();
	cur_pos->data = (*root)->up->data;
	show_menu();

	while (1) {
		stack_print(cur_pos);
		printf(" :");
		scanf_s("%d", &chose, sizeof(chose));

		if (chose == 1) {
			add(root);
		}
		else if (chose == 2) {
			del(root);
		}
		else if (chose == 3) {
			show_curfolder(root);
		}
		else if (chose == 4) {
			cd(root, cur_pos);
		}
		else if (chose == 5) {
			goto_up(root, 1);
			stack_pop(cur_pos);
		}
		else if (chose == 6) {
			preorder_print((*root));
		}
		else if (chose == 7) {
			postorder_print((*root));
		}
		else if (chose == 8) {
			show_menu();
		}
		else if (chose == 9) {
			break;
		}
	}
}


void add(Tree **root) {

	int chose, data = 0;
	printf("�߰� - ������ 1��, �����̸� 2�� : ");
	scanf_s("%d", &chose, sizeof(chose));

	if (chose == 1) {
		printf("������ ��ȣ�� �Է����ּ��� : ");
		scanf_s("%d", &data, sizeof(data));
		add_node(root, data, 1);
	}
	else if (chose == 2) {
		printf("������ ��ȣ�� �Է����ּ��� : ");
		scanf_s("%d", &data, sizeof(data));
		add_node(root, data, 0);
	}
}

void del(Tree **root) {

	int chose;
	printf("���� ��ȣ�� �Է����ּ���(0�� �Ұ�) : ");

	while (1) {
		scanf_s("%d", &chose, sizeof(chose));
		if (chose == 0) {
		}
		else {
			goto_right(root, chose);
			del_node(root);
			goto_up(root, chose - 1);
			break;
		}
	}
}

void cd(Tree **root, Stack *cur_pos) {

	int choose;
	printf("���� ��ȣ�� �����ϼ��� : ");

	while (1) {
		scanf_s("%d", &choose, sizeof(choose));
		goto_right(root, choose);
		if ((*root)->left == NULL) {
			printf("������ �ƴմϴ�! �ٽ� �Է����ּ���.\n");
			goto_up(root, choose);
		}
		else {
			break;
		}
	}
	stack_push(cur_pos, (*root)->data);
	(*root) = (*root)->left;
}