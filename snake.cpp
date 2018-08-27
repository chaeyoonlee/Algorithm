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

int N;//���� ũ��
int K;//��� ����
int L;//�� ���� ��ȯ Ƚ��
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
/* ����
�ʸ� ī��Ʈ, ���⺯ȯ Ƚ�� �� ���� ���̳� �� �� ���� �� ����
�ʿ� ������ - �ʿ� ���� ��ȯ�� ���ٸ� ���� ���� �״��
���� ��ȯ�� �ִٸ� ����
if ���������ų� �ڱ� ���� ���Ե� �� ������ ���� ����

else �����̰� ����� �ִٸ� �� ���̸� �ø���
����� ���ٸ� �״�� ���� �����̱�



*/
int play(int sec) {
	int drc[4][2] = { { 0,-1 },{ -1,0 },{ 0,1 },{ 1,0 } };
	int currentdirection = 2;//ó������ ���������� ������
	bool keep = true;
	while (keep) {
		if (!direction.empty() && sec == direction.front().x) {
			//���� �ʰ� �������� ����
			currentdirection += direction.front().y;
			if (currentdirection == 4) currentdirection = 0;
			else if (currentdirection == -1) currentdirection = 3;
			direction.pop();
			//���� �ٲ��� pop
		}

		//������ ������ �� �帧
		sec++;
		n next = snake.back();// ���� �� ��ġ
		next.y += drc[currentdirection][0];
		next.x += drc[currentdirection][1];

		int i = 0;
		int size = snake.size();
		for (i; i<size; i++) {//�ڱ� ��
			if ((snake[i].x == next.x) && (snake[i].y == next.y)) keep = false;
		}//���� ������ ��
		if (next.x<0 || next.x > N - 1 || next.y<0 || next.y>N - 1) keep = false;
		else if (board[next.y][next.x] == 2) {//��� ������ ��
			board[next.y][next.x] = 0;//��� �԰�
			snake.push_back(next);//���ڸ��� ���� �־ ���� �ø�
								  //cout <<"y : "<< next.y << "x : " << next.x << endl;
		}
		else {
			snake.push_back(next);//�Ӹ� �ű��
								  //cout << "y : " << next.y << "x : " << next.x << endl;
								  //cout << "delete y : " << snake.front().y << "x : " << snake.front().x << endl;
			snake.pop_front();//���� �ϳ� �����

		}
		//�ϰ͵� ������ ���� ������ ������ ��


	}
	return sec;
}
int main() {
	//ifstream fin("input.txt");
	cin >> N;
	cin >> K;
	//���� �ʱ�ȭ 1�� ��, 2�� ���
	int i, j;
	/*for (i = 0; i < N; i++) {
	board[0][i] = 1; // �� �� ������
	board[i][0] = 1;//�� ���� ������
	board[N - 1][i] = 1;//�� �� ������
	board[i][N - 1] = 1;//�� ������ ������
	}*/
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			board[i][j] = 0;
		}
	}
	//��� �Է�
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
	cin >> L;// ���� ��ȯ ����
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