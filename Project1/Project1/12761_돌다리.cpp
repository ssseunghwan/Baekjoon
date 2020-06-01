#include <iostream>
#include <queue>

using namespace std;

int A, B, N, M;
bool visited[100001];
int main() {
	cin >> A >> B >> N >> M;
	queue<pair<int, int>> q;
	q.push({N, 0});
	while (!q.empty()) {
		int position = q.front().first;
		int cnt = q.front().second;
		if (position == M) {
			cout << cnt;
			return 0;
		}
		q.pop();
		int move[8] = {
			position + 1,position - 1,position + A,position - A,
			position + B,position - B,position * A,position * B };
		for (int i = 0; i < 8; i++) {
			if(move[i]>=0&& move[i] <=100000)
				if (!visited[move[i]]) {
					visited[move[i]] = true;
					q.push({ move[i], cnt + 1 });
				}
		}
	}
}