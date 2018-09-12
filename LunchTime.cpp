//4:42
#include<iostream>
#include <algorithm>
//#include <fstream>
#include <vector>
#include <deque>
using namespace std;
struct node { int x; int y; };
int N;
int map[11][11];//1.1���� ����
int numP;
node Pinfo[11];//����� 1�� ����
node Sinfo[2];//����� 0������
int SK[2];

//node Pinfo[11];//����� 1�� ����
//node Sinfo[2];//����� 0������
int stairprocess(deque<int> people, int stairnum) {
	deque<int> waiting;//��� �� ���
					   //int processflag = 0;
	deque<int> processing;
	//for (register int i = 0; i < 3; i++)processing[i] = -1;
	if (!people.empty()) {//�� ���� ����ϴ� ����� ���� ��
		for (register int i = 0; i < ((int)people.size()); i++) {
			register int distance = abs(Sinfo[stairnum].x - Pinfo[people[i]].x) + abs(Sinfo[stairnum].y - Pinfo[people[i]].y);
			people[i] = distance;//���� ��� ���� �ð����� ��� ������ �ٲ�		
		}
		sort(people.begin(), people.end());
		int t = people.front();//�� ���� �� ����

		while (!people.empty() || !waiting.empty() || !processing.empty()) {//��ΰ� �������� �� ����

			while (!people.empty() && (t == people.front())) {//���� �ð��� ���� �� ����
				waiting.push_back(people.front());
				people.pop_front();
			}

			//��� ��
			while ((int)processing.size()<3 && !waiting.empty()) {
				processing.push_back(SK[stairnum]);//�ð� ī��Ʈ ����
				waiting.pop_front();//�տ� ����� �־� ��}					
			}
			for (register int s = 0; s < (int)processing.size(); s++) {//�ð� ī��Ʈ
				processing[s] -= 1;
			}
			sort(processing.begin(), processing.end());
			while (!processing.empty() && processing.front() == 0) {
				processing.pop_front();
			}


			t++;
		}
		return t;
	}
	else return 0;
}
int devidegroup() {
	int ans = 9999;
	//�ΰ� �׷����� ������
	/* nump���� 1����� nmp���� �̴� ����� �� ����
	���� �Ŷ� �ݴ�Ǵ� �� ���� �ϳ��� s1 ������ s2�� �й�
	��ܱ����� �ð� ��� �� ª�� ������ sort�ؼ� ����
	*/

	vector<int> v;
	deque<int> stairone;
	deque<int> stairtwo;
	int time;
	for (register int iter = 0; iter < numP; iter++) {	//0��� �ٻ̴� �� �ϱ�
		stairone.push_back(iter + 1);//�� �̱�
	}
	time = max(stairprocess(stairone, 0), stairprocess(stairtwo, 1));
	ans = min(ans, time);
	time = max(stairprocess(stairone, 1), stairprocess(stairtwo, 0));
	ans = min(ans, time);
	stairone.clear();
	stairtwo.clear();
	for (int i = 1; i< numP; i++) {
		v.clear();
		for (register int j = 0; j< i; j++) {//���� ��� ��
			v.push_back(1);
		}
		for (register int j = 0; j <(numP - i); j++) {//����� 0���� ä���
			v.push_back(0);
		}
		sort(v.begin(), v.end());
		do {//srair�� ����			
			//for (register int iter = 0; iter < (int)v.size(); iter++) cout << v[iter];
			//cout << endl;
			stairone.clear();
			stairtwo.clear();
			for (register int iter = 0; iter < numP; iter++) {
				if (v[iter] == 1) {//�� ��� ��ȣ�� �־���
					stairone.push_back(iter + 1);
				}
				else stairtwo.push_back(iter + 1);
			}
			//�Ѱ� ������ stair
			time = max(stairprocess(stairone, 0), stairprocess(stairtwo, 1));
			//cout << time << endl;
			ans = min(ans, time);

		} while (next_permutation(v.begin(), v.end()));

	}

	//�Ѵ� �ð� ��� ��
	//�ð� �߿� ��ɷ� ����


	//��ȯ ans �� �ּڰ�
	return ans + 1;
}
int main(int argc, char** argv)
{
	//ifstream fin("input.txt");
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		cin >> N;
		numP = 0;
		int buf = 0;
		int stairnum = 0;
		for (register int i = 1; i <= N; i++) {
			for (register int j = 1; j <= N; j++) {
				cin >> buf;
				if (buf == 1) {//���
					numP++;
					register node one;
					one.y = i;
					one.x = j;
					Pinfo[numP] = one;
				}
				if (buf > 1) {
					SK[stairnum] = buf;
					register node one;
					one.y = i;
					one.x = j;
					Sinfo[stairnum] = one;
					stairnum++;
				}
			}
		}
		int ans;
		ans = devidegroup();



		cout << "#" << tc << " " << ans << "\n";
	}

	//system("pause");
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}