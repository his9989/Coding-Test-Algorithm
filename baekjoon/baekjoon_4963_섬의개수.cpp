/*
* github url : https://github.com/his9989
* 문제번호 : 4963번 - 섬의개수
* 카테고리 : 그래프 이론
* 해결방법1 : (h,w)행렬의 (0,0)부터 (h-1, w-1)까지 탐색. 1인 경우, [오른쪽, 좌하향, 하향, 우하향] 확인 후 카운팅
* 겪은 에러1 : 결과가 다르게 나온다. 아마 탐색을 현재점 기준 4방향만 탐색해서 그런듯. 재귀 방식으로 다시 시도하자

* 해결방법2 : (h+2, w+2)행렬로 패딩 삽입. 탐색한 땅을 0으로 변환하고, 이어진 모든 지역을 8방향으로 탐색하는 방식으로 수정
* 바로 컴파일 성공
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
		// w행 h열 2자 배열 생성		
		arr = new int*[h+2];
		for (int i = 0; i < h+2; i++) 
			arr[i] = new int[w+2];
		// 2차배열에 데이터 삽입
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
	// 8방향 탐색. 1이면 재귀적으로 탐색
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
