#include <iostream>
#include <math.h>
#include <queue>

using namespace std;
int A, B, C;
int visited[201][201][201];
int test[201];

struct axis {
	int a; 
	int b;
	int c;
};

axis change(axis cur, int c) {
	axis n;
	int move;
	if (c == 0) { //c->a
		move = cur.a + cur.c;
		if (move > A) {
			n.a = A;
			n.b = cur.b;
			n.c = move - A;
		}
		else {
			n.a = move;
			n.b = cur.b;
			n.c = 0;
		}
	}
	if (c == 1) {//c->b
		move = cur.b + cur.c;
		if (move > B) {
			n.a = cur.a;
			n.b = B;
			n.c = move - B;
		}
		else {
			n.a = cur.a;
			n.b = move;
			n.c = 0;
		}
	} 
	if (c == 2) {//a->b
		move = cur.b + cur.a;
		if (move > B) {
			n.a = move - B;
			n.b = B;
			n.c = cur.c;
		}
		else {
			n.a = 0;
			n.b = move;
			n.c = cur.c;
		}
	} 
	if (c == 3) {//a->c
		move = cur.c + cur.a;
		if (move > C) {
			n.a = move - C;
			n.b = cur.b;
			n.c = C;
		}
		else {
			n.a = 0;
			n.b = cur.b;
			n.c = move;
		}
	} 
	if (c == 4) {//b->a
		move = cur.a + cur.b;
		if (move > A) {
			n.a = A;
			n.b = move-A;
			n.c = cur.c;
		}
		else {
			n.a = move;
			n.b = 0;
			n.c = cur.c;
		}
	} 
	if (c == 5) {//b->c
		move = cur.c + cur.b;
		if (move > C) {
			n.a = cur.a;
			n.b = move-C;
			n.c = C;
		}
		else {
			n.a = cur.a;
			n.b = 0;
			n.c = move;
		}
	} 
	return n;
}
void bfs() {
	visited[0][0][C] = 1;
	axis st;
	st.a = 0; st.b = 0; st.c = C;
	queue <axis> q;
	q.push(st);
	while (!q.empty()) {
		axis cur;
		cur.a = q.front().a;
		cur.b = q.front().b;
		cur.c = q.front().c;
		if (cur.a == 0) {
			test[cur.c] = 1;
		}
		q.pop();
		for (int i = 0; i < 6; i++) {
			axis pos = change(cur, i);
			if (visited[pos.a][pos.b][pos.c] == 0) {
				q.push(pos);
				visited[pos.a][pos.b][pos.c] = 1;
			}
		}
	}
}

int main() {
	cin >> A >> B >> C;
	bfs();
	for (int i = 0; i <= 200; i++) {
		if (test[i] == 1) cout << i<<" ";
	}
}