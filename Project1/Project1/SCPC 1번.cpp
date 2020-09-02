/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int Answer;


int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;

	for (test_case = 0; test_case < T; test_case++)
	{
		int N, K, sub;
		cin >> N >> K;
		sub = N - K;
		/*int A[200];
		int B[200];*/
		priority_queue<int, vector<int>, greater<int>> up;
		priority_queue<int, vector<int>, less<int>> down;

		int A, B;

		for (int i = 0; i < N; i++) {
			//cin >> A[i];
			cin >> A; up.push(A);
		}
		for (int i = 0; i < N; i++) {
			//cin >> B[i];
			cin >> B; down.push(B);
		}
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		//sort(A, A + N);
		//sort(B, B + N, desc);
		for (int i = 0; i < sub; i++) {
			down.pop();
		}
		//cout << "//////" << up.top() << "/////";
		for (int i = 0; i < K; i++) {
			Answer = max(Answer, up.top() + down.top());
			up.pop(); down.pop();
		}
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.

}