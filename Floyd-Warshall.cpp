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
	for (int i = 1; i <= n; i++)//�ʱ�ȭ
		for (int j = 1; j <= n; j++)
		{
			bus[i][j] = INF;
		}
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> c;
		if (bus[s][e]>c)bus[s][e] = c;//���� �������� ���� ���� �߿� �ּڰ��� ����
	}
	//�÷��̵�
	for (int k = 1; k <= n; k++) {//�������� �߽����� �ؾ� ������ update�� �ݿ���
		for (int i = 1; i <= n; i++) {//�����
			for (int j = 1; j <= n; j++) {//������
				if (k == i || i == j || k == j)continue;//�ڱ��ڽ��� �� �ʿ䰡 ����
				if (bus[i][j] > bus[i][k] + bus[k][j]) {//������ ��ġ�� �� �� ������ update
					bus[i][j] = bus[i][k] + bus[k][j];

				}

			}
		}
	}
//���
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (bus[i][j] == INF)cout << 0 << " ";
			else cout << bus[i][j] << " ";
		}cout << "\n";
	}

	return 0;
}