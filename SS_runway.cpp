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
		//가로줄 하나 받아서
		me = 0;//처음꺼 set
		sameme = 1;
		ans = 1;
		while (me <(N-1)) {//0~N-1
			if (ans == 0) break; 
			front = me + 1;
			//cout << "me : " << me<<" valsu : "<<map[i][me] << " front : " << front<<" value : "<<map[i][front] <<"\n";
			if (abs(map[i][front] - map[i][me]) > 1) { //벽이 길이 2이상이면
				ans = 0; break;
			}
			if (map[i][front] > map[i][me]) {//앞이 높음 -> 계단놓을 수 있는 지
				if (sameme < X) { ans = 0; break; }
				else {//front를 me로 바꿔주고 새로운 시작
					me = front;
					sameme = 1;
				}
			}
			else if (map[i][front] < map[i][me]) {//앞이 낮음
				me = front;//앞으로 세면서 계단 놓을 수 있는지
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
	
	//세로 줄
	for(register int j = 0; j < N; j++) {
		me = 0;//처음꺼 set
		sameme = 1;
		ans = 1;
		while (me <(N - 1)) {
			if (ans == 0) break;
			front = me + 1;
			//cout << "me : " << me<<" valsu : "<<map[me][j] << " front : " << front<<" value : "<< map[front][j] <<"\n";
			if (abs(map[front][j] - map[me][j]) > 1) { //벽이 길이 2이상이면
				ans = 0; break;
			}
			if (map[front][j] > map[me][j]) {//앞이 높음 -> 계단놓을 수 있는 지
				if (sameme < X) { ans = 0; break; }
				else {//front를 me로 바꿔주고 새로운 시작
					me = front;
					sameme = 1;
				}
			}
			else if (map[front][j] < map[me][j]) {
				me = front;//앞으로 세면서 계단 놓을 수 있는지
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