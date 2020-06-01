#include <iostream>
#include <queue>

using namespace std;

int c_num, N, max_num,cnt;
int map[100][100];
int visit[100][100];

struct axis{
	int x;
	int y;
};

void BFS(axis P) {
	queue<axis> q;
	q.push(P);
	cnt = cnt + 1;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if ((map[ny][nx] > c_num)&&(visit[ny][nx] == 0))
				if ((nx >= 0 && nx < N)&&(ny >= 0 && ny < N)) {
					axis np; np.x = nx; np.y = ny;
					visit[ny][nx] = 1; q.push(np); 
				}

		}

	}
}

int main() {
	max_num = 0;
	axis p;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (c_num = 0; c_num <= 100; c_num++) {
		for (int k = 0; k < 100; k++) {
			for (int l = 0; l < 100; l++) {
				visit[k][l] = 0;
			}
		}
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if ((map[i][j] > c_num)&&(visit[i][j] == 0)) {
					p.x = j;	p.y = i; visit[i][j] = 1; BFS(p);
				}
			}
		}
		if (max_num < cnt) max_num = cnt;
		if (cnt == 0) break;
	}
	cout << max_num;
	return 0;
}