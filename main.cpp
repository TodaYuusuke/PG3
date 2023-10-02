#include <stdio.h>

int NormalWage(int workedTime) {
	return 1072 * workedTime;
}

int RecursiveWage(int workedTime, int preHourWage = 100) {
	if (workedTime <= 0) { 
		return 0; 
	}
	else if (workedTime <= 1) { 
		return 100; 
	}

	// 現在の時間の時給を計算
	int currentHourWage = preHourWage * 2 - 50;
	return  currentHourWage + RecursiveWage(workedTime - 1, currentHourWage);
}

int main() {
	int workedTime = 0;

	while (true) {
		printf("労働時間を入力してください（0以下の数字で終了） -> ");
		scanf_s("%d", &workedTime);

		if (workedTime < 0) {
			break;
		}

		printf("一般的な賃金体系の場合 ... %d 円\n", NormalWage(workedTime));
		printf("再帰的な賃金体系の場合 ... %d 円\n", RecursiveWage(workedTime));
	}

	return 0;
}