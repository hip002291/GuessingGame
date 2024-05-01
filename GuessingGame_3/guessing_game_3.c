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
  printf("%d～%dの間で数値を入力してください：", ANSWER_MIN, ANSWER_MAX);
  int index = 0;
  int player_input = 0;
  char input[INPUT_SIZE_MAX];
  scanf_s("%s", input, INPUT_SIZE_MAX); //文字列入力
  while (strlen(input) > ANSWER_DIGITS) {
	  printf("%d桁以上の数字を入力しないでください", ANSWER_DIGITS);
	  scanf_s("%s", input, INPUT_SIZE_MAX);
  }
  while (input[index] != '\0') { //1文字ずつ確認
    if ((input[index] < '0') || (input[index] > '9')) { //0~9の文字定数以外が出たら
	  BufferClear();
	  printf("数字以外を入力しないでください\n");
	  printf("再入力：");
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
  if ((player_input < ANSWER_MIN) || (player_input > ANSWER_MAX)) { //入力が範囲を超えていないか確認
	  printf("入力された数値が%d～%dの範囲を超えています\n", ANSWER_MIN, ANSWER_MAX);
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

  printf("あなたが正解までに入力した回数は%dです\n", input_count);
}

int main(void) {
  srand((unsigned int)time(NULL));

  GuessingGame();
  return 0;
}