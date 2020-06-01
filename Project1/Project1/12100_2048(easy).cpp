#include <iostream>
#include <queue>

using namespace std;

int N;
int map[20][20];
int result[11][11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct axis {
	int x; int y; int move;
	int curmap[20][20];
};

void clear(int a[20][20]) {
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			a[i][j] = 0;
		}
	}
}
int find(int a[20][20]) {
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] > temp) temp = a[i][j];
		}
	}
	return temp;
}

void copy(int a[20][20], int b[20][20]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j]=b[i][j];
		}
	}
}
void left(int a[20][20]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] == 0) {
				for (int k = j+1; k < N; k++) {
					if (a[i][k] != 0) {
						a[i][j] = a[i][k];
						a[i][k] = 0;
						break;
					}
				}
			}
			if (a[i][j] != 0) {
				for (int k = j + 1; k < N; k++) {
					if (a[i][k] != 0) {
						if (a[i][k] == a[i][j]) {
							a[i][j] = 2 * a[i][j];
							a[i][k] = 0; 
						}
						break;
					}
				}
			}
		}
	}
}
void right(int a[20][20]) {
	for (int i = 0; i < N; i++) {
		for (int j = N-1; j >=0; j--) {
			if (a[i][j] == 0) {
				for (int k = j - 1; k >=0; k--) {
					if (a[i][k] != 0) {
						a[i][j] = a[i][k];
						a[i][k] = 0;
						break;
					}
				}
			}
			if (a[i][j] != 0) {
				for (int k = j - 1; k >=0; k--) {
					if (a[i][k] != 0) {
						if (a[i][k] == a[i][j]) {
							a[i][j] = 2 * a[i][j];
							a[i][k] = 0;
						}
						break;
					}
				}
			}
		}
	}
}
void up(int a[20][20]) {
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (a[i][j] == 0) {
				for (int k = i + 1; k < N; k++) {
					if (a[k][j] != 0) {
						a[i][j] = a[k][j];
						a[k][j] = 0;
						break;
					}
				}
			}
			if (a[i][j] != 0) {
				for (int k = i + 1; k < N; k++) {
					if (a[k][j] != 0) {
						if (a[k][j] == a[i][j]) {
							a[i][j] = 2 * a[i][j];
							a[k][j] = 0;
						}
						break;
					}
				}
			}
		}
	}
}
void down(int a[20][20]) {
	for (int j = 0; j < N; j++) {
		for (int i = N-1; i>=0; i--) {
			if (a[i][j] == 0) {
				for (int k = i - 1; k >=0; k--) {
					if (a[k][j] != 0) {
						a[i][j] = a[k][j];
						a[k][j] = 0;
						break;
					}
				}
			}
			if (a[i][j] != 0) {
				for (int k = i - 1; k >=0; k--) {
					if (a[k][j] != 0) {
						if (a[k][j] == a[i][j]) {
							a[i][j] = 2 * a[i][j];
							a[k][j] = 0;
						}
						break;
					}
				}
			}
		}
	}
}

void bfs() {
	queue <axis>q;
	axis st;
	st.x = 5;
	st.y = 5;
	st.move = 0;
	copy(st.curmap, map);
	q.push(st);
	result[st.y][st.x] = find(st.curmap);

	while (!q.empty()) {
		int x = q.front().x;	int y = q.front().y;
		int move = q.front().move;	int curmap[20][20];
		copy(curmap, q.front().curmap);
		q.pop();

		if (move < 5) {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];		int ny = y + dy[i];
				int nxtmap[20][20];
				copy(nxtmap, curmap);

				if (i == 0)  left(nxtmap);
				if (i == 1)  right(nxtmap);
				if (i == 2)  up(nxtmap);
				if (i == 3)  down(nxtmap);

				axis n;
				n.x = nx;	n.y = ny; n.move = move + 1;
				copy(n.curmap, nxtmap);
				q.push(n);

				if (result[ny][nx] < find(nxtmap)) result[ny][nx] = find(nxtmap);
			}
		}
	} 
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			result[i][j] = 0;
		}
	}
	
	bfs();

	int temp = 0;

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			if (temp < result[i][j]) temp = result[i][j];
		}
	}
	cout << temp;
}