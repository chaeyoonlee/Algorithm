#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);

	int n, m;
	int bus[102][102];

	cin >> n;
	cin >> m;
	int s, e, c;
	int INF = 999999;
	for (int i = 1; i <= n; i++)//초기화
		for (int j = 1; j <= n; j++)
		{
			bus[i][j] = INF;
		}
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> c;
		if (bus[s][e]>c)bus[s][e] = c;//시작 도착점이 같은 버스 중에 최솟값만 저장
	}
	//플로이드
	for (int k = 1; k <= n; k++) {//경유지를 중심으로 해야 경유지 update가 반영됨
		for (int i = 1; i <= n; i++) {//출발점
			for (int j = 1; j <= n; j++) {//도착점
				if (k == i || i == j || k == j)continue;//자기자신은 할 필요가 없음
				if (bus[i][j] > bus[i][k] + bus[k][j]) {//경유지 거치는 게 더 작으면 update
					bus[i][j] = bus[i][k] + bus[k][j];

				}

			}
		}
	}
//출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (bus[i][j] == INF)cout << 0 << " ";
			else cout << bus[i][j] << " ";
		}cout << "\n";
	}

	return 0;
}