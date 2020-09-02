/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <algorithm>
#include <queue>

struct axis {
	int layer;
	int num;
	int s;
};
using namespace std;

int Answer;
int o_map[2000][1501];
int result[100001];
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
	for (int i = 0; i < m; i++) {
		result[i] = 0;
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
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	 // freopen("input.txt", "r", stdin);

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
		for (int i = 0; i < m; i++) {
			int s, d;
			cin >> s >> d;
			queue<axis> a;
			axis now;
			now.layer = 0;
			now.s = s;
			for (int j = 0; j < k; j++) {
				if (result[i] != 0)break;
				now.num = j;
				a.push(now);
				while (!a.empty()) {
					axis nnow;
					if (a.front().layer == k) {
						if (d == a.front().s) {
							result[i] = k-j;
							break;
						}
						else a.pop();
					}
					else {
						if (o_map[a.front().layer][a.front().s] == 0) {
							nnow.layer = a.front().layer + 1;
							nnow.num = a.front().num;
							nnow.s = a.front().s;
							a.pop();
							a.push(nnow);
						}
						else {
							if (a.front().num > 0) {
								nnow.layer = a.front().layer + 1;
								nnow.num = a.front().num - 1;
								nnow.s = a.front().s;
								a.push(nnow);
								nnow.num = a.front().num;
								nnow.s = o_map[a.front().layer][a.front().s];
								a.push(nnow); 
								a.pop();
							}
							else {
								nnow.layer = a.front().layer + 1;
								nnow.num = a.front().num;
								nnow.s = o_map[a.front().layer][a.front().s];
								a.push(nnow);
								a.pop();
							}
						}
					}
				}
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////
		for (int i = 0; i < m; i++) {
			if (result[i] == 0) sum = sum - 1;
			else sum = sum + k - result[i];
		}
		Answer = sum;

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}