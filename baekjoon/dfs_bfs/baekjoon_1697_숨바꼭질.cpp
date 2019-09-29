#include<iostream>
#include<queue>
using namespace std;

int N, K;
int value = 0;
bool check = false;
queue<pair<int, int>> q;
bool visited[100001];

// ���� ���̿� �ش��ϴ� ������ queue�� �־
// ���Լ���� �̾Ƽ� Ȯ���Ѵ�.
// ��, ���̺��� ���Լ���� �ֱ� ������ ���� ������ Ž�� �����ϸ�
// ��ü ��ž��Ű�� bool ������ ������ ����Ͽ� ������ ã���� �� �ߴܽ�ų �� �ִ�.
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