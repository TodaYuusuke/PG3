#pragma once
#include "IShape.h"

class Rectangle : public IShape {
public:

	void size() override {
		area = width * height;
	};
	void draw() override {
		printf("四角形の面積：%.2f\n", area);
	};

private:
	// 辺の長さ
	float width = 2;
	float height = 3;

	// 面積
	float area = 0;
};