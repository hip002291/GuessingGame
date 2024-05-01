#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ANSWER_MIN 1
#define ANSWER_MAX 100
#define INPUT_SIZE_MAX 4
#define ANSWER_DIGITS 3
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
  while (input[index] != '\0') { //1文字ずつ確認
    if ((input[index] < '0') || (input[index] > '9') || (strlen(input) > ANSWER_DIGITS)) { //0~9の文字定数以外が出たら
      printf("%d桁の数字以外を入力しないでください\n", ANSWER_DIGITS);
      printf("再入力：");
	  player_input = -1;
	  break;
	}
	player_input *= 10;
	player_input += input[index] - '0';
	index++;
  }

  BufferClear();
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
	do {
	  player_input = InputNum();
	} while (player_input == -1);
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