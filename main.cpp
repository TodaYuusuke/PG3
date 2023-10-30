#include "Calc.h"
#include <stdio.h>

int main() {
	Calc<int, int> calc1(1, 1);
	Calc<int, float> calc2(1, 1.1f);
	Calc<int, double> calc3(1, 1.1);
	Calc<float, float> calc4(1.0f, 1.1f);
	Calc<float, double> calc5(1.0f, 1.1);
	Calc<double, double> calc6(1.0, 1.1);

	printf("   int    int ... min -> %d\n", calc1.Min<int>());
	printf("   int  float ... min -> %f\n", calc2.Min<float>());
	printf("   int double ... min -> %lf\n", calc3.Min<double>());
	printf(" float  float ... min -> %f\n", calc4.Min<float>());
	printf(" float double ... min -> %lf\n", calc5.Min<double>());
	printf("double double ... min -> %lf\n", calc6.Min<double>());
}