//11:30
#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, C;
int honeyhouse[10][10];//���� �� ����
int maxmap[10][10]; // ���������� M�������� ���� �������� M�� ���� �ִ��� ã�� ����

void calMmax() {//�������� m���� �̾� m�ȿ����� ������ �ִ��� ���� 
	vector<int> pick;
	int ret = 0;
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j <= N - M; j++) {//���������θ� Ž�� ���������� M�� �������� Ž��
		{//������ ����� �ʴ� �ٸ� M�ȿ����� �ִ��� ����
				register int totalmax = 0;
				for (int p = M; p >0; p--) {//���� ���� M������ 1�� ����
					pick.clear();//�ʱ�ȭ
					register int add = 0;
					register int money = 0;
					register int ccheck = 0;
					for (register int a = (M - p); a > 0; a--) pick.push_back(0);
					for (register int a = p; a > 0; a--) pick.push_back(1);//���� ���� ��ŭ
					do {
						money = 0;
						add = 0;
						for (register int ppoint = 0; ppoint < M; ppoint++) {
							if (pick[ppoint] == 1) {//���� �Ŷ��
								add += honeyhouse[i][j + ppoint];
								if (add > C) break;//ä���� �� ���ٸ� �ѱ�
								money += (honeyhouse[i][j + ppoint] * honeyhouse[i][j + ppoint]);//����� ���� ���ϱ�
							}
						}
						if (add <= C)	totalmax = max(totalmax, money);//�� �� �ٽ��ѹ� �����ϰ� �ִ� �� max update

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
				if (visitedx == -1 || (visitedx + (M - 1)<j || visitedy != i)) {//�湮�� ���� ���� mĭ ������ ������				
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

		calMmax();//M���� ������ �ִ� ���ϱ�
		ret = FindMaxOfTwo(0, 0, -1, -1);//���� �ִ��� ��ġ�� �ʰ� ���� �ִ밡 �Ǵ� �� ����

		cout << "#" << tc << " " << ret << "\n";
	}
	return 0;
}