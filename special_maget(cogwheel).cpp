//11:20
#include <iostream>
#include <deque>
//#include <fstream>
using namespace std;

struct sn {
	deque<int> num;//8�� ���� ���� �ڼ� ��ȣ
};
struct kinfo {
	int clockid;
	int clockwise;
};
kinfo makenewkinfo(int id, int wise) {
	kinfo newone;
	newone.clockid = id;
	newone.clockwise = wise;
	return newone;
}
/*void printsades(int id, sn clock) {
cout << "clock id : " << id << "\n";
for (register int j = 0; j < 8; j++) {

cout << clock.num.front();
clock.num.pop_front();
}cout << "\n";
}*/
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	//ifstream fin("input.txt");
	int T;
	cin >> T;
	int k;
	sn sladeinfo[4];
	int buf;
	int clockid, clockwise;
	deque<kinfo> ks;
	int score[4] = { 1,2,4,8 };
	for (int tc = 0; tc < T; tc++) {
		cin >> k;
		//deque ����
		if (!ks.empty()) while (!ks.empty()) ks.pop_back();
		for (register int i = 0; i < 4; i++) {
			//�� ����
			if (!sladeinfo[i].num.empty()) {
				while (!sladeinfo[i].num.empty()) sladeinfo[i].num.pop_back();
			}
			//�� ���� �ޱ�
			for (register int j = 0; j < 8; j++) {
				cin >> buf;
				sladeinfo[i].num.push_back(buf);
			}
			//printsades(i, sladeinfo[i]);

		}
		for (register int j = 0; j < k; j++) {
			//k���� �ޱ�
			cin >> clockid >> clockwise;
			--clockid;//���� �ð� 0�� ���� ����
					  //bfs �� �����ֱ�
					  //ó���� ���� �� �ְ�
			ks.push_back(makenewkinfo(clockid, clockwise));
			register int originid = clockid;
			register int originwise = clockwise;
			//�� ���� �Ļ� �˻�
			while (clockid>0) {//���� �˻��ϴ� �갡 1�϶�����
				if (sladeinfo[clockid].num[6] != sladeinfo[clockid - 1].num[2]) {
					//���� 6���� ������ 2���� �ٸ���
					clockid -= 1;//id�ϳ� �������� �Ű��ְ�
					clockwise *= (-1);//���� �ݴ�� �����ְ�
					ks.push_back(makenewkinfo(clockid, clockwise));
				}
				else break;//������ �Ļ� stop
			}
			//������ �Ļ� �˻�
			clockid = originid;//���� �� �����ְ�
			clockwise = originwise;//���� ����
			while (clockid < 3) {//������ �˻��ϴ� �갡 2�϶� ����
				if (sladeinfo[clockid].num[2] != sladeinfo[clockid + 1].num[6]) {
					//���� 2���� �� �������� 6���� �ٸ���
					clockid += 1;//id�ϳ� ���������� �Ű��ְ�
					clockwise *= (-1);//���� �ݴ�� �����ְ�
					ks.push_back(makenewkinfo(clockid, clockwise));
				}
				else break;//������ �Ļ� stop
			}
			//ks�� �ִ� �� ������ -> ť empty�� �����
			kinfo thisone;
			while (!ks.empty()) {
				thisone = ks.front();
				ks.pop_front();
				//cout << "before slade " << thisone.clockid << "\n";
				//printsades(thisone.clockid, sladeinfo[thisone.clockid]);
				//cout << "after\n";

				if (thisone.clockwise == 1) {//�ð� ����
											 //�ڿ����� ���� �� �տ�
					register int back = sladeinfo[thisone.clockid].num.back();
					sladeinfo[thisone.clockid].num.pop_back();
					sladeinfo[thisone.clockid].num.push_front(back);
				}
				else {//�ݽð�
					  //�� �տ����� �� �ڷ�
					register int front = sladeinfo[thisone.clockid].num.front();
					sladeinfo[thisone.clockid].num.pop_front();
					sladeinfo[thisone.clockid].num.push_back(front);
				}
				//cout << "after\n";
				//printsades(thisone.clockid, sladeinfo[thisone.clockid]);

			}
		}
		//0���ڸ� �˻��� ���� ���
		int ans = 0;
		for (register int i = 0; i < 4; i++) {
			if (sladeinfo[i].num[0] == 1) ans += score[i];
		}
		cout << "#" << tc + 1 << " " << ans << endl;
	}
	//system("pause");
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}