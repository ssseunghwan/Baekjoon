#include <iostream>
#include <algorithm>

using namespace std;
int N, K;
int obj[101][2];
int result[101][100001];

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> obj[i][0] >> obj[i][1];
	}
	for (int i = 1; i <= N; i++) {
		for (int j= 1; j <= K; j++) {
			if (obj[i][0] <= j) {
				result[i][j] = max(result[i - 1][j], result[i - 1][j - obj[i][0]] + obj[i][1]);
			}
			else {
				result[i][j] = result[i - 1][j];
			}
		}
	}
	cout << result[N][K];
}

