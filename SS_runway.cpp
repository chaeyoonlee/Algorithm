#include <iostream>
//#include <fstream>
using namespace std;
int N, X;
int map[21][21] = { 0 };
int main() {
	ios::sync_with_stdio(false);
	int tc;
	cin >> tc;
	
	//ifstream fin("input.txt");
	//fin >> tc;
	for (register int t = 1; t < tc + 1; t++) {
	//fin >> N >> X;
	cin >> N >> X;
	int ans;
	int add = 0;
	int sameme;
	int me;
	int front;
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			cin >> map[i][j];
			//fin >> map[i][j];


		}
		//������ �ϳ� �޾Ƽ�
		me = 0;//ó���� set
		sameme = 1;
		ans = 1;
		while (me <(N-1)) {//0~N-1
			if (ans == 0) break; 
			front = me + 1;
			//cout << "me : " << me<<" valsu : "<<map[i][me] << " front : " << front<<" value : "<<map[i][front] <<"\n";
			if (abs(map[i][front] - map[i][me]) > 1) { //���� ���� 2�̻��̸�
				ans = 0; break;
			}
			if (map[i][front] > map[i][me]) {//���� ���� -> ��ܳ��� �� �ִ� ��
				if (sameme < X) { ans = 0; break; }
				else {//front�� me�� �ٲ��ְ� ���ο� ����
					me = front;
					sameme = 1;
				}
			}
			else if (map[i][front] < map[i][me]) {//���� ����
				me = front;//������ ���鼭 ��� ���� �� �ִ���
				sameme = 1;
				++front;
				while (X != sameme) {
					if (me == N) { ans = 0; break; }

					if (map[i][front] != map[i][me]) { ans = 0; break; }
					else {
						me = front;
						front++;
						sameme++;
					}
				}
				
				sameme =0;
			}
			else {
				sameme++;
				me = front;

			}
		}
		//cout << "i : " << i << "ans : " << ans << endl;
		add += ans;
	}
	
	//���� ��
	for(register int j = 0; j < N; j++) {
		me = 0;//ó���� set
		sameme = 1;
		ans = 1;
		while (me <(N - 1)) {
			if (ans == 0) break;
			front = me + 1;
			//cout << "me : " << me<<" valsu : "<<map[me][j] << " front : " << front<<" value : "<< map[front][j] <<"\n";
			if (abs(map[front][j] - map[me][j]) > 1) { //���� ���� 2�̻��̸�
				ans = 0; break;
			}
			if (map[front][j] > map[me][j]) {//���� ���� -> ��ܳ��� �� �ִ� ��
				if (sameme < X) { ans = 0; break; }
				else {//front�� me�� �ٲ��ְ� ���ο� ����
					me = front;
					sameme = 1;
				}
			}
			else if (map[front][j] < map[me][j]) {
				me = front;//������ ���鼭 ��� ���� �� �ִ���
				sameme = 1;
				++front;
				while (X != sameme) {	
					if (me == N) { ans = 0; break; }
						if (map[front][j]!= map[me][j]) { ans = 0; break; }
						else {
							me = front;
							front++;
							sameme++;
						}
				}
				
				sameme=0;
			}
			else {
				sameme++;
				me = front;

			}
		}
		//cout << "j : " << j << "ans : " << ans << endl;
		add += ans;
	}
	//cout << add;
	cout <<"#"<<t <<" "<<add<<"\n";
	}

	//system("pause");

	return 0;

}