#pragma once
#include <iostream>

class IShape {
public:
	virtual void size() = 0;
	virtual void draw() = 0;
};