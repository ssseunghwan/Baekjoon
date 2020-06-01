//#include <iostream>
//#include <queue>
//#include <tuple>
//
//using namespace std;
//
//int N, M, H;
//int map[101][101][101];
//int visit[101][101][101];
//bool iszero = false;
//int cnt = 0;
//
//void BFS(queue<tuple<int, int, int>> &q) {
//	int i, j, k, x, y, z;
//	int dx[6] = { -1,1,0,0,0,0 };
//	int dy[6] = { 0,0,-1,1,0,0 };
//	int dz[6] = { 0,0,0,0, -1,1 };
//
//	while (!q.empty()) {
//		x = get<0>(q.front());
//		y = get<1>(q.front());
//		z = get<2>(q.front());
//		q.pop();
//		for (i = 0; i < 6; i++) {
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			int nz = z + dz[i];
//			if (visit[nx][ny][nz] == -1 && map[nx][ny][nz] == 0) {
//				if (nx > 0 && nx <= N && ny > 0 && ny <= M && nz > 0 && nz <= H) {
//					q.push(make_tuple(nx, ny, nz));
//					visit[nx][ny][nz] = visit[x][y][z] + 1;
//				}
//			}
//		}
//	}
//	for (k = 1; k <= H; k++) {
//		for (i = 1; i <= N; i++) {
//			for (j = 1; j <= M; j++) {
//				if (cnt < visit[i][j][k]) {
//					cnt = visit[i][j][k];
//				}
//				if (map[i][j][k] == 0 && visit[i][j][k] == -1) {
//					iszero = true;
//				}
//			}
//		}
//	}
//	
//
//
//}
//
//int main() {
//	int i, j, k;
//	cin >> M >> N >> H;
//
//	for (k = 1; k <= H; k++) {
//		for (i = 1; i <= N; i++) {
//			for (j = 1; j <= M; j++) {
//				cin >> map[i][j][k];
//				visit[i][j][k] = -1;
//			}
//		}
//	}
//	queue < tuple<int, int, int>> q;
//	for (k = 1; k <= H; k++) {
//		for (i = 1; i <= N; i++) {
//			for (j = 1; j <= M; j++) {
//				if (map[i][j][k] == 1) {
//					q.push(make_tuple(i, j, k));
//					visit[i][j][k] = 0;
//				}
//			}
//		}
//	}
//	BFS(q);
//	if (iszero == true) {
//		cout << "-1" << endl;
//	}
//	else {
//		cout << cnt << endl;
//	}
//	return 0;
//}
