#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <Windows.h>
#include <time.h>

int main() {
	// 乱数初期化
	srand((unsigned int)time(nullptr));

	// プレイヤーの選択
	int playerChoice;
	// 関数ポインタを宣言
	std::function<int()> randomAnswer = []() {return rand() % 6 + 1; };
	std::function<void(std::function<int()>, bool, int)> callBack = [](std::function<int()> func, bool ans, int second) {
		printf("結果は");
		for (int i = 0; i < second; i++) {
			printf(".");
			Sleep(1000);
		}
		int num = func();
		printf("%d\n", num);
		// 結果によって分岐
		if (ans == num % 2) {
			printf("正解！\n");
		}
		else {
			printf("残念！\n");
		}
	};
	
	while (true) {
		printf("半(奇数)なら1、丁(偶数)なら0を入力してください。（それ以外の数字で終了） -> ");
		scanf_s("%d", &playerChoice);
		// 0か1以外なら終了
		if (playerChoice != 0 && playerChoice != 1) {
			break;
		}

		// 結果を確認
		callBack(randomAnswer, (bool)playerChoice, 3);
	}
}