#include "Enemy.h"
#include <stdio.h>

void Enemy::Update() {
	(this->*funcTabel[static_cast<size_t>(state)])();
}


// 近接
void Enemy::Melee() {
	printf("近接！\n");
	state = State::Shoot;
}
// 射撃
void Enemy::Shoot() {
	printf("射撃！\n");
	state = State::Leave;
}
// 離脱
void Enemy::Leave() {
	printf("離脱！\n");
	state = State::Melee;
}


void (Enemy::* Enemy::funcTabel[])() = {
	&Enemy::Melee,
	&Enemy::Shoot,
	&Enemy::Leave
};