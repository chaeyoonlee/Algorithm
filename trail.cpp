#include<iostream>
//#include <fstream>
#include <algorithm>
using namespace std;
int N, K;
int map[8][8];
int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };//�� �� �¿�0 y
int ans = 0;
bool visited[8][8] = { false };
void trail(int y, int x, int count, bool k) {
	int tmpy, tmpx;
	bool flag = false;
	//int ret = 0;
	for (register int i = 0; i < 4; i++) { //��,��,��,�� 
		tmpy = y + dir[i][0];
		tmpx = x + dir[i][1];
		if (visited[tmpy][tmpx] == false && (tmpy > -1 && tmpy<N&&tmpx>-1 && tmpx < N)) {//�湮�� �� ���� ���� ���� ��
			if (map[tmpy][tmpx] < map[y][x]) {//���� ���� �ٷ� �� �� ����
				visited[tmpy][tmpx] = true;
				trail(tmpy, tmpx, count + 1, k);

				visited[tmpy][tmpx] = false;
			}
			else if (k == false) {
				register int tk = K;
				while (tk != 0) {//K�� �ִ� ���� �����̴� ��� ��� �� �������!!!!!! �̰� ���о Ʋ�Ⱦ���
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
	int top[5][2];//���� ���� �� �ִ� 5��
	int numoftop;
	int ret = 0;
	for (register int tc = 1; tc <= T; tc++) {
		cin >> N >> K;
		highest = 0;//�ʱ�ȭ
		ans = 0;
		for (register int i = 0; i < N; i++) {
			for (register int j = 0; j < N; j++) {
				visited[i][j] = false;
				cin >> map[i][j];
				if (map[i][j] > highest) highest = map[i][j];
			}
		}
		numoftop = 0;//�ʱ�ȭ
		for (register int i = 0; i < N; i++) {
			for (register int j = 0; j < N; j++) {
				if (map[i][j] == highest) {
					top[numoftop][0] = i;//0 = y/ 1 = x
					top[numoftop][1] = j;
					numoftop++;
				}
			}
		}
		//���� ���� �� ���� ����
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