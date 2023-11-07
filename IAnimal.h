#pragma once
#include <iostream>

class IAnimal {
public:
	// 鳴く
	virtual void MakeSound() = 0;
};