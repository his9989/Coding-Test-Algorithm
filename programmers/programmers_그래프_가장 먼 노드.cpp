#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int map[20001][20001] = { 0, };
int visited[20001] = { 0, };
int staticN = 0;
queue<int> nod;

void bfs(int num) {
	for (int x = 1; x <= staticN; x++) {
		if (map[num][x] == 1 && visited[x] == 0) {
			visited[x] = visited[num] + 1;
			nod.push(x);
		}
	}
	while (!nod.empty()) {
		int _num = nod.front();
		nod.pop();
		bfs(_num);
	}

}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	staticN = n;

	// edge�� ���ȭ
	for (int i = 0; i<edge.size(); i++) {
		int _y = edge[i][0];
		int _x = edge[i][1];
		map[_y][_x] = 1; map[_x][_y] = 1;
	}

	//1���� �����̴ϱ� 1���� �� ���鼭 bfs�� Ž���ϸ鼭 �ּ� �Ÿ��� visited�� ���
	visited[1] = 1;
	bfs(1);

	// max ��, ���� Ȯ��
	int _cnt = 1;
	int _max = 0;
	for (int i = 1; i <= n; i++) {
		if (_max < visited[i]) {
			_max = visited[i];
			_cnt = 1;
		}
		else if (_max == visited[i]) {
			_cnt++;
		}
	}
	answer = _cnt;
	return answer;
}


/*
ũ�Ⱑ n+1�� 2���� �迭�� edge �����͸� �̵���Ų��.
visited[y][x] : y���� x�� �̵��� ����
visited[y][y] : y ��带 �湮�� ����
visited[y][y] : 1���� y���� ���µ� �ּ� ���
visited[y][y] Ž���ϸ鼭 �ִ�� ������ cnt++, �ִ뺸�� ũ�� cnt�ʱ�ȭ & max �缳�� -> answer = cnt + 1 ��!
*/