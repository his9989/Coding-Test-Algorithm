#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	// 1�� ���� �迭
	int *count = NULL;
	count = new int[n];
	// 1�� ���� �迭 �ʱ�ȭ
	for (int i = 0; i < n; i++) count[i] = 0;

	// 2�� ���� �迭
	int ** arr = new int*[n];
	for (int i = 0; i<n; i++) {
		arr[i] = new int[4];
	}
	// 2�� ���� �迭 �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = 0;
		}
	}
}
