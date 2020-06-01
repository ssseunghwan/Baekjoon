#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>  

using namespace std;

int answer[1000001] = {};

int main() {
	int w;
	answer[1] = 0;
	answer[2] = 1;
	answer[3] = 1;

	cin >> w;
	for (int i = 4; i <= w; i++) {
		
		if (i % 3 == 0 && i % 2 == 0)	answer[i] = min(answer[i / 3] + 1, min(answer[i / 2] + 1, answer[i - 1]));
		else if (i % 3 != 0 && i % 2 == 0)	answer[i] = min(answer[i / 2] + 1, answer[i - 1] + 1);
		else if (i % 3 == 0 && i % 2 != 0)	answer[i] = min(answer[i / 3] + 1, answer[i - 1] + 1);
		else answer[i] = answer[i - 1] + 1;
	}
	cout << answer[w];
}

