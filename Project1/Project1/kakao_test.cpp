#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
	vector<int> ans;
	int x1, x2, y1, y2;
	int nx1 = 0; int nx2 = 0; int ny1 = 0; int ny2 = 0;

	x1 = v[0][0]; nx1++;
	y1 = v[0][1]; ny1++;

	for (int i = 1; i < 3; i++) {
		if (v[i][0] == x1) nx1++;
		else {
			x2 = v[i][0];
			nx2++;
		}
		if (v[i][1] == y1) ny1++;
		else {
			y2 = v[i][1];
			ny2++;
		}
	}
	if (nx1 == 2) ans.push_back(x2);
	else ans.push_back(x1);

	if (ny1 == 2) ans.push_back(y2);
	else ans.push_back(y1);

	cout << "Hello Cpp" << endl;

	return ans;
}

int main() {
	vector<int> result;
	vector<vector<int>> input;
	input.push_back({ 1,4 });
	input.push_back({ 3,4 });
	input.push_back({ 3,10 }); 

	cout << input[0][1];
	//for(int i=0; i)

	result = solution(input);

	cout << result[0] << result[1];
	return 0;
}