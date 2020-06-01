#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int N;
int cnt = 0;
string map[25];
int visit[25][25];
int S[313];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct axis {
	int x; int y;
};

void bfs(axis a) {
	int S_cnt = 0;
	visit[a.y][a.x] = 1;
	queue <axis> q;
	q.push(a);
	while (!q.empty()) {
		int x = q.front().x; int y = q.front().y;
		S_cnt++;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (nx >= 0 && nx < N&&ny >= 0 && ny < N)
				if (map[ny][nx] == '1'&&visit[ny][nx] == 0){
					axis n; n.x = nx; n.y = ny;
					q.push(n);  visit[ny][nx] = 1;
				}
		}

	}
	S[cnt] = S_cnt;
	cnt++;
}
	

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1' && visit[i][j] == 0) {
				axis v; v.x = j; v.y = i; bfs(v);
			}
		}
	}
	sort(S, S + cnt);
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		cout << S[i] << endl;
	}
}