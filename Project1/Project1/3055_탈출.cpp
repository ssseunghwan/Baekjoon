#include <iostream>
#include <queue>

using namespace std;

int R, C;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

char map[50][50];
int visit[50][50];
char og_water[50][50];
char current_water[50][50];

bool found;
pair<int, int> dest;
pair<int, int> start;

struct axis {
	int y; int x; int day;
};
void make_watermap(int a) {
	char now_water[50][50];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			now_water[i][j] = og_water[i][j];
		}
	}
	for (int k = 0; k < a; k++) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (now_water[i][j] == '*') {
					current_water[i][j] = '*';
					if (i - 1 >= 0 && map[i - 1][j] != 'D'&&map[i - 1][j] != 'X') current_water[i - 1][j] = '*';
					if (i + 1 < R&&map[i + 1][j] != 'D'&&map[i + 1][j] != 'X') current_water[i + 1][j] = '*';
					if (j - 1 >= 0 && map[i][j - 1] != 'D'&&map[i][j - 1] != 'X') current_water[i][j - 1] = '*';
					if (j + 1 < C&&map[i][j + 1] != 'D'&&map[i][j + 1] != 'X') current_water[i][j + 1] = '*';
				}
			}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				now_water[i][j] = current_water[i][j];
			}
		}
	}
}
void bfs() {
	axis st;
	st.y = start.first; st.x = start.second; st.day = 0;
	queue <axis> q;
	visit[start.first][start.second] = 1;
	q.push(st);

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int day = q.front().day;
		if (y == dest.first&&x == dest.second) {
			cout << day;
			found = true;
			break;
		}
		q.pop();
		make_watermap(day+1);
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (ny >= 0 && ny < R&&nx >= 0 && nx < C&&visit[ny][nx] == 0) {
				if (current_water[ny][nx] != '*'&&map[ny][nx] != 'X') {
					axis na;
					na.y = ny; na.x = nx; na.day = day + 1;
					q.push(na);
					visit[ny][nx] = 1;
				}
			}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				current_water[i][j]=0;
			}
		}
	}
	if(found==false) cout << "KAKTUS";
}

int main() {
	cin >> R >> C;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') og_water[i][j] = '*';
			if (map[i][j] == 'D') dest = { i,j };
			if (map[i][j] == 'S') start = { i,j };
		}
	}
	bfs();
}