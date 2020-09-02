#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
	int answer = 0;//A=65, a=97
	int map1[26][26] = { 0, };
	int map2[26][26] = { 0, };
	int min_num = 0; int max_num = 0;
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] >= 97 && str1[i] <= 122) {
			str1[i] = str1[i] - 32;
		}

	}
	for (int i = 0; i < str2.size(); i++) {
		if (str2[i] >= 97 && str2[i] <= 122) {
			str2[i] = str2[i] - 32;
		}
	}
	//map1,map2
	for (int i = 0; i < str1.size() - 1; i++) {
		if (str1[i] >= 65 && str1[i] <= 90 && str1[i+1] >= 65 && str1[i+1] <= 90) {
			map1[str1[i] - 65][str1[i + 1] - 65] += 1;
		}
	}
	for (int i = 0; i < str2.size() - 1; i++) {
		if (str2[i] >= 65 && str2[i] <= 90 && str2[i + 1] >= 65 && str2[i + 1] <= 90) {
			map2[str2[i] - 65][str2[i + 1] - 65] += 1;
		}
	}
	//min,max
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			min_num += min(map1[i][j], map2[i][j]);
			max_num += max(map1[i][j], map2[i][j]);
		}
	}
	if (max_num == 0) return 65536;
	answer = int((double)min_num / max_num * 65536);
	return answer;
}

int main() {
	string a, b;
	a = "handshake";
	b = "shake hands";
	cout << solution(a, b);
}