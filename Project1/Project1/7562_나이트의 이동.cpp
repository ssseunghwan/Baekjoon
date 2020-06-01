#include <iostream>
#include <queue>

using namespace std;

int t, l, x_s, y_s, x_d, y_d, x_c, y_c;
int visited[300][300];
int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { -1,1,-2,2,-2,2,-1,1 };

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> l >> x_s >> y_s >> x_d >> y_d;
		for (int m = 0; m < 300; m++) {
			for (int n = 0; n < 300; n++) {
				visited[m][n] = 0;
			}
		}
		queue<pair<int, int>> q;
		q.push({ x_s,y_s });
		visited[y_s][x_s] = 1;
		while (!q.empty()) {
			x_c = q.front().first;
			y_c = q.front().second;
			if (x_c == x_d && y_c == y_d) {
				if (i == t - 1) cout << visited[y_c][x_c]-1;
				else cout << visited[y_c][x_c]-1 << endl;

				break;
			}
			q.pop();
			for (int j = 0; j < 8; j++) {
				int nx = x_c + dx[j]; int ny = y_c + dy[j];
				if (visited[ny][nx] == 0 && nx >= 0 && nx < l && ny >= 0 && ny < l) {
					visited[ny][nx] = visited[y_c][x_c] + 1 ;
					q.push({ nx,ny });
				}
			}
			
		}
	}
	return 0;
}