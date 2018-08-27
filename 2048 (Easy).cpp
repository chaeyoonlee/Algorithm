/* codbs0417
# 2048 (Easy)
## https://www.acmicpc.net/problem/12100

*/
#include <iostream>
#include <queue>
//#include <fstream>
#include <algorithm>
using namespace std;
int N;
int map[21][21] = { 0 };

void copymap(int arr[][21], bool flag) {

	int a, b;
	for (a = 0; a < N; a++) {
		for (b = 0; b < N; b++) {
			if (flag) arr[a][b] = map[a][b];
			else map[a][b] = arr[a][b];
		}
	}

}
void move(int direction) {
	int i, j;
	int a, b;
	queue<int> q;

	if (direction == 0) {
		for (i = 0; i < N; i++) {
			for (j = N - 1; j > -1; j--) {

				if (map[i][j] != 0) {
					q.push(map[i][j]);
					map[i][j] = 0;

				}
			}
			j = N - 1;
			while (!q.empty()) {
				a = q.front();
				q.pop();

				if (!q.empty()) b = q.front();
				else b = 0;

				if (a == b) {
					map[i][j] = a + b;
					q.pop();
					j--;
				}
				else {
					map[i][j] = a;
					j--;
				}
			}

		}
	}
	else if (direction == 1) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {

				if (map[i][j] != 0) {
					q.push(map[i][j]);
					map[i][j] = 0;
				}
			}
			j = 0;
			while (!q.empty()) {
				a = q.front();
				q.pop();

				if (!q.empty()) b = q.front();
				else b = 0;

				if (a == b) {
					map[i][j] = a + b;
					q.pop();
					j++;
				}
				else {
					map[i][j] = a;
					j++;
				}
			}

		}
	}
	else if (direction == 2) {
		for (j = 0; j < N; j++) {
			for (i = 0; i < N; i++) {

				if (map[i][j] != 0) {
					q.push(map[i][j]);
					map[i][j] = 0;
				}
			}
			i = 0;
			while (!q.empty()) {
				a = q.front();
				q.pop();

				if (!q.empty()) b = q.front();
				else b = 0;

				if (a == b) {
					map[i][j] = a + b;
					q.pop();
					i++;
				}
				else {
					map[i][j] = a;
					i++;
				}
			}

		}
	}
	else {
		for (j = 0; j < N; j++) {
			for (i = N - 1; i > -1; i--) {

				if (map[i][j] != 0) {
					q.push(map[i][j]);
					map[i][j] = 0;

				}
			}
			i = N - 1;
			while (!q.empty()) {
				a = q.front();
				q.pop();

				if (!q.empty()) b = q.front();
				else b = 0;

				if (a == b) {
					map[i][j] = a + b;
					q.pop();
					i--;
				}
				else {
					map[i][j] = a;
					i--;
				}
			}

		}
	}



}

int play(int count) {
	//±âÀú»ç·Ê
	int ret = 0;
	int i;
	if (count == 5) {
		int a, b;
		int max = 0;
		for (a = 0; a < N; a++) {
			for (b = 0; b < N; b++) {
				if (max < map[a][b]) max = map[a][b];
			}
		}
		return max;
	}


	int tmparr[21][21];
	for (i = 0; i < 4; i++) {
		copymap(tmparr, true);
		move(i);
		ret = max(ret, play(count + 1));
		copymap(tmparr, false);
	}

	return ret;
}


int main() {
	//ifstream fin("input.txt");
	//fin >> N;
	cin >> N;
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			//fin >> map[i][j];
			cin >> map[i][j];
		}
	}

	int ans = play(0);
	cout << ans;

	//system("pause");
	return 0;
}