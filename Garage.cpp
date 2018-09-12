//10:45-12:15
#include<iostream>
//#include<fstream>
#include <deque>
#include <vector>
using namespace std;
int N, M, K, A, B;//N M K ��� 1������ ����
int recepstaff[10];
int reapairstaff[10];

int kvisit[1001];


struct customer {
	int k;//�ڱ� ��ȣ
	int t;//������ �ð� or ���� �ð�
};
int repair(deque<customer> custorepair, vector<int> Acheck) {
	//for (register int j = 0; j < Acheck.size(); j++) {
	//	cout << Acheck[j];
	//}
	int ans = 0;
	deque<int> waiting;
	customer processing[10];
	for (register int i = 0; i < N + 1; i++) {//�ʱ�ȭ
		processing[i].k = -1;
		processing[i].t = -1;
	}
	int t = 0;
	if (!custorepair.empty()) { t = custorepair.front().t; }


	while (!custorepair.empty() || !waiting.empty()) {
		while (!custorepair.empty() && t == custorepair.front().t) {//�ð��� ����� �� �־��ְ�
			waiting.push_back(custorepair.front().k);
			custorepair.pop_front();
		}
		for (register int i = 1; i < M + 1; i++) {
			if (waiting.empty()) break;
			else if (processing[i].k == -1) {//���� ����� �ְ� ����ִٸ�
				processing[i].k = waiting.front();//��� �־��ְ�
				waiting.pop_front();
				processing[i].t = reapairstaff[i];//�ð� ����
												  //ans ���ϱ�
				if (i == B) {
					for (register int j = 0; j < (int)Acheck.size(); j++) {
						if (Acheck[j] == processing[i].k) {
							//cout << Acheck[j] << endl;
							//cout << processing[i].k << endl;
							ans += processing[i].k;
						}
					}
				}

			}
		}
		for (register int i = 1; i < M + 1; i++) {
			processing[i].t -= 1;
			if (processing[i].t == 0) {
				processing[i].k = -1;
				processing[i].t = -1;
			}
		}

		t++;
	}


	return ans;
}

int reception(deque<customer> customers) {

	deque<customer> custorepair;
	int t = 0; int k = 1;
	deque<int> waiting;
	customer processing[10];
	vector<int> Acheck;
	for (register int i = 0; i < N + 1; i++) {//�ʱ�ȭ
		processing[i].k = -1;
		processing[i].t = -1;
	}
	bool processempty = true;
	while (!customers.empty() || !waiting.empty() || !processempty) {
		//if waiting �� empty && process �� �� empty �� break

		while (!customers.empty() && t == customers.front().t) {//�ð��� ����� �� �־��ְ�
			customers.pop_front();
			waiting.push_back(k);
			k++;
		}

		for (register int i = 1; i < N + 1; i++) {
			if (waiting.empty()) break;
			else if (processing[i].k == -1) {//���� ����� �ְ� ����ִٸ�
				processing[i].k = waiting.front();//��� �־��ְ�
				waiting.pop_front();
				processing[i].t = recepstaff[i];//�ð� ����
												//A check
				if (i == A) {
					Acheck.push_back(processing[i].k);
				}
			}
		}
		//�� �ð��� -- �ϰ� ����
		processempty = true;
		for (register int i = 1; i < N + 1; i++) {
			processing[i].t -= 1;
			if (processing[i].t == 0) {
				//�ڷ� �Ѱ��ְ�
				customer one;
				one.k = processing[i].k;
				one.t = t;
				custorepair.push_back(one);
				processing[i].k = -1;
				processing[i].t = -1;
			}
			else if (processing[i].t>0)processempty = false;
		}
		//print
		//cout << "time " << t << endl;
		//for (register int i = 1; i < N + 1; i++) {
		//	cout << i << " c : " << processing[i].k << endl;
		//}
		t++;
	}

	int ans = repair(custorepair, Acheck);
	return ans;
}



int main(int argc, char** argv)
{
	//ifstream fin("input.txt");
	int test_case;
	int T;
	//fin >> T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		//�ʱ�ȭ
		cin >> N >> M >> K >> A >> B;

		//N�ް�
		for (register int i = 1; i < N + 1; i++) {
			cin >> recepstaff[i];
		}
		//M�ް�
		for (register int i = 1; i < M + 1; i++) {
			cin >> reapairstaff[i];
		}
		deque<customer> customers;
		for (register int i = 1; i < K + 1; i++) {
			customer one;
			one.k = i;
			cin >> one.t;
			customers.push_back(one);

		}

		int ans = reception(customers);
		if (ans == 0) ans = -1;

		cout << "#" << test_case << " " << ans << "\n";
	}
	//system("pause");
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}