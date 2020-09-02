#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	vector<char> line;
	string line_s;
	int num1, num2;
	//cout << "hello";
	for (int i = 0; i < n; i++) {
		line.clear();
		num1 = arr1[i]; num2 = arr2[i];
		line_s = "";
		for (int j = n - 1; j >= 0; j--) {
			if (num1 / (int)pow(2, j) == 1) {
				num1 = num1 - pow(2, j);
				line.push_back('#');
			}
			else line.push_back(' ');
		}

		for (int j = n - 1; j >= 0; j--) {
			if (num2 / (int)pow(2, j) == 1) {
				num2 = num2 - pow(2, j);
				line[n - 1 - j] = '#';
			}
		}
		for (int j = 0; j < n; j++) {
			line_s += line[j];
		}
		answer.push_back(line_s);
	}
	return answer;
}

int main() {
	vector<int> arr1 = { 9,20,28,18,11};
	vector<int> arr2 = { 30,20,28,18,11 };
	vector<string> result;

	result = solution(5, arr1, arr2);

	
	for (int i = 0; i < result.size(); i++) {
		cout <<result[i]<< endl;
	}
}