#include<iostream>
using namespace std;

int N;
int map[1001][3];
int d[1001][3];

int min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int min3(int a, int b, int c) {
	if (a > b) {
		if (b > c)
			return c;
		else
			return b;
	}
	else {
		if (a > c)
			return c;
		else
			return a;
	}
}

int main() {
	cin >> N;
	d[0][0] = 0, d[0][1] = 0, d[0][2] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
			d[i][j] = 0;
		}
	}
	for (int i = 1; i <= N; i++) {
		d[i][0] = map[i][0] + min(d[i - 1][1], d[i - 1][2]);
		d[i][1] = map[i][1] + min(d[i - 1][0], d[i - 1][2]);
		d[i][2] = map[i][2] + min(d[i - 1][0], d[i - 1][1]);
	}
	int answer = min3(d[N][0], d[N][1], d[N][2]);
	cout << answer << endl;
}