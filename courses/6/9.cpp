#include<iostream>
#include<string>
#include<cmath>
#include "../../Libs/MyLib.h"
using namespace std;
using namespace Input;
using namespace Output;
//using namespace std;
void PrintfromMtoN(int M, int N) {
	if (M >= N) {
		Printl(M);
		PrintfromMtoN(M - 1, N);

	}
}



int Power(int N, int M) {
	if (M == 1)
		return N;
	else
		return (Power(N, M - 1) * N);

}



int main() {
	PrintfromMtoN(5, 1);
	Printl(Power(3, 2));



	return 0;
}