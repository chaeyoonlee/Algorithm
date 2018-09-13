//11:30
#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, C;
int honeyhouse[10][10];//원래 수 저장
int maxmap[10][10]; // 시작점부터 M개까지를 합쳐 시작점에 M개 중의 최댓값을 찾아 저장

void calMmax() {//지도에서 m개를 뽑아 m안에서의 가능한 최댓값을 구함 
	vector<int> pick;
	int ret = 0;
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j <= N - M; j++) {//오른쪽으로만 탐색 마지막에는 M개 전까지만 탐색
		{//범위를 벗어나지 않는 다면 M안에서의 최댓값을 뽑음
				register int totalmax = 0;
				for (int p = M; p >0; p--) {//뽑은 것중 M개부터 1개 뽑음
					pick.clear();//초기화
					register int add = 0;
					register int money = 0;
					register int ccheck = 0;
					for (register int a = (M - p); a > 0; a--) pick.push_back(0);
					for (register int a = p; a > 0; a--) pick.push_back(1);//뽑을 개수 만큼
					do {
						money = 0;
						add = 0;
						for (register int ppoint = 0; ppoint < M; ppoint++) {
							if (pick[ppoint] == 1) {//뽑은 거라면
								add += honeyhouse[i][j + ppoint];
								if (add > C) break;//채취할 수 없다면 넘김
								money += (honeyhouse[i][j + ppoint] * honeyhouse[i][j + ppoint]);//비용인 제곱 구하기
							}
						}
						if (add <= C)	totalmax = max(totalmax, money);//총 합 다시한번 점검하고 최댓 돈 max update

					} while (next_permutation(pick.begin(), pick.end()));
				}
				maxmap[i][j] = totalmax;
				//print();
			}
			else break;
		}
	}

}
int FindMaxOfTwo(int add, int count, int visitedy, int visitedx) {
	int ret = 0;
	if (count == 2) {
		return add;
	}
	else {
		for (register int i = 0; i < N; i++) {
			for (register int j = 0; j <= N - M; j++) {
				if (visitedx == -1 || (visitedx + (M - 1)<j || visitedy != i)) {//방문한 적이 없고 m칸 떨어져 있으면				
					ret = max(ret, FindMaxOfTwo(add + maxmap[i][j], count + 1, i, j));

				}
			}
		}
	}
	return ret;
}
int main() {

	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	register int ret;
	for (register int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> C;
		for (register int i = 0; i < N; i++) {
			for (register int j = 0; j < N; j++) {
				cin >> honeyhouse[i][j];
				maxmap[i][j] = 0;
			}
		}

		calMmax();//M마다 각각의 최댓값 구하기
		ret = FindMaxOfTwo(0, 0, -1, -1);//구한 최댓값중 겹치지 않고 합이 최대가 되는 것 고르기

		cout << "#" << tc << " " << ret << "\n";
	}
	return 0;
}