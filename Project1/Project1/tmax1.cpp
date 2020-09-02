#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

vector<char> com;
vector<char> result;
stack < pair<int, int >> a;

int st_idx;
int multiple;
int dis;
int idx=0;
int last;
int number;
void main() {
	com = { '2','(','3','(','h','i',')','c','o',')' };

	for (int i = 0; i < com.size(); i++) {
		if (com[i] >= '0'&&com[i]<='9') {
			for (int j = 1; j < 100; j++) {
				if (com[i + j] >= '0'&&com[i + j] <= '9') number = number + 1;
			}
			atoi(com[i : i + number]);
			a.push({ result.size() , com[i - 1] - 48});
		}
		if (com[i] == ')') {
			st_idx = a.top().first;
			multiple = a.top().second;
			last = result.size();
			a.pop();
			for (int j = 0; j < multiple - 1; j++) {
				for (int k = st_idx; k < last; k++) {
					result.push_back(result[k]);
				}
			}
		}
		if (com[i] >= 'a'&&com[i] <= 'z') {
			result.push_back(com[i]);
		}
	}


	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
}