#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

void show_menu() {
	printf("새로운 파일/폴더 1번, 제거 2번, ls 3번, cd[폴더] 4번, cd .. 5번\n");
	printf("preorder 출력은 6번, postorder 출력은 7번, 다시 보시려면 8번, 종료는 9번을 눌러주세요\n");
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
	printf("추가 - 폴더면 1번, 파일이면 2번 : ");
	scanf_s("%d", &chose, sizeof(chose));

	if (chose == 1) {
		printf("폴더의 번호를 입력해주세요 : ");
		scanf_s("%d", &data, sizeof(data));
		add_node(root, data, 1);
	}
	else if (chose == 2) {
		printf("파일의 번호를 입력해주세요 : ");
		scanf_s("%d", &data, sizeof(data));
		add_node(root, data, 0);
	}
}

void del(Tree **root) {

	int chose;
	printf("지울 번호를 입력해주세요(0은 불가) : ");

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
	printf("폴더 번호를 선택하세요 : ");

	while (1) {
		scanf_s("%d", &choose, sizeof(choose));
		goto_right(root, choose);
		if ((*root)->left == NULL) {
			printf("폴더가 아닙니다! 다시 입력해주세요.\n");
			goto_up(root, choose);
		}
		else {
			break;
		}
	}
	stack_push(cur_pos, (*root)->data);
	(*root) = (*root)->left;
}