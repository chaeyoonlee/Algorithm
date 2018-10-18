#include <fstream>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct node { int y; int x; int cost;
node(int _y, int _x, int _cost) :y(_y), x(_x), cost(_cost) {};
};
bool operator<(node a, node b) {//우선순위 큐를 최솟값을 맨 위에 오게
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
		for (int i = 0; i < N; i++)//간선간의 비용 값 입력
			for (int j = 0; j < N; j++)
			{
				visited[i][j] = false;
				fin >> buf;
				map[i][j]=buf-48;
			}
		//A*
		q.push(node(0, 0, map[0][0]));//시작점
		visited[0][0] = true;
		int ans;
		while (!q.empty()) {
			node here = q.top();
			q.pop();
			if (here.y == N - 1 && here.x == N - 1) { ans = here.cost; break; }//도착지점 도착
			//cout << here.y << " " << here.x << endl;
			for (register int i = 0; i < 4; i++) {//갈 수 있는 방향 탐색
				if(!visited[here.y + dir[i][0]][here.x + dir[i][1]]&&isrange(here.y + dir[i][0], here.x + dir[i][1])){
					//최소 우선순위 큐를 사용하니 이 값은 항상 here지점까지의 최단 경로가 됨. 그래서 따로 비교 없어도 이 값이 최단 경로 임을 앎
							q.push(node(here.y + dir[i][0], here.x + dir[i][1], here.cost + map[here.y + dir[i][0]][here.x + dir[i][1]]));//현재 위치와 시작점부터 현재값 까지의 값(최솟값)으로 넘겨줌
							visited[here.y + dir[i][0]][here.x + dir[i][1]] = true;//다시 방문하여 무한 루프 돌거나 최단 경로 계산을 망치는 일이 없도록

					
				}
			}
			
		}		
		cout << "#" << tc << " " <<ans << "\n";
		//큐비우기
		while (!q.empty()) q.pop();
	}
	system("pause");
	return 0;
}
