#include <iostream>
#include <algorithm>
using namespace std;

int one = 0;
int two = 0;

int N;
int map[100000];
int tmp;
int canuse;
int recent = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp == 1) {
			two = two + 1;
			tmp = 0;
		}
		/*else {
			if (two != 0) {
				canuse = min(tmp / 2, two);
				tmp = tmp - 2 * canuse;
				two = two - canuse;
			}
		}*/
		map[i] = tmp;
	}

	for (int i = 0; i < N; i++) {
		if (two != 0) {
			canuse = min(map[i] / 2, two);
			map[i] = map[i] - 2 * canuse;
			two = two - canuse;
		}
		if (one != 0) {
			canuse = min(map[i] / 1, one);
			map[i] = map[i] - 1 * canuse;
			one = one - canuse;
		}
		recent = map[i] % 3;
		if (recent == 1) two = two + 1;
		if (recent == 2) one = one + 1;
	}
	if (recent == 0 && two == 0 && one == 0) cout << "YES";
	else cout << "NO";
}