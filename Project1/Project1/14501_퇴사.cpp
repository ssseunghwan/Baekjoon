#include <iostream>
#include <algorithm>
using namespace std;

int N;
int info[16][2];
int salary[22];
int m_sal=0;

int main() {
	cin >> N;
	for (int i = 1; i < N+1; i++) {
		cin >> info[i][0] >> info[i][1];
	}

	for (int i = 1; i <= N+1; i++) {
		for (int l = 1; l <=i-1; l++) {
			salary[i] = max(salary[i], salary[l]);
		}
		salary[i + info[i][0]] = max(salary[i + info[i][0]], salary[i] + info[i][1]);
		
		
	}
	for (int j = 1; j <= N + 1; j++) {
				m_sal = max(m_sal, salary[j]);
	}
	cout << m_sal;

}
