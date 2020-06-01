#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
int visited[1000001];

int main() {
	cin >> F >> S >> G >> U >> D;
	queue<pair<int, int>> q;
	q.push({ S, 0 });
	visited[S] = 1;
	while (!q.empty()) {
		int position = q.front().first;
		int cnt = q.front().second;
		if (position == G) {
			cout << cnt;
			return 0;
		}
		q.pop();
		int move[2] = { position + U ,position - D };
		for (int i = 0; i < 2; i++) {
			if (move[i] >= 1 && move[i] <= F && visited[move[i]] == 0) {
				q.push({ move[i],cnt + 1 });
				visited[move[i]] = 1;
			}
		}
	}
	cout << "use the stairs";
	return 0;
}