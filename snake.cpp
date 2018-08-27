/* codbs0417
snake
https://www.acmicpc.net/problem/3190

*/
//10:50
#include <iostream>
//#include <fstream>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;

int N;//보드 크기
int K;//사과 개수
int L;//뱀 방향 변환 횟수
int board[101][101];

struct n {
	int x;
	int y;
};
n makenode(int a, int b) {
	n newn;
	newn.x = a;
	newn.y = b;
	return newn;
}

queue<n> direction;
deque<n> snake;
/* 게임
초를 카운트, 방향변환 횟수 다 쓰고 벽이나 내 몸 만날 때 까지
초에 움직임 - 초에 방향 변환이 없다면 가던 방향 그대로
방향 변환이 있다면 꺾기
if 벽을만나거나 자기 몸에 포함된 데 만나면 게임 오버

else 움직이고 사과가 있다면 몸 길이를 늘리기
사과가 없다면 그대로 몸만 움직이기



*/
int play(int sec) {
	int drc[4][2] = { { 0,-1 },{ -1,0 },{ 0,1 },{ 1,0 } };
	int currentdirection = 2;//처음에는 오른쪽으로 움직임
	bool keep = true;
	while (keep) {
		if (!direction.empty() && sec == direction.front().x) {
			//지금 초가 움직임이 있음
			currentdirection += direction.front().y;
			if (currentdirection == 4) currentdirection = 0;
			else if (currentdirection == -1) currentdirection = 3;
			direction.pop();
			//방향 바꿔줌 pop
		}

		//방향대로 움직임 초 흐름
		sec++;
		n next = snake.back();// 다음 갈 위치
		next.y += drc[currentdirection][0];
		next.x += drc[currentdirection][1];

		int i = 0;
		int size = snake.size();
		for (i; i<size; i++) {//자기 몸
			if ((snake[i].x == next.x) && (snake[i].y == next.y)) keep = false;
		}//벽을 만났을 때
		if (next.x<0 || next.x > N - 1 || next.y<0 || next.y>N - 1) keep = false;
		else if (board[next.y][next.x] == 2) {//사과 만났을 때
			board[next.y][next.x] = 0;//사과 먹고
			snake.push_back(next);//그자리를 집어 넣어서 몸을 늘림
								  //cout <<"y : "<< next.y << "x : " << next.x << endl;
		}
		else {
			snake.push_back(next);//머리 옮기고
								  //cout << "y : " << next.y << "x : " << next.x << endl;
								  //cout << "delete y : " << snake.front().y << "x : " << snake.front().x << endl;
			snake.pop_front();//꼬리 하나 지우고

		}
		//암것도 없으면 원래 방향대로 움직여 줌


	}
	return sec;
}
int main() {
	//ifstream fin("input.txt");
	cin >> N;
	cin >> K;
	//보드 초기화 1은 벽, 2는 사과
	int i, j;
	/*for (i = 0; i < N; i++) {
	board[0][i] = 1; // 맨 위 가로줄
	board[i][0] = 1;//맨 왼쪽 세로줄
	board[N - 1][i] = 1;//맨 밑 가로줄
	board[i][N - 1] = 1;//맨 오른쪽 세로줄
	}*/
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			board[i][j] = 0;
		}
	}
	//사과 입력
	int y, x;
	for (i = 0; i < K; i++) {
		cin >> y >> x;
		board[y - 1][x - 1] = 2;
	}

	/*
	for (i = 0; i < N ; i++) {
	for (j = 0; j < N; j++) {
	cout << board[i][j];
	}
	cout << endl;
	}*/
	cin >> L;// 방향 전환 정보
	char C;
	for (i = 0; i < L; i++) {
		cin >> x >> C;
		if (C == 'L') y = -1;
		else y = 1;
		direction.push(makenode(x, y));
	}

	snake.push_back(makenode(0, 0));

	int ans = play(0);
	cout << ans;

	//system("pause");
	return 0;
}