#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

char map[8][8];
char input;
int result = 0;
int cnt = 0;
int num = 0;
int st_row, st_col;
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,1,1,1,0,-1,-1,-1};

int find(int row,int col, int dir,int cnt) {
	int nxt_row, nxt_col;
	nxt_row = row + dy[dir]; nxt_col = col + dx[dir];
	if(nxt_row>=0&&nxt_row<8&& nxt_col >= 0 && nxt_col < 8){
		if (map[nxt_row][nxt_col] == '2') {
			return find(nxt_row, nxt_col, dir, cnt + 1);
		}
		else if(map[nxt_row][nxt_col] == '0') {
			return 0;
		}
		else if (map[nxt_row][nxt_col] == '1') {
			return cnt;
		}
	}
}

int main() {
	while (!(num == 64)) {
		cin >> input;
		if ((input == '0') ||(input == '1') || (input == '2')) {
			map[num/8][num%8] = input;
			num++;
		}
	}
	int number;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (map[i][j] == '2') {
				for (int k = 0; k < 8; k++) {
					if (map[i + dy[k]][j + dx[k]] == '0') {
						number = 0;
						for (int l = 1; l < 7; l++) {
							if (map[i + l*dy[(k + 4) % 8]][j + l*dx[(k + 4) % 8]] == '2') continue;
							if (map[i + l * dy[(k + 4) % 8]][j + l * dx[(k + 4) % 8]] == '1') {
								number = number + l; break;
							}
							if (map[i + l * dy[(k + 4) % 8]][j + l * dx[(k + 4) % 8]] == '0') {
								number = number + 0;
								break;
							}
						}
						result = max(result, number);
					}
					/*st_row = i + dy[k];
					st_col = j + dx[k];
					if (map[st_row][st_col] == '0') {
						result = max(find(st_row, st_col, (k + 4) % 8, 0),result);
					}*/
				}
				
			}
		}
	}
	cout << result;
	return 0;
}