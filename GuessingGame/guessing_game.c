#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(NULL)); //�����̎�𐶐�

	int pc_num = rand() % 100 + 1; //PC�����߂��C�ӂ̐��l

	int p_num = -1; //�v���C���[�̐��l
	int count = 0; //���͉�

	while (p_num!=pc_num) {
		printf("1�`100�̊ԂŐ��l����͂��Ă��������F");
		scanf_s("%d", &p_num);
		count++;

		if (p_num > pc_num) {
			printf("Big\n");
		}
		else if (p_num < pc_num) {
			printf("Small\n");
		}

	}

	printf("Bingo!\n");
	printf("�����܂łɓ��͂����񐔂�%d�ł�\n", count);

	return 0;
}