#include <iostream>
#include <algorithm>

using namespace std;

int Answer;
int o_map[15][20];
pair<int,int> task[400];
int result[400];
int N, k, m;
int x, y, sum;

void find(int map[15][20],int num) {
	for (int i = 0; i < m; i++) {
		int s = task[i].first;
		int d = task[i].second;
		int c;
		for (int j = 0; j < k; j++) {
			if (j == 0) {
				if (map[j][s] == 0) {
					c = s;
					continue;
				}
				else c = map[j][s];
			}
			else {
				if (map[j][c] == 0) {
					continue;
				}
				else c = map[j][c];
			}
		}
		if (c == d)	result[i] = max(result[i], k-num);
	}
}

void combination(int layer, int map[15][20], int num) {
	if (layer == k) {
		find(map,num);
	}
	else {
		combination(layer + 1, map, num);
		for (int i = 0; i < N; i++) {
			map[layer][i] = 0;
		}
		combination(layer + 1, map, num + 1);
	}
}

void clear() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 20; j++) {
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
		cin >> N >>k >>m;
		Answer = 0;
		clear();
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			o_map[i][x] = y; o_map[i][y] = x;
		}
		for (int i = 0; i < m; i++) {
			int s, d;
			cin >> s >> d;
			task[i] = { s,d };
		}
		combination(0,o_map,0);
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////
		sum = 0;
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