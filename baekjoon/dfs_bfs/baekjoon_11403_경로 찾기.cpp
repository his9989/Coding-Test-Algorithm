#include<iostream>
using namespace std;
int N, map[100][100];

// 경로 찾기
int main() {
	cin >> N;
	for (int y = 0; y < N; y++) 
		for (int x = 0; x < N; x++) 
			cin >> map[y][x];

	for (int k = 0; k < N; k++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[y][k] == 1 && map[k][x] == 1) {
					map[y][x] = 1;
				}
			}
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++)
			cout << map[y][x] << " ";
		cout << endl;
	}
}