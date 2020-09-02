#include <iostream>

using namespace std;
unsigned long long num[101][10];
unsigned long long N, result;
int main() {
	num[1][0] = 1; num[1][1] = 1; num[1][2] = 1; num[1][3] = 1; num[1][4] = 1; num[1][5] = 1; num[1][6] = 1; num[1][7] = 1; num[1][8] = 1; num[1][9] = 1;
	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) num[i][0] = num[i-1][1]%1000000000;
			else if (j == 9) num[i][9] = num[i-1][8]%1000000000;
			else num[i][j] = num[i-1][j-1]%1000000000 + num[i-1][j+1]%1000000000;
		}
	}
	cin >> N;
	for (int i = 1; i <= 9; i++) result = (result + num[N][i])%1000000000;
	cout << result%1000000000;
}