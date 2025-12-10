#include <iostream>
#include "../../libs/MyLib.h"
using namespace std;
using namespace Output;


int main() {
	int n1 = 1, n2 = 5;

	printf("The Result Of %d + %d = %d \n", n1, n2, n1 + n2);


	printf("The Result Of %d + %d = %0*d \n", n1, n2, 2, n1 + n2);

	return 0;

}