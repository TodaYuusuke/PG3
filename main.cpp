#include "Dog.h"
#include "Cat.h"
#include "Chicken.h"
#include <windows.h>


int main() {
	IAnimal* animals[3]{
		new Dog(),
		new Cat(),
		new Chicken()
	};

	for (int i = 0; i < 3; i++) {
		animals[i]->MakeSound();
	}

	return 0;
}