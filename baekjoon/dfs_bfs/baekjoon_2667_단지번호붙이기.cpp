#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N = 0;
int map[25][25];
int visited[25][25];
int cnt = 1, cntcnt = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool check = false;
int answer[625];
//vector<int> answer;

void dfs(int y, int x) {
	if (map[y][x] == 0) {
		visited[y][x] = 0;
		return;
	}
	else if (visited[y][x]>0)
		return;
	else if (map[y][x] == 1) {
		visited[y][x] = cnt;
		cntcnt++;
		check = true;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				if (map[ny][nx] == 1) {
					dfs(ny, nx);
				}
			}
		}
	}
}

int main() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		string cintemp;
		cin >> cintemp;
		for (int x = 0; x < N; x++) {
			map[y][x] = int(cintemp[x]) - 48;
			visited[y][x] = -1;
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			check = false;
			cntcnt = 0;
			dfs(y, x);
			if (check == true) {
				answer[cnt] = cntcnt;
				//answer.push_back(cntcnt);
				cnt++;
			}
		}
	}
	cnt = cnt - 1;
	cout << cnt << endl;
	
	for (int i = 1; i < cnt; i++) {
		for (int j = i; j <= cnt; j++) {
			if (answer[i] > answer[j]) {
				int temp = answer[i];
				answer[i] = answer[j];
				answer[j] = temp;
			}
		}
	}
	//sort(answer.begin(), answer.end());
	for (int i = 1; i <= cnt; i++) {
		cout << answer[i] << endl;
	}
}