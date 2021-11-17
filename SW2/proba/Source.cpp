#include <iostream>

using namespace std;

int* creatArray(int size) {
	int* arr = new int[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 21 - 5;
		cout << arr[i] << " ";
	}
	return arr;
}