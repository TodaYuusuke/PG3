#include <stdio.h>
#include <iostream>
#include <string>

template <typename T>
void Min(T a, T b) {
	T value = a < b ? a : b;
	std::cout << value << std::endl;
}
template <>
void Min<char>(char a, char b) {
	std::cout << "数字以外は代入できません" << std::endl;
}

int main() {
	Min(1, 2);
	Min(1.2f, 0.8f);
	Min(3.2, 4.1);
	Min('a', 'b');
	
	return 0;
}