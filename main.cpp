#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <regex>

int main() {

	// リスト
	std::vector<std::string> dataList = {
		"k022g0108@g.neec.ac.jp", "k022g0045@g.neec.ac.jp", "k022g0007@g.neec.ac.jp", "k022g0015@g.neec.ac.jp","k022g0028@g.neec.ac.jp", "k022g0049@g.neec.ac.jp", "k022g0003@g.neec.ac.jp", "k022g0044@g.neec.ac.jp",
		"k022g0072@g.neec.ac.jp", "k022g0055@g.neec.ac.jp", "k021g1139@g.neec.ac.jp", "k021g1485@g.neec.ac.jp","k021g1162@g.neec.ac.jp", "k021g1278@g.neec.ac.jp", "k020g1229@g.neec.ac.jp", "k020g1202@g.neec.ac.jp",
		"k020g1215@g.neec.ac.jp", "k020g1416@g.neec.ac.jp", "k020g1245@g.neec.ac.jp", "k020g1506@g.neec.ac.jp","k020g1401@g.neec.ac.jp", "k022g0089@g.neec.ac.jp", "k022g0107@g.neec.ac.jp", "k022g0135@g.neec.ac.jp",
		"k022g0020@g.neec.ac.jp", "k022g0046@g.neec.ac.jp", "k022g0126@g.neec.ac.jp", "k022g0068@g.neec.ac.jp","k022g1060@g.neec.ac.jp", "k022g0019@g.neec.ac.jp", "k022g0013@g.neec.ac.jp", "k022g0024@g.neec.ac.jp",
		"k022g0134@g.neec.ac.jp", "k022g0123@g.neec.ac.jp", "k022g0030@g.neec.ac.jp", "k022g0053@g.neec.ac.jp","k022g0023@g.neec.ac.jp", "k022g0041@g.neec.ac.jp", "k022g0063@g.neec.ac.jp", "k022g0059@g.neec.ac.jp",
		"k022g0078@g.neec.ac.jp", "k022g0011@g.neec.ac.jp", "k022g0040@g.neec.ac.jp", "k022g0088@g.neec.ac.jp","k022g0099@g.neec.ac.jp", "k022g0060@g.neec.ac.jp", "k022g0032@g.neec.ac.jp", "k022g0087@g.neec.ac.jp",
		"k022g0016@g.neec.ac.jp", "k022g0116@g.neec.ac.jp", "k022g0056@g.neec.ac.jp", "k022g0009@g.neec.ac.jp","k022g0034@g.neec.ac.jp", "k022g0062@g.neec.ac.jp", "k022g0102@g.neec.ac.jp", "k022g0113@g.neec.ac.jp",
		"k022g0064@g.neec.ac.jp", "k022g0080@g.neec.ac.jp", "k022g0114@g.neec.ac.jp", "k022g0025@g.neec.ac.jp","k022g0095@g.neec.ac.jp", "k022g0121@g.neec.ac.jp", "k022g0021@g.neec.ac.jp", "k022g0104@g.neec.ac.jp",
		"k022g0101@g.neec.ac.jp", "k022g0130@g.neec.ac.jp", "k022g0036@g.neec.ac.jp", "k022g0004@g.neec.ac.jp","k022g0093@g.neec.ac.jp", "k022g0038@g.neec.ac.jp", "k022g0069@g.neec.ac.jp", "k022g0029@g.neec.ac.jp",
		"k022g0010@g.neec.ac.jp", "k022g0083@g.neec.ac.jp", "k022g0086@g.neec.ac.jp", "k022g0129@g.neec.ac.jp","k022g0048@g.neec.ac.jp", "k022g0027@g.neec.ac.jp", "k022g0103@g.neec.ac.jp", "k022g0117@g.neec.ac.jp",
		"k022g0085@g.neec.ac.jp", "k022g0052@g.neec.ac.jp", "k022g0073@g.neec.ac.jp", "k022g0065@g.neec.ac.jp","k022g0091@g.neec.ac.jp", "k022g0136@g.neec.ac.jp", "k022g0079@g.neec.ac.jp", "k022g0017@g.neec.ac.jp",
		"k022g0097@g.neec.ac.jp", "k022g0077@g.neec.ac.jp", "k022g0050@g.neec.ac.jp", "k022g0033@g.neec.ac.jp","k022g0039@g.neec.ac.jp", "k022g0118@g.neec.ac.jp", "k022g0112@g.neec.ac.jp", "k022g0120@g.neec.ac.jp",
		"k022g0127@g.neec.ac.jp", "k021g1464@g.neec.ac.jp", "k022g0137@g.neec.ac.jp", "k022g0066@g.neec.ac.jp","k022g0051@g.neec.ac.jp", "k022g0111@g.neec.ac.jp", "k022g0094@g.neec.ac.jp", "k022g0128@g.neec.ac.jp",
		"k022g0109@g.neec.ac.jp", "k022g0124@g.neec.ac.jp", "k022g0084@g.neec.ac.jp", "k022g0082@g.neec.ac.jp","k022g0122@g.neec.ac.jp", "k022g0061@g.neec.ac.jp", "k022g0031@g.neec.ac.jp", "k022g0076@g.neec.ac.jp",
		"k022g0002@g.neec.ac.jp", "k022g0090@g.neec.ac.jp", "k022g0074@g.neec.ac.jp", "k022g0012@g.neec.ac.jp","k022g0001@g.neec.ac.jp"
	};

	// 順番にソート
	std::sort(dataList.begin(), dataList.end(), [](std::string& s1, std::string& s2) {
		// 数字を抽出する正規表現パターン
		std::regex pattern("\\d+");

		// 正規表現に一致するすべての数字を取り出す
		std::sregex_iterator iter1(s1.begin(), s1.end(), pattern);
		std::sregex_iterator iter2(s2.begin(), s2.end(), pattern);
		
		// 数字のデータを取り出す
		int numbers[2][2];
		numbers[0][0] = std::stoi(static_cast<std::smatch>(*iter1++).str());	// 1つめの文字列の3ケタの方のデータ
		numbers[0][1] = std::stoi(static_cast<std::smatch>(*iter2++).str());	// 2つめの文字列
		numbers[1][0] = std::stoi(static_cast<std::smatch>(*iter1).str());	// 1つめの文字列の4ケタの方のデータ
		numbers[1][1] = std::stoi(static_cast<std::smatch>(*iter2).str());	// 2つめの文字列
		
		// 3ケタのデータが同じの場合 -> 4ケタのデータで比較する
		if (numbers[0][0] == numbers[0][1]) {
			return numbers[1][0] < numbers[1][1];
		}
		else {
			return numbers[0][0] < numbers[0][1];
		}
	});

	// 表示
	for (std::vector<std::string>::iterator itr = dataList.begin(); itr != dataList.end(); ++itr) {
		printf("%s\n", static_cast<std::string>(*itr).c_str());
	}
}