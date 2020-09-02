#include <string>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<char> com;
vector<char> result;

void main() {
		com = { '2','(','3','(','h','i',')','c','o',')' };

		for (int i = 0; i < com.size(); i++) {
			if (com[i] >= '0'&&com[i] <= '9') {
				for (int j = 1; j < 100; j++) {
					if (com[i + j] >= '0'&&com[i + j] <= '9') number = number + 1;
				}
}