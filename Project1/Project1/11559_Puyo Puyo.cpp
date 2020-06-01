#include <iostream>
#include <queue>

using namespace std;

char map[12][6];
int visited[12][6];
int cnt;
bool Rb, Gb, Bb, Pb, Yb;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs2(int, int, char);

void bfs(char type) {
	if (type == 'R') Rb = false;
	if (type == 'G') Gb = false;
	if (type == 'B') Bb = false;
	if (type == 'P') Pb = false;
	if (type == 'Y') Yb = false;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (visited[i][j] == 0 && map[i][j] == type) {
				bfs2(i, j, type);
			}
		}
	}
}
void order() {
	for (int j = 0; j < 6; j++) {
		for (int i = 11; i >= 0; i--) {
			if (map[i][j] != '.') {
				for (int k = 11; k > i; k--) {
					if (map[k][j] == '.') {
						map[k][j] = map[i][j];
						map[i][j] = '.';
						break;
					}
				}
			}
		}
	}
}
void visit_clr() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			visited[i][j] = 0;
		}
	}
}
void map_clr(char type) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (visited[i][j] == 1 && map[i][j] == type) map[i][j] = '.';
		}
	}
}
void bfs2(int y0, int x0, char type) {
	int S=0;
	queue<pair<int, int>> q;
	q.push({ y0,x0 });
	visited[y0][x0] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		S++;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (visited[ny][nx] == 0 && map[ny][nx] == type) {
				if (ny >= 0 && ny < 12 && nx >= 0 && nx < 6) {
					visited[ny][nx] = 1;
					q.push({ ny,nx });
				}
			}
		}
	}
	if (S >= 4) {
		map_clr(type);
		if (type == 'R') Rb = true;
		if (type == 'G') Gb = true;
		if (type == 'B') Bb = true;
		if (type == 'P') Pb = true;
		if (type == 'Y') Yb = true;
	}
	visit_clr();
}
int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}
	while (1) {
		int temp = cnt;
		bfs('R');
		bfs('G');
		bfs('B');
		bfs('P');
		bfs('Y');
		order();
		if ((Rb || Gb || Bb || Pb || Yb) == true) cnt++;
		if (temp == cnt) break;
	}
	cout << cnt;
	return 0;
}