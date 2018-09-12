//4:42
#include<iostream>
#include <algorithm>
//#include <fstream>
#include <vector>
#include <deque>
using namespace std;
struct node { int x; int y; };
int N;
int map[11][11];//1.1부터 시작
int numP;
node Pinfo[11];//사람도 1번 부터
node Sinfo[2];//계단은 0번부터
int SK[2];

//node Pinfo[11];//사람도 1번 부터
//node Sinfo[2];//계단은 0번부터
int stairprocess(deque<int> people, int stairnum) {
	deque<int> waiting;//계단 앞 대기
					   //int processflag = 0;
	deque<int> processing;
	//for (register int i = 0; i < 3; i++)processing[i] = -1;
	if (!people.empty()) {//이 꼐단 사용하는 사람이 있을 때
		for (register int i = 0; i < ((int)people.size()); i++) {
			register int distance = abs(Sinfo[stairnum].x - Pinfo[people[i]].x) + abs(Sinfo[stairnum].y - Pinfo[people[i]].y);
			people[i] = distance;//최초 계단 도착 시간으로 사람 정보를 바꿈		
		}
		sort(people.begin(), people.end());
		int t = people.front();//젤 작은 거 부터

		while (!people.empty() || !waiting.empty() || !processing.empty()) {//모두가 빠져나갈 때 까지

			while (!people.empty() && (t == people.front())) {//같은 시간대 도착 다 넣음
				waiting.push_back(people.front());
				people.pop_front();
			}

			//계단 앞
			while ((int)processing.size()<3 && !waiting.empty()) {
				processing.push_back(SK[stairnum]);//시간 카운트 시작
				waiting.pop_front();//앞에 얘부터 넣어 줌}					
			}
			for (register int s = 0; s < (int)processing.size(); s++) {//시간 카운트
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
	//두개 그룹으로 나눠서
	/* nump에서 1명부터 nmp까지 뽑는 사람의 수 돌림
	뽑은 거랑 반대되는 애 만들어서 하나는 s1 나머지 s2에 분배
	계단까지의 시간 계산 후 짧은 순으로 sort해서 전달
	*/

	vector<int> v;
	deque<int> stairone;
	deque<int> stairtwo;
	int time;
	for (register int iter = 0; iter < numP; iter++) {	//0명과 다뽑는 거 하기
		stairone.push_back(iter + 1);//다 뽑기
	}
	time = max(stairprocess(stairone, 0), stairprocess(stairtwo, 1));
	ans = min(ans, time);
	time = max(stairprocess(stairone, 1), stairprocess(stairtwo, 0));
	ans = min(ans, time);
	stairone.clear();
	stairtwo.clear();
	for (int i = 1; i< numP; i++) {
		v.clear();
		for (register int j = 0; j< i; j++) {//뽑을 사람 수
			v.push_back(1);
		}
		for (register int j = 0; j <(numP - i); j++) {//빈공간 0으로 채우기
			v.push_back(0);
		}
		sort(v.begin(), v.end());
		do {//srair과 나눔			
			//for (register int iter = 0; iter < (int)v.size(); iter++) cout << v[iter];
			//cout << endl;
			stairone.clear();
			stairtwo.clear();
			for (register int iter = 0; iter < numP; iter++) {
				if (v[iter] == 1) {//그 사람 번호를 넣어줌
					stairone.push_back(iter + 1);
				}
				else stairtwo.push_back(iter + 1);
			}
			//한거 보내고 stair
			time = max(stairprocess(stairone, 0), stairprocess(stairtwo, 1));
			//cout << time << endl;
			ans = min(ans, time);

		} while (next_permutation(v.begin(), v.end()));

	}

	//둘다 시간 계산 후
	//시간 중에 긴걸로 내림


	//반환 ans 중 최솟값
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
				if (buf == 1) {//사람
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
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}