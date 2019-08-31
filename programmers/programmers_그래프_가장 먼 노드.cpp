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

	// edge를 행렬화
	for (int i = 0; i<edge.size(); i++) {
		int _y = edge[i][0];
		int _x = edge[i][1];
		map[_y][_x] = 1; map[_x][_y] = 1;
	}

	//1부터 시작이니까 1부터 쭉 돌면서 bfs로 탐색하면서 최소 거리를 visited에 기록
	visited[1] = 1;
	bfs(1);

	// max 비교, 개수 확인
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
크기가 n+1인 2차원 배열로 edge 데이터를 이동시킨다.
visited[y][x] : y에서 x로 이동한 여부
visited[y][y] : y 노드를 방문한 여부
visited[y][y] : 1에서 y까지 오는데 최소 비용
visited[y][y] 탐색하면서 최대와 같으면 cnt++, 최대보다 크면 cnt초기화 & max 재설정 -> answer = cnt + 1 끝!
*/