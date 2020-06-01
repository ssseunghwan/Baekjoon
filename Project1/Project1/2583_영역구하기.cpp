#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

int N, M, num;
int map[101][101];
int visit[101][101];
int S[100001]; 
int block[100001][5];
int cnt = 0;
bool iszero = false;


void BFS(queue<pair<int, int>> &q) {
	cnt = cnt+1;
	int i, j, x, y;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	int S_cnt = 0;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		S_cnt = S_cnt + 1;
		for (i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (visit[ny][nx] == 0 && map[ny][nx] == 0) {
				if (nx > 0 && nx <= N && ny > 0 && ny <= M) {
					visit[ny][nx] = 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
	S[cnt] = S_cnt;
}

int main() {
	int i, j, k, l,b_num;
	cin >> M >> N >> b_num;
	for (i = 1; i <= b_num; i++) {
		for (j = 1; j <= 4; j++) {
			cin >> block[i][j];
		}
	}
	for (i = 1; i <= M; i++) {
		for (j = 1; j <= N; j++) {
			for (k = 1; k <= b_num; k++) {
				if (j > block[k][1] && j <= block[k][3] && i > block[k][2] && i <= block[k][4]) {
					map[i][j] = 2;
				}
			}
			if (map[i][j] != 2) map[i][j] = 0;
			visit[i][j] = 0;
		}
	}
	for (i = 0; i < 100001; i++) {
		S[i] = M * N;
	}
	queue < pair<int, int>> q;
	for (i = 1; i <= M; i++) {
		for (j = 1; j <= N; j++) {
			if (map[i][j] == 0 && visit[i][j] == 0) {
				visit[i][j] = 1;
				q.push(make_pair(i, j));
				BFS(q);
			}
		}
	}
	sort(S,S+100001);
	cout << cnt << endl;
	for (i = 0; i < cnt; i++) {
		cout << S[i]<<" ";
	}
}
