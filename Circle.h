#pragma once
#include "IShape.h"

class Circle : public IShape {
public:

	void size() override {
		area = radius * radius * 3.14f;
	};
	void draw() override {
		printf("円の面積：%.2f\n", area);
	};

private:
	// 半径
	float radius = 2;

	// 面積
	float area = 0;
};