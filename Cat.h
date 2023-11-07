#pragma once
#include "IAnimal.h"

class Cat : public IAnimal {

	void MakeSound() override {
		printf("ニャー!\n");
	};

};