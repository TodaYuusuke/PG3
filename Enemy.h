#pragma once

class Enemy {
	enum class State : size_t {
		Melee = 0,
		Shoot = 1,
		Leave = 2
	};


public: // ** メンバ関数 ** //

	// 更新
	void Update();

private: // ** メンバ変数 ** //

	// メンバ関数ポインタテーブル
	static void(Enemy::* funcTabel[])();

	// 現在のstate
	State state = State::Melee;
	

private: // ** プライベートな関数 ** //
	
	// 近接
	void Melee();
	// 射撃
	void Shoot();
	// 離脱
	void Leave();
};