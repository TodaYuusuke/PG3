#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <Windows.h>
#include <time.h>

void SetTimeout(std::function<void()> func, int second) {
	Sleep(1000 * second);
	func();
}

int main() {
	// 乱数初期化
	srand((unsigned int)time(nullptr));

	// プレイヤーの選択を格納する関数
	int playerChoice;

	// コールバック関数
	std::function<void()> result = [&]() {
		int num = rand() % 6 + 1;
		printf("%d\n", num);
		// 結果によって分岐
		if (playerChoice == num % 2) {
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
		printf("結果は...");
		SetTimeout(result, 3);
	}
}