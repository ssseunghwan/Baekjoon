#include <iostream>
#include <algorithm>
#include <queue>

struct axis {
	int layer;
	int num;
	int s;
	int c;
};
using namespace std;

int Answer;
int o_map[2000][1501];
int result[1501][1501];
int N, k, m;
int x, y, sum;

//void combination(int layer, int num, int rank, int d, int c) {
//	if (layer == k) {
//		if(d==c) result[rank] = max(result[rank], k - num);
//	}
//	else {
//		if (o_map[layer][c] == 0) combination(layer + 1, num, rank, d, c);
//		else {
//			combination(layer + 1, num, rank, d, o_map[layer][c]);
//			combination(layer + 1, num+1, rank, d, c);
//		}
//	}
//}

void clear() {
	for (int i = 0; i <= 1500; i++) {
		for (int j = 0; j <= 1500; j++) {
			result[i][j] = 0;
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j <= N; j++) {
			o_map[i][j] = 0;
		}
	}
}
int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> N >> k >> m;
		Answer = 0; sum = 0;
		clear();
		
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			o_map[i][x] = y; o_map[i][y] = x;
		}
		queue<axis> a;
		axis now;
		now.layer = 0;
		now.num = 0;
		
		for (int i = 0; i < m; i++) {
			int s, d;
			cin >> s >> d;
			if(started[s]==0){
			now.s = s;
			now.c = s;
			a.push(now);
		}
		for (int i = 1; i <= N; i++) {
			
		}
		while (!a.empty()) {
			axis nnow;
			if (a.front().layer == k) {
				result[a.front().s][a.front().c] = max(k-a.front().num, result[a.front().s][a.front().c]);
				a.pop();
			}
			else {
				if (o_map[a.front().layer][a.front().s] == 0) {
					nnow.layer = a.front().layer + 1;
					nnow.num = a.front().num;
					nnow.s = a.front().s;
					nnow.c = a.front().c;
					a.pop();
					a.push(nnow);
				}
				else {
					//combination(layer + 1, num, rank, d, o_map[layer][c]);
					nnow.layer = a.front().layer + 1;
					nnow.num = a.front().num + 1;
					nnow.s = a.front().s;
					nnow.c = a.front().c;
					a.push(nnow);
					nnow.num = a.front().num;
					nnow.s = a.front().s;
					nnow.c = o_map[a.front().layer][a.front().c];
					a.push(nnow);
					a.pop();
				}
			}
		}
		
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////
		
		/*for (int i = 0; i < m; i++) {
			if (result[i] == 0) sum = sum - 1;
			else sum = sum + k - result[i];
		}*/
		Answer = sum;

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}
	return 0;//Your program should return 0 on normal termination.
}