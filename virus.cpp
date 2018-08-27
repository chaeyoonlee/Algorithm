/*codbs0417
virus
https://www.acmicpc.net/problem/2606
*/
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int NumCom;
//int **map;
int map[101][101];
queue <int> que;
//bool *visited;
bool visited[101];

void bfs() { //LIFO
	int i;

	int here;

	while (!que.empty())
	{
		here = que.front(); //시작번호(큐0의 
		visited[here] = true;
		que.pop();
		for (i = 1; i <= NumCom; i++) {
			if (map[here][i] == 1 && visited[i] == false) {//형제 탐색 - 방문한 적 없고 연결 되어 있고
				que.push(i);//que에 형제 삽입
			}
		}
	}
	//시작은 virus 걸린 visited함	
	//형제를 큐에 넣기
	// 큐에 없어질 때 까지 bfs 돌림

}

int main() {

	ofstream fout("output.txt");
	ifstream fin("input.txt");

	int i, n;
	int a, b;
	cin >> NumCom >> n;
	//fin >> NumCom >> n;

	//1 ~ NumCom
	/*map = new int *[NumCom +1];
	visited = new bool[NumCom + 1];

	for (i = 1; i <= NumCom; i++) {
	visited[i] = false;
	map[i] = new int[NumCom + 1];
	}
	*/
	for (i = 0; i < n; i++) {
		//fin >> a >> b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	que.push(1);
	bfs();
	int count = 0;

	for (i = 1; i <= NumCom; i++) {
		if (visited[i] == true) count++;
	}
	//fout<<count-1;
	cout << count - 1; // 1번 컴퓨터 제외라서
					   //system("pause");
	return 0;
}