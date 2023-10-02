#include <stdio.h>

template <typename T>
T Min(T a, T b) {
	return a < b ? a : b;
}
template <>
char Min<char>(char a, char b) {
	printf("数字以外は代入できません\n");
	return 0;
}

int main() {
	int a(1), b(2);
	float c(1.2f), d(0.8f);
	double e(3.2), f(4.1);
	char g('a'), h('d');

	printf("int型の比較 Min(%d, %d) -> ", a, b);
	printf("%d\n", Min<int>(a, b));
	printf("float型の比較 Min(%.2f, %.2f) -> ", c, d);
	printf("%.2f\n", Min<float>(c, d));
	printf("double型の比較 Min(%.2lf, %.2lf) -> ", e, f);
	printf("%.2lf\n", Min<double>(e, f));
	printf("char型の比較 Min(%c, %c) -> ", g, h);
	printf("%c\n", Min<char>(g, h));

	return 0;
}