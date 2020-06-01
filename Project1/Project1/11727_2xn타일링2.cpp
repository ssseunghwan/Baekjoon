#include <iostream>

using namespace std;

unsigned long long result[1001] = {};

int main() {
	result[1] = 1;
	result[2] = 3;
	int check;
	for (int i = 3; i < 1001; i++) {
		result[i] = (result[i - 2] * 2 + result[i - 1]);
	}
	cin >> check;
	printf("%d", result[check]);
}