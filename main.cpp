#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

typedef int (*PFunc)();

// 半(奇数)ならtrue、丁(偶数)ならfalse
int GetRandomAnswer() {
	return rand() % 6 + 1;
}

// 指定された数秒待ってから関数を実行する関数
void CallBack(PFunc p, bool ans, int second) {
	printf("結果は");
	for (int i = 0; i < second; i++) {
		printf(".");
		Sleep(1000);
	}
	int num = p();
	printf("\n結果：%d\n", num);
	// 結果によって分岐
	if (ans == num % 2) {
		printf("正解！\n");
	}
	else {
		printf("残念！\n");
	}
}

int main() {
	// 乱数初期化
	srand((unsigned int)time(nullptr));

	// プレイヤーの選択
	int playerChoice;
	// 関数ポインタを宣言
	PFunc pfunc = &GetRandomAnswer;
	
	while (true) {
		printf("半(奇数)なら1、丁(偶数)なら0を入力してください。（それ以外の数字で終了） -> ");
		scanf_s("%d", &playerChoice);
		// 0か1以外なら終了
		if (playerChoice != 0 && playerChoice != 1) {
			break;
		}

		// 結果を確認
		CallBack(pfunc, (bool)playerChoice, 3);
	}
}