#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int N, M, s_num, x, y;
int line[1001][1001];
int visited[1001];

int go_first(int a) {
	for (int i = N; i >= 1; i--) {
		if (line[a][i] == 1&&visited[i]==0) return i;
	}
	return 0;
}

void DFS(int s) {
	int cur, nxt;
	stack <int> st;
	st.push(s);
	while (!st.empty()) {
		cur = st.top();
		if (visited[cur] == 1) {
			st.pop();
			continue;
		}
		st.pop();
		visited[cur] = 1;
		cout << cur << " ";
		for (int i = N; i >= 1; i--) {
			if (line[cur][i] == 1 && visited[i] == 0) st.push(i);
		}
	}
}

void BFS(int s) {
	int cur, nxt;
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		cur = q.front();
		if (visited[cur] == 1) {
			q.pop();
			continue;
		}
		q.pop();
		visited[cur] = 1;
		cout << cur << " ";
		for (int i = 1; i <= N; i++) {
			if (line[cur][i] == 1 && visited[i] == 0) q.push(i);
		}
	}
}

int main() {
	cin >> N >> M >> s_num;
	for (int i = 1; i <= M; i++) {
		cin >> x >> y;
		line[x][y] = 1;
		line[y][x] = 1;
	}
	DFS(s_num);
	for (int i = 0; i < 1001; i++) {
		visited[i] = 0;
	}
	cout << endl;
	BFS(s_num);
}