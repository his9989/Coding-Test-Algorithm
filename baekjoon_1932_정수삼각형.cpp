#include<iostream>
using namespace std;

int N;
int map[500][500];
int d[500][500];

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++) {
			map[y][x] = -1;
			d[y][x] = 0;
		}
	for (int y = 0; y < N; y++)
		for (int x = 0; x <= y; x++)
			cin >> map[y][x];
	d[0][0] = map[0][0];
	for (int y = 1; y < N; y++) {
		for (int x = 0; x <= y; x++) {
			if (x == 0)			d[y][0] = d[y - 1][0] + map[y][0];
			else if (x == y)	d[y][y] = d[y - 1][y - 1] + map[y][y];
			else				d[y][x] = max(d[y - 1][x - 1], d[y - 1][x]) + map[y][x];
		}
	}
	//cout
	int max = 0;
	for (int i = 0; i < N; i++)
		if (d[N-1][i] > max)	max = d[N-1][i];
	cout << max << endl;
}