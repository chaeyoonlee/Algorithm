#include <fstream>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct node { int y; int x; int cost;
node(int _y, int _x, int _cost) :y(_y), x(_x), cost(_cost) {};
};
bool operator<(node a, node b) {//�켱���� ť�� �ּڰ��� �� ���� ����
	if (a.cost > b.cost) return true;
	return false;
}
int N;
bool isrange(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N) return false;
	else return true;
}
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	ifstream fin("input.txt");
	int T;
	int map[101][101];
	bool visited[101][101];
	int dir[4][2] = { {-1,0} ,{1,0} ,{0,-1} ,{0,1} };
	priority_queue<node> q;
	fin >> T;
	char buf;
	for (int tc = 1; tc <= T; tc++) {
		fin >> N;
		for (int i = 0; i < N; i++)//�������� ��� �� �Է�
			for (int j = 0; j < N; j++)
			{
				visited[i][j] = false;
				fin >> buf;
				map[i][j]=buf-48;
			}
		//�� �ͽ�Ʈ��
		q.push(node(0, 0, map[0][0]));//������
		visited[0][0] = true;
		int ans;
		while (!q.empty()) {
			node here = q.top();
			q.pop();
			if (here.y == N - 1 && here.x == N - 1) { ans = here.cost; break; }//�������� ����
			//cout << here.y << " " << here.x << endl;
			for (register int i = 0; i < 4; i++) {//�� �� �ִ� ���� Ž��
				if(!visited[here.y + dir[i][0]][here.x + dir[i][1]]&&isrange(here.y + dir[i][0], here.x + dir[i][1])){
					//�ּ� �켱���� ť�� ����ϴ� �� ���� �׻� here���������� �ִ� ��ΰ� ��. �׷��� ���� �� ��� �� ���� �ִ� ��� ���� ��
							q.push(node(here.y + dir[i][0], here.x + dir[i][1], here.cost + map[here.y + dir[i][0]][here.x + dir[i][1]]));//���� ��ġ�� ���������� ���簪 ������ ��(�ּڰ�)���� �Ѱ���
							visited[here.y + dir[i][0]][here.x + dir[i][1]] = true;//�ٽ� �湮�Ͽ� ���� ���� ���ų� �ִ� ��� ����� ��ġ�� ���� ������

					
				}
			}
			
		}		
		cout << "#" << tc << " " <<ans << "\n";
		//ť����
		while (!q.empty()) q.pop();
	}
	system("pause");
	return 0;
}