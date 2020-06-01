#include <iostream>
#include <algorithm>
using namespace std;

int routes[101][101];
int n, m;
int HIGH = 100000001;

int main() {
	cin >> n >> m;
	int start, dest, cost;

	for (int i = 1; i <= m; i++) {
		cin >> start >> dest >> cost;
		if (routes[start][dest] != 0)
			routes[start][dest] = min(routes[start][dest], cost);
		else routes[start][dest] = cost;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (routes[i][j] == 0&&i!=j) routes[i][j] = HIGH;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (routes[i][k] + routes[k][j] < routes[i][j])
					routes[i][j] = routes[i][k] + routes[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (routes[i][j] >= HIGH) routes[i][j] = 0;
			cout << routes[i][j] << " ";
		}
		if(i<n)
			cout << endl;
	}
}
