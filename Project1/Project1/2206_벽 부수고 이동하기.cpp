#include <iostream>
#include <queue>

using namespace std;

int N, M;
char map[1000][1000];
int visited[1000][1000][2];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool found;

struct axis {
	int x; int y; int des;
};

void bfs() {
	axis s;
	s.y = 0; s.x = 0; s.des = 0;
	visited[0][0][0] = 1;
	queue <axis> q;
	q.push(s);
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int des = q.front().des;
		if (y == N - 1 && x == M - 1) {
			cout << visited[y][x][des];
			found = true;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			axis n;
			if (ny >= 0 && ny < N&&nx >= 0 && nx < M) {
				if (des == 0) {
					if (map[ny][nx] == '1') {
						n.y = ny; n.x = nx; n.des = 1;
						q.push(n); visited[ny][nx][1] = visited[y][x][0] + 1;
					}
					if (map[ny][nx] == '0' && visited[ny][nx][0] == 0) {
						n.y = ny; n.x = nx; n.des = des;
						q.push(n); visited[ny][nx][0] = visited[y][x][0] + 1;
					}
				}
				if (des == 1) {
					if (map[ny][nx] == '0' && visited[ny][nx][1] == 0) {
						n.y = ny; n.x = nx; n.des = des;
						q.push(n); visited[ny][nx][1] = visited[y][x][1] + 1;
					}
				}
			}
		}
	}
	if (found==false) {
		cout << -1;
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	bfs();
	return 0;
}
