#include <iostream>
#include <string>
#include <vector>
using namespace std;

int map[201][201];
int visited[201][201];
int cnt = 0, _n = 0;

void dfs(int y) {
	// y와 연결되어 있으며 아직 cnt가 부여되지 않은 노드가 있음을 확인했다. 여기서는 무식하게 y부터 시작해서 연결된 모든 애들에 cnt 부여하면 된다!!
	for (int x = 0; x<_n; x++) {
		if (map[y][x] == 1 && y != x && visited[y][x] == 0) {
			visited[y][x] = cnt; // y에서 x로 연결 여부 기록
			visited[x][y] = cnt; // x에서 y로 연결 여부 기록
			visited[x][x] = cnt; // 노드 방문 여부 기록
			dfs(x);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0, check = 0;
	_n = n;
	// computer의 값을 map 형태로 변형해준다.
	for (int y = 0; y<n; y++) for (int x = 0; x<n; x++) map[y][x] = computers[y][x];

	// 각 노드에 대해 탐색할 것
	for (int y = 0; y<n; y++) {
		check = 0;
		// 해당 노드에서 하나라도 연결된 노드가 있는지 확인
		for (int x = 0; x<n; x++) {
			if (visited[y][x] == 0 && map[y][x] == 1 && y != x) {
				cnt++;
				check = 1;
				break;
			}
		}
		// 연결되어 있으며, 아직 판별되지 않은 연결이 있는 노드의 여부를 파악. 이제 얘부터 cnt부여하면서 dfs 돌리면 됨.
		if (check) {
			visited[y][y] = cnt;
			dfs(y);
		}
	}
	// visited[n][n]에는 해당 노드에 네트워크 부여 여부를 의미한다.
	// 즉, visited[n][n] == 0인 경우 단일 노드 당 하나의 네트워크를 부여 받는 것.
	// 즉, 이런 애들은 개 당 네트워크 개수 하나씩 추가해준다.
	for (int y = 0; y<n; y++)
		for (int x = 0; x<n; x++)
			if (y == x && visited[y][x] == 0) cnt++;
	answer = cnt;
	return answer;
}