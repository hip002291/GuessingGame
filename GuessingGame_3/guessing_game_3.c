#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ANSWER_MIN 1
#define ANSWER_MAX 100
#define ANSWER_DIGITS 3
#define INPUT_SIZE_MAX ANSWER_DIGITS+1
#define TRUE 1
#define FALSE 0

void BufferClear() {
  char s;
  do {
	s = getchar();
  } while (s !='\n');
}

int InputNum() {
  printf("%d�`%d�̊ԂŐ��l����͂��Ă��������F", ANSWER_MIN, ANSWER_MAX);
  int index = 0;
  int player_input = 0;
  char input[INPUT_SIZE_MAX];
  scanf_s("%s", input, INPUT_SIZE_MAX); //���������
  while (strlen(input) > ANSWER_DIGITS) {
	  printf("%d���ȏ�̐�������͂��Ȃ��ł�������", ANSWER_DIGITS);
	  scanf_s("%s", input, INPUT_SIZE_MAX);
  }
  while (input[index] != '\0') { //1�������m�F
    if ((input[index] < '0') || (input[index] > '9')) { //0~9�̕����萔�ȊO���o����
	  BufferClear();
	  printf("�����ȊO����͂��Ȃ��ł�������\n");
	  printf("�ē��́F");
	  index = 0;
	  player_input = 0;
    }
	player_input *= 10;
	player_input += input[index] - '0';
	index++;
  }

  return player_input;
}

int JudgeNum(int player_input) {
  if ((player_input < ANSWER_MIN) || (player_input > ANSWER_MAX)) { //���͂��͈͂𒴂��Ă��Ȃ����m�F
	  printf("���͂��ꂽ���l��%d�`%d�͈̔͂𒴂��Ă��܂�\n", ANSWER_MIN, ANSWER_MAX);
    return FALSE;
  }
  return TRUE;
}

int CheckAnswer(int player_input, int ans) {
  if ((player_input > ans) && (player_input > 0)) {
    printf("Big\n");
  }
  else if ((player_input < ans) && (player_input > 0)) {
    printf("Small\n");
  }
  else if (player_input == ans) {
	printf("Bingo!\n");
	return TRUE;
  }

  return FALSE;
}

void GuessingGame() {
  int ans = (rand() % ANSWER_MAX) + 1;
  int player_input = -1;
  int input_count = 0;

  while (CheckAnswer(player_input, ans) == FALSE) {
	player_input = InputNum();
	while (JudgeNum(player_input) == FALSE) {
      player_input = InputNum();
	}
	input_count++;
  }

  printf("���Ȃ��������܂łɓ��͂����񐔂�%d�ł�\n", input_count);
}

int main(void) {
  srand((unsigned int)time(NULL));

  GuessingGame();
  return 0;
}