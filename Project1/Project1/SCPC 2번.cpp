#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int Answer1, Answer2;
bool map[3001][3001];

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
		for (int i = 0; i <= 3000; i++) {
			for (int j = 0; j <= 3000; j++) {
				map[i][j] = false;
			}
		}
		int X[3001];
		int Y[3001];
		Answer1 = 0;
		Answer2 = 0;
		
		int n, k,v;
		cin >> n >> k;
		
		for (int i = 1; i <= n; i++) {
			cin >> X[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> Y[i];
		}
		map[0][0] = true;
		/////////////////////////////////////////////////////////////////////////////////////////////
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j<= n; j++) {
				//x Ãà ¹æÇâ ÆØÃ¢ 
				int x = 0;
				if (map[i][j] == false) {
					for (int l = j + 1; l <= n; l++) {
						x = x + X[l];
						if (x <= k) map[i][l] = !(map[i][j]);
						else break;

					} 
					int y = 0;
					// y Ãà ¹æÇâ ÆØÃ¢
					for (int l = i + 1; l <= n; l++) {
						y = y + Y[l];
						if (y <= k)	map[l][j] = !(map[i][j]);
						else break;
					}
				}
			}
		}

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (map[i][j] == true) Answer1++;
				else Answer2++;
			}
		}
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer1 <<" " << Answer2 <<endl;
	}

	return 0;//Your program should return 0 on normal termination.
}