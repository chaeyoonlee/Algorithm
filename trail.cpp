#include<iostream>
//#include <fstream>
#include <algorithm>
using namespace std;
int N, K;
int map[8][8];
int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };//상 하 좌우0 y
int ans = 0;
bool visited[8][8] = { false };
void trail(int y, int x, int count, bool k) {
	int tmpy, tmpx;
	bool flag = false;
	//int ret = 0;
	for (register int i = 0; i < 4; i++) { //상,하,좌,우 
		tmpy = y + dir[i][0];
		tmpx = x + dir[i][1];
		if (visited[tmpy][tmpx] == false && (tmpy > -1 && tmpy<N&&tmpx>-1 && tmpx < N)) {//방문한 적 없고 범위 안일 때
			if (map[tmpy][tmpx] < map[y][x]) {//낮은 지형 바로 갈 수 있음
				visited[tmpy][tmpx] = true;
				trail(tmpy, tmpx, count + 1, k);

				visited[tmpy][tmpx] = false;
			}
			else if (k == false) {
				register int tk = K;
				while (tk != 0) {//K는 최대 공사 높이이니 모든 경우 다 해줘야함!!!!!! 이거 안읽어서 틀렸었음
					if ((map[tmpy][tmpx] - tk) < map[y][x]) {
						k = true;
						register int tmpmap = map[tmpy][tmpx];
						map[tmpy][tmpx] -= tk;
						visited[tmpy][tmpx] = true;
						trail(tmpy, tmpx, count + 1, k);
						k = false;
						map[tmpy][tmpx] = tmpmap;
						visited[tmpy][tmpx] = false;

					}
					tk--;
				}
			}

		}

	}
	ans = max(ans, count);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	//ifstream fin("input.txt");
	int T;
	cin >> T;
	int highest;
	int top[5][2];//가장 높은 거 최대 5개
	int numoftop;
	int ret = 0;
	for (register int tc = 1; tc <= T; tc++) {
		cin >> N >> K;
		highest = 0;//초기화
		ans = 0;
		for (register int i = 0; i < N; i++) {
			for (register int j = 0; j < N; j++) {
				visited[i][j] = false;
				cin >> map[i][j];
				if (map[i][j] > highest) highest = map[i][j];
			}
		}
		numoftop = 0;//초기화
		for (register int i = 0; i < N; i++) {
			for (register int j = 0; j < N; j++) {
				if (map[i][j] == highest) {
					top[numoftop][0] = i;//0 = y/ 1 = x
					top[numoftop][1] = j;
					numoftop++;
				}
			}
		}
		//가장 높은 곳 부터 시작
		for (register int i = 0; i < numoftop; i++) {
			visited[top[i][0]][top[i][1]] = true;
			trail(top[i][0], top[i][1], 1, false);
			//cout << ans << endl;
			visited[top[i][0]][top[i][1]] = false;
		}



		cout << "#" << tc << " " << ans << "\n";
	}

	//system("pause");
	return 0;
}