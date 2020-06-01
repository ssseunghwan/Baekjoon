#include <iostream>
#include <queue>

using namespace std;

int K, W, H;
int map[200][200];
int visited[200][200][31];
int dx[12] = { -2,-2,-1,-1,1,1,2,2,-1,1,0,0 };
int dy[12] = { -1,1,-2,2,-2,2,-1,1,0,0,-1,1 };

struct axis {
	int x;
	int y;
	int k;
};

int BFS() {
	queue <axis> q;
	axis s;
	s.x = 0; s.y = 0; s.k = K;
	visited[0][0][0] = 1;
	q.push(s);
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int k = q.front().k;
		if (x == W - 1 && y == H - 1) {
			return visited[y][x][k];
		}
		q.pop();
		for (int i = 0; i < 12; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			axis n;
			if (map[ny][nx] == 0 && ny >= 0 && ny < H&&nx >= 0 && nx < W) {
				if (i < 8&&k>0) {
					if (visited[ny][nx][k - 1] == 0) {
						n.x = nx; n.y = ny; n.k = k - 1;
						visited[ny][nx][k - 1] = visited[y][x][k] + 1;
						q.push(n);
					}
				}
				if (i >= 8) {
					if (visited[ny][nx][k] == 0) {
						n.x = nx; n.y = ny; n.k = k;
						visited[ny][nx][k] = visited[y][x][k] + 1;
						q.push(n);
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}
	cout<< BFS();
}