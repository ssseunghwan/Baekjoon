#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321
#define MAX_V 20001
#define MAX_E 300001

using namespace std;

int V, E, S;

vector<pair<int, int>> route[MAX_E];

int result[MAX_V] = { 0 };

void dijkstra() {
	priority_queue<pair<int, int>> q;
	q.push({ 0, S });

	while (!q.empty()) {
		int now = q.top().second;
		int cost = -1*q.top().first;
		
		q.pop();

		for (int k = 0; k < route[now].size(); k++) {
			int new_cost = result[now] + route[now][k].second;
			int before = result[route[now][k].first];
			
			if (new_cost < before) {
				result[route[now][k].first] = new_cost;
				q.push({ -1 * new_cost, route[now][k].first });
			}
		}
	}
}

int main() {
	cin >> V >> E >> S;

	int s, d, v;
	
	for (int i = 0; i < E; i++) {	
		scanf("%d %d %d", &s, &d, &v);
		route[s].push_back(make_pair(d, v));
	}

	for (int i = 1; i <= V; i++) {
		result[i] = INF;
	}
	result[S] = 0;

	dijkstra();
	
	for (int i = 1; i <= V; i++) {
		if (result[i] != INF) printf("%d\n", result[i]);
		else printf("INF\n");
	}
	return 0;
}

