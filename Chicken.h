#pragma once
#include "IAnimal.h"

class Chicken : public IAnimal {

	void MakeSound() override {
		printf("コケコッコー!\n");
	};

};