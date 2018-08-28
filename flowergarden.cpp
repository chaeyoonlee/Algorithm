//9:53 ~10:35
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int N;
int map[11][11];

void copymap(int arr[][11], bool c) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++){
			if (c) arr[i][j] = map[i][j]; //map에 있는 거 복사
			else map[i][j] = arr[i][j];	//map 되돌려주기
		}
	}
}

int flower(int count, int add[3]) {
	int i, j;
	if (count == 3) {
		int all=0;
		int h;
		for (h = 0; h < 3; h++) all += add[h];
		return all;
		
	}
	
	int ret = 9999;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {//범위 안 + 다른 꽃과 겹치지 않아야돼
			if ((i > 0 && j > 0 && i + 1 < N && j + 1 < N) ) {
				if (map[i][j] >= 0 && map[i - 1][j] >= 0 && map[i][j - 1] >= 0 && map[i + 1][j] >= 0 && map[i][j + 1] >= 0) {
					//cout << "y : " << i << "x : " << j;
					int tmparr[11][11];
					copymap(tmparr,true);
					add[count] = (map[i][j] + map[i - 1][j] + map[i][j - 1] + map[i + 1][j] + map[i][j + 1]);
					map[i][j] = map[i - 1][j] = map[i][j - 1] = map[i + 1][j] = map[i][j + 1] = -1;
					/*for (int k = 0; k < N; k++) {
						for (int g = 0; g < N; g++) {
							cout << map[k][g];
						}
						cout << endl;
					}cout << endl;*/
					ret  = min(ret,flower(count + 1, add));
					copymap(tmparr, false);
					
				}
			
			}
			//꽃이 들어갈 수 있다면 
			//꽃 넣기 전 상태 저장
			//심어보고 재귀
			//꽃 넣은 거 빼기
		}
	}
	return ret;
}

int main() {
	//ifstream fin("input.txt");
	cin >> N;
	int i,j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int add[3];
	cout << flower(0,add);
	//system("pause");
	return 0;
}