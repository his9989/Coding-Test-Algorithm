#include <iostream>
#include <string>
#include <vector>
using namespace std;

int map[201][201];
int visited[201][201];
int cnt = 0, _n = 0;

void dfs(int y) {
	// y�� ����Ǿ� ������ ���� cnt�� �ο����� ���� ��尡 ������ Ȯ���ߴ�. ���⼭�� �����ϰ� y���� �����ؼ� ����� ��� �ֵ鿡 cnt �ο��ϸ� �ȴ�!!
	for (int x = 0; x<_n; x++) {
		if (map[y][x] == 1 && y != x && visited[y][x] == 0) {
			visited[y][x] = cnt; // y���� x�� ���� ���� ���
			visited[x][y] = cnt; // x���� y�� ���� ���� ���
			visited[x][x] = cnt; // ��� �湮 ���� ���
			dfs(x);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0, check = 0;
	_n = n;
	// computer�� ���� map ���·� �������ش�.
	for (int y = 0; y<n; y++) for (int x = 0; x<n; x++) map[y][x] = computers[y][x];

	// �� ��忡 ���� Ž���� ��
	for (int y = 0; y<n; y++) {
		check = 0;
		// �ش� ��忡�� �ϳ��� ����� ��尡 �ִ��� Ȯ��
		for (int x = 0; x<n; x++) {
			if (visited[y][x] == 0 && map[y][x] == 1 && y != x) {
				cnt++;
				check = 1;
				break;
			}
		}
		// ����Ǿ� ������, ���� �Ǻ����� ���� ������ �ִ� ����� ���θ� �ľ�. ���� ����� cnt�ο��ϸ鼭 dfs ������ ��.
		if (check) {
			visited[y][y] = cnt;
			dfs(y);
		}
	}
	// visited[n][n]���� �ش� ��忡 ��Ʈ��ũ �ο� ���θ� �ǹ��Ѵ�.
	// ��, visited[n][n] == 0�� ��� ���� ��� �� �ϳ��� ��Ʈ��ũ�� �ο� �޴� ��.
	// ��, �̷� �ֵ��� �� �� ��Ʈ��ũ ���� �ϳ��� �߰����ش�.
	for (int y = 0; y<n; y++)
		for (int x = 0; x<n; x++)
			if (y == x && visited[y][x] == 0) cnt++;
	answer = cnt;
	return answer;
}