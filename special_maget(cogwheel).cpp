//11:20
#include <iostream>
#include <deque>
//#include <fstream>
using namespace std;

struct sn {
	deque<int> num;//8개 날을 가진 자석 번호
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
		//deque 비우기
		if (!ks.empty()) while (!ks.empty()) ks.pop_back();
		for (register int i = 0; i < 4; i++) {
			//날 비우고
			if (!sladeinfo[i].num.empty()) {
				while (!sladeinfo[i].num.empty()) sladeinfo[i].num.pop_back();
			}
			//날 정보 받기
			for (register int j = 0; j < 8; j++) {
				cin >> buf;
				sladeinfo[i].num.push_back(buf);
			}
			//printsades(i, sladeinfo[i]);

		}
		for (register int j = 0; j < k; j++) {
			//k정보 받기
			cin >> clockid >> clockwise;
			--clockid;//나느 시계 0번 부터 시작
					  //bfs 로 돌려주기
					  //처음에 받은 애 넣고
			ks.push_back(makenewkinfo(clockid, clockwise));
			register int originid = clockid;
			register int originwise = clockwise;
			//얘 왼쪽 파생 검사
			while (clockid>0) {//왼쪽 검사하니 얘가 1일때까지
				if (sladeinfo[clockid].num[6] != sladeinfo[clockid - 1].num[2]) {
					//나의 6번과 왼쪽의 2번이 다르면
					clockid -= 1;//id하나 왼쪽으로 옮겨주고
					clockwise *= (-1);//방향 반대로 돌려주고
					ks.push_back(makenewkinfo(clockid, clockwise));
				}
				else break;//같으면 파생 stop
			}
			//오른쪽 파생 검사
			clockid = originid;//원래 수 돌려주고
			clockwise = originwise;//원래 방향
			while (clockid < 3) {//오른쪽 검사하니 얘가 2일때 까지
				if (sladeinfo[clockid].num[2] != sladeinfo[clockid + 1].num[6]) {
					//나의 2번과 내 오른쪽의 6번이 다르면
					clockid += 1;//id하나 오른쪽으로 옮겨주고
					clockwise *= (-1);//방향 반대로 돌려주고
					ks.push_back(makenewkinfo(clockid, clockwise));
				}
				else break;//같으면 파생 stop
			}
			//ks에 있는 애 돌리기 -> 큐 empty로 만들기
			kinfo thisone;
			while (!ks.empty()) {
				thisone = ks.front();
				ks.pop_front();
				//cout << "before slade " << thisone.clockid << "\n";
				//printsades(thisone.clockid, sladeinfo[thisone.clockid]);
				//cout << "after\n";

				if (thisone.clockwise == 1) {//시계 방향
											 //뒤에꺼를 빼서 맨 앞에
					register int back = sladeinfo[thisone.clockid].num.back();
					sladeinfo[thisone.clockid].num.pop_back();
					sladeinfo[thisone.clockid].num.push_front(back);
				}
				else {//반시계
					  //맨 앞에꺼를 맨 뒤로
					register int front = sladeinfo[thisone.clockid].num.front();
					sladeinfo[thisone.clockid].num.pop_front();
					sladeinfo[thisone.clockid].num.push_back(front);
				}
				//cout << "after\n";
				//printsades(thisone.clockid, sladeinfo[thisone.clockid]);

			}
		}
		//0번자리 검사해 점수 출력
		int ans = 0;
		for (register int i = 0; i < 4; i++) {
			if (sladeinfo[i].num[0] == 1) ans += score[i];
		}
		cout << "#" << tc + 1 << " " << ans << endl;
	}
	//system("pause");
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}