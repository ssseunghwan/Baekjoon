#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, x, y, iszero;
int cnt = 0;
int map[300][300], nxt_map[300][300], visited[300][300];
bool stop = false;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool brk = false;

bool bfs_search() {
	queue<pair<int, int>> q;

	brk = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		if (brk == true) break;
		for (int j = 0; j < M; j++) {
			if (nxt_map[i][j] != 0 && visited[i][j] == 0) {
				q.push({ i,j });
				visited[i][j] = 1;
				brk = true;
				break;
			}
		}
	}
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (visited[ny][nx] == 0 && nxt_map[ny][nx] != 0) {
				visited[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (nxt_map[i][j] != 0 && visited[i][j] == 0)	return true;
		}
	}
	return false;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	while (stop==false) {
		iszero = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 0) {
					nxt_map[i][j] = map[i][j];
					if (map[i - 1][j] == 0) nxt_map[i][j] = max(nxt_map[i][j] - 1, 0);
					if (map[i + 1][j] == 0) nxt_map[i][j] = max(nxt_map[i][j] - 1, 0);
					if (map[i][j - 1] == 0) nxt_map[i][j] = max(nxt_map[i][j] - 1, 0);
					if (map[i][j + 1] == 0) nxt_map[i][j] = max(nxt_map[i][j] - 1, 0);
				}
			}
		}
		
		cnt++;
		stop = bfs_search();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = nxt_map[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				nxt_map[i][j] = 0;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) iszero++;
			}
		}
		if (iszero == M * N) break;
	}
	if (stop == true) cout << cnt;
	if (stop == false) cout << 0;
	return 0;
}	