#include<iostream>
#include<queue>
using namespace std;

int N, K;
int value = 0;
bool check = false;
queue<pair<int, int>> q;
bool visited[100001];

// 같은 높이에 해당하는 노드들은 queue에 넣어서
// 선입선출로 뽑아서 확인한다.
// 즉, 높이별로 선입선출로 넣기 때문에 높이 순으로 탐색 가능하며
// 전체 스탑시키는 bool 변수를 기저로 사용하여 정답을 찾았을 때 중단시킬 수 있다.
void bfs(int node, int height) {
	if (node == K) {
		value = height;
		check = true;
		return;
	}
	visited[node] = true;
	if (node - 1 >= 0 && !visited[node - 1])
		q.push(make_pair(node - 1, height + 1));
	if (node + 1 < 100001 && !visited[node + 1])
		q.push(make_pair(node + 1, height + 1));
	if (node * 2 < 100001 && node != 0 && !visited[2 * node])
		q.push(make_pair(node * 2, height + 1));
	while (!q.empty() && !check) {
		int node = q.front().first;
		int height = q.front().second;
		q.pop();
		bfs(node, height);
	}
}

int main() {
	cin >> N >> K;
	if (N == K)
		cout << 0 << endl;
	else{
		bfs(N, value);
		cout << value << endl;
	}
}