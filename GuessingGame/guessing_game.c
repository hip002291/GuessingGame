#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(NULL)); //乱数の種を生成

	int pc_num = rand() % 100 + 1; //PCが決めた任意の数値

	int p_num = -1; //プレイヤーの数値
	int count = 0; //入力回数

	while (p_num!=pc_num) {
		printf("1～100の間で数値を入力してください：");
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
	printf("正解までに入力した回数は%dです\n", count);

	return 0;
}