#include "Circle.h"
#include "Rectangle.h"

int main() {
	IShape* shapes[2]{
		new Circle(),
		new Rectangle()
	};

	for (int i = 0; i < 2; i++) {
		shapes[i]->size();
		shapes[i]->draw();
	}

	return 0;
}