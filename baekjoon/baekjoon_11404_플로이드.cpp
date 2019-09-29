#include<iostream>
#include<algorithm>
using namespace std;

int n;
long long m;
int map[101][101];

int main() {
	cin >> n; // (1 <= n <= 100)
	cin >> m; // (1 <= m <= 100,000)
	for (int i = 0; i < m; i++) {
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		if (!map[t1][t2]) map[t1][t2] = t3;
		else map[t1][t2] = min(map[t1][t2], t3);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				else if (map[i][k] && map[k][j]) {
					if (!map[i][j]) map[i][j] = map[i][k] + map[k][j];
					else map[i][j] = min(map[i][k] + map[k][j], map[i][j]);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
}