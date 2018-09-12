#include<iostream>
//#include <fstream>
#include <algorithm>
using namespace std;
int map[20][20];
int check[20][20];
int N, M;
int numhouse;
inline int cost(int K) {
	return ((K * K) + ((K - 1) * (K - 1)));
}
int count(int k, int y, int x) {

	register int a, b;
	register int cnt = 0;
	for (b = -(k - 1); b < k; b++) {//-(k-1) ~ (k-1)
		for (a = -(k - 1 - abs(b)); a<(k - abs(b)); a++) {
			if ((x + a) >= 0 && (x + a) <= N - 1 && (y + b) >= 0 && (y + b) <= N - 1)//범위에 포함될 때 체크
			{
				if (map[y + b][x + a] == 1) {//집이 포함됨
					cnt++;

				}

			}
		}
	}

	return cnt;
}
int dependingonk() {
	int tryk = 1;
	//int tryk = 4;
	int ret = 0;
	int tmp = 0;
	//cout << "numhouse : " << numhouse << " numhouse*M : " << numhouse * M << endl;
	while (numhouse*M >= cost(tryk)) {
		for (register int i = 0; i < N; i++) {
			for (register int j = 0; j < N; j++) {
				tmp = count(tryk, i, j);
				if (cost(tryk) <= (M * tmp)) {
					ret = max(ret, tmp);
					//cout << i<<j<<" k = "<< tryk <<" count "<<tmp << endl;
				}

			}
		}

		tryk++;
	}
	return ret;
}
int main() {

	ios::sync_with_stdio(false);
	//ifstream fin("input.txt");
	int T;
	cin >> T;

	for (register int tc = 1; tc <= T; tc++) {
		numhouse = 0;
		cin >> N >> M;
		for (register int i = 0; i < N; i++) {
			for (register int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1)numhouse++;
			}
		}

		int ans = dependingonk();
		cout << "#" << tc << " " << ans << "\n";
	}

	//system("pause");
	return 0;
}