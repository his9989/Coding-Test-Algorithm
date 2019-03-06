/*
* github url : https://github.com/his9989
* ������ȣ : 4963�� - ���ǰ���
* ī�װ� : �׷��� �̷�
* ���� ����1 : ����� �ٸ��� ���´�. �Ƹ� Ž���� ������ ���� 4���⸸ Ž���ؼ� �׷���. ����ó�� �����ؼ� �ٽ� �õ�����
* ���� �ذ��� : Ž���� ���� 0���� ��ȯ�ϰ�, �̾��� ��� ������ 8�������� Ž���ϴ� ������� ����
*/

#include<iostream>
#include<queue>
using namespace std;

int **arr;

void check(int, int);

int main() {
	int w, h;
	int count = 0;
	cin >> w >> h;

	while (w != 0 && h != 0) {
		count = 0;
		// w�� h�� 2�� �迭 ����		
		arr = new int*[h+2];
		for (int i = 0; i < h+2; i++) 
			arr[i] = new int[w+2];
		// 2���迭�� ������ ����
		for (int i = 0; i < h+2; i++) {
			for (int j = 0; j < w+2; j++) {
				arr[i][j] = 0;
				if (i > 0 && i < h + 1 && j>0 && j < w + 1)
					cin >> arr[i][j];
			}
		}
		for (int i = 1; i < h+1; i++) {
			for (int j = 1; j < w+1; j++) {
				if (arr[i][j] == 1) {
					count += 1;
					check(i, j);
				}
			}
		}
		cout << "result : " << count << endl;
		cin >> w >> h;
	}
}

void check(int i, int j) {
	// 8���� Ž��. 1�̸� ��������� Ž��
	if (arr[i][j] == 1) {
		arr[i][j] = 0;
		check(i - 1, j - 1);
		check(i - 1, j);
		check(i - 1, j + 1);
		check(i, j - 1);
		check(i, j + 1);
		check(i + 1, j - 1);
		check(i + 1, j);
		check(i + 1, j + 1);
	}
}