#include <stdio.h>
#include <algorithm>
#include <list>
#include <functional>
#include <Windows.h>

void PrintList(const char* year, std::list<const char*> list) {
	int index = 0;
	// 表示
	printf(" - %s - \n", year);
	for (std::list<const char*>::iterator itr = list.begin(); itr != list.end(); ++itr, ++index) {
		printf("%02d:%s\n", index, *itr);
	}
	printf("\n");
}

int main() {

	// 駅名リスト
	std::list<const char*> stationName = {
		"Tokyo","Kanda","Akihabara","Okachimachi","Ueno","Uguisudani","Nippori",
		"Tabata","Komagome","Sugamo","Otsuka","Ikebukuro","Mejiro","Takadanobaba",
		"Shin-Okubo","Shinjuku","Yoyogi","Harajuku","Shibuya","Ebisu","Meguro",
		"Gotanda","Osaki","Shinagawa","Tamachi","Hamamatsucho","Shimbashi","Yurakucho"
	};
	// 駅を挿入するためのイテレータ
	std::list<const char*>::iterator itr;

	// 表示
	PrintList("1970", stationName);
	
	// 駅を追加
	itr = std::find_if(stationName.begin(), stationName.end(), [](const char* name) { return name == "Tabata"; });
	stationName.insert(itr, "Nishi-Nippori");
	
	// 表示
	PrintList("2019", stationName);

	// 駅を追加
	itr = std::find_if(stationName.begin(), stationName.end(), [](const char* name) { return name == "Tamachi"; });
	stationName.insert(itr, "Takanawa-Gateway");
	
	// 表示
	PrintList("2022", stationName);
}