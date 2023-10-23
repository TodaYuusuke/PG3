#include "Enemy.h"
#include <Windows.h>

int main() {
	Enemy enemy;

	while (true) {
		enemy.Update();
		Sleep(1000);
	}
}