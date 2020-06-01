#include<iostream>
#include<queue>
using namespace std;
int N, M;
int map[1001][1001];
int visited[1001][1001];
bool iszero = false;
int cnt = 0;
void BFS(queue<pair<int, int>> &q) {
	int i, j, x, y;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++) {

			int nx = x + dx[i];
			int ny = y + dy[i];
			if (visited[nx][ny] == -1 && map[nx][ny] == 0) {
				if (nx > 0 && nx <= N && ny > 0 && ny <= M) {
					q.push(make_pair(nx, ny));
					visited[nx][ny] = visited[x][y] + 1;
				}
			}
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if (cnt < visited[i][j]) {
				cnt = visited[i][j];
			}
			if (map[i][j] == 0 && visited[i][j] == -1) {
				iszero = true;
			}
		}
	}
}
int main() {

	int i, j;
	cin >> M >> N;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			visited[i][j] = -1;
		}
	}
	queue<pair<int, int>> q;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
				visited[i][j] = 0;
			}
		}
	}
	BFS(q);
	if (iszero == true) {
		cout << "-1" << endl;
	}
	else {
		cout << cnt << endl;
	}
	return 0;
}