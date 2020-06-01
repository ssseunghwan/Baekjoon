#include <iostream>
#include <string.h>

using namespace std;



int main() {

	int num_doc, distance, up_location,doc[100];
	int total_num = 0;
	int answer[100];
	cin >> total_num ;
	for (int l = 0; l < total_num; l++) {
		int want = 0;
		int num_upper = 10;
		int count_num_of_big = 0;
		int same_num_btw = 0;

		cin >> num_doc >> want;

		for (int k = 0; k < num_doc; k++) cin >> doc[k];

		for (int i = 0; i < num_doc; i++) {
			if (doc[want] < doc[i]) {
				count_num_of_big++;
				if (num_upper >= doc[i]) {
					num_upper = doc[i];
					up_location = i;
					if (want < i) distance = want + num_doc - i - 1;
					else distance = want - i - 1;
				}
			}
		}
		
		if (count_num_of_big != 0) {
			for (int j = 0; j < distance; j++) {
				if (doc[(up_location + j + 1) % num_doc] == doc[want]) same_num_btw++;
			}
			if (l == total_num - 1) cout << same_num_btw + count_num_of_big + 1;
			else cout << same_num_btw + count_num_of_big + 1 << endl;
		}
		else{
			for (int j = 0; j < want; j++) {
				if (doc[j] == doc[want])	same_num_btw++;
			}
			if (l == total_num - 1) cout << same_num_btw + 1;
			else cout << same_num_btw + 1 << endl;
		}
	}
}
