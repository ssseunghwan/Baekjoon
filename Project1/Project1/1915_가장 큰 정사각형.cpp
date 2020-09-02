#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
char map[1000][1000];
int map2[1000][1000];
int result;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '1') map2[i][j] = 1;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (map2[i][j] == 1) {
				map2[i][j] = min(map2[i-1][j-1], min(map2[i-1][j], map2[i][j-1])) + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result = max(map2[i][j], result);
		}
	}
	cout << result*result;
}