#include <stdio.h>
#include <string>
#include <chrono>

// 経過時間を取得する
void CheckElapsedTime(const std::chrono::steady_clock::time_point& startTime) {
	std::chrono::duration<double, std::milli> elapsedTime = std::chrono::steady_clock::now() - startTime;
	printf("かかった時間は%lfマイクロ秒です。\n", elapsedTime.count());
}

int main() {
	// 10万文字の文字列
	std::string a(100000, 'a');
	// 実行開始時間
	std::chrono::steady_clock::time_point startTime;

	printf("「a」10万文字をコピーします\n");
	// 計測開始
	startTime = std::chrono::steady_clock::now();
	// コピー
	std::string b = a;
	// 経過時間を測定
	CheckElapsedTime(startTime);


	printf("「a」10万文字を移動します\n");
	// 計測開始
	startTime = std::chrono::steady_clock::now();
	// コピー
	std::string c = std::move(a);
	// 経過時間を測定
	CheckElapsedTime(startTime);
}