#include <string>
#include <vector>
#include <iostream>

using namespace std;

//int solution(vector<string> lines) {
//	int answer = 0;
//	string line, line2;
//	line.copy(&line2[0], 3, 5);
//	vector<vector<double>> t_table;
//	
//	for (int i = 0; i < lines.size; i++) {
//		double t_start, t_end;
//		t_end = 3600 * (lines[i][11]*10 + lines[i][12]) + 
//			60 * stod(lines[i][14] + lines[i][15]) + (lines[i][14] * 10 + lines[i][15])
//	}
//	
//	return answer;
//}


int main() {
	int result;

	string abc = "abcdefg";
	string token = "";

	abc.copy(&token[0], abc.length(), 0);

	for (int i = 0; i < token.length(); i++) {
		cout << token[i];
	}
	vector<string> lines = {
		"2016-09-15 01:00:04.001 2.0s",
		"2016-09-15 01:00:07.000 2s"
	};

	//result = solution(lines);

	//cout << line[20] << line[21] << line[22];
}