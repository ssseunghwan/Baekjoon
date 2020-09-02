#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	vector<int> num;
	int index = -1;
	for (int i = 0; i < dartResult.size(); i++) {
		if (dartResult[i] >= '0'&&dartResult[i] <= '9') {
			index++;
			if (dartResult[i] == '1'&&dartResult[i + 1] == '0') {
				num.push_back(10);
				i++;
			}
			else {
				num.push_back(dartResult[i] - '0');
			}
		}
		if (dartResult[i] == 'D')	num[index] = (int)pow(num[index],2);
		else if (dartResult[i] == 'T') num[index] = (int)pow(num[index], 3);

		if (dartResult[i] == '*'){
			num[index-1] *= 2;
			num[index] *= 2;
		}
		if (dartResult[i] == '#') num[index] *= -1;
	}
	for (int i = 0; i < num.size(); i++) {
		answer += num[i];
	}
	return answer;
}

int main() {
	string words = "1D2S#10D";

	cout << solution(words);
}