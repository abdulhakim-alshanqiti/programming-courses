#include<iostream>

using namespace std;
int main() {
	void* ptr; // Generic Pointer Allows To Change The Pointer Address to any Type At Runtime
	//int* ptr; // Int Pointer Allows To Change The Pointer Address only to Int Type At RunTime Time


	float float1 = 10.5;
	int integer1 = 50;
	// You can store any Address in it No matter the type of the variable
	ptr = &float1;

	cout << ptr << endl;
	// here you are going to cast from void pointer to float pointer

	// ptr is a void*,
	// which means it’s a pointer that can hold the address of any data type,
	// but you cannot dereference it directly because it has no type information.
	// static_cast<float*>(ptr) converts the void* pointer into a float* pointer 
	// now it is a pointer to a float You can derefrence it like any other pointer likr this *ptr 
	float* floatPointer = static_cast<float*>(ptr);
	cout << *floatPointer << endl;

	ptr = &integer1;

	cout << ptr << endl;
	// here is another way to write it
	cout << *(static_cast<int*>(ptr)) << endl;



	return 0;
}