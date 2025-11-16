#pragma warning(disable: 4996)


#include <ctime>
#include <iostream>

using namespace std;

int main() {
	time_t t = time(0);

	char* dt = ctime(&t);
	cout << "Local Date and Time: " << dt << endl;


	tm* gmtm = gmtime(&t);
	dt = asctime(gmtm);
	cout << "UTC Date and Time: " << dt << endl;

	return 0;
}
