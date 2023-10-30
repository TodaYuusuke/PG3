#pragma once

template <typename T1, typename T2>
class Calc {
public: // ** メンバ関数 ** //
	
	// コンストラクタ
	Calc(T1 t1, T2 t2) : num1(t1), num2(t2) {}

	// 最小の値を比較する関数
	template<typename T>
	T Min(){
		T t1 = static_cast<T>(num1);
		T t2 = static_cast<T>(num2);
		return t1 < t2 ? t1 : t2;
	}


	// ** メンバ変数 ** //

	T1 num1;
	T2 num2;
};