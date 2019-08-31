#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int  arr[30];
	int answer = 0;
	// 기본적으로 모두 하나씩 갖고 있다고 가정
	for (int i = 0; i<n; i++) arr[i] = 1;
	// 2개 가져온 애들은 하나씩 추가해주기
	for (int i = 0; i<reserve.size(); i++) arr[reserve[i] - 1] += 1;
	// 놓고온 애들은 하나씩 빼주기
	for (int i = 0; i<lost.size(); i++) arr[lost[i] - 1] -= 1;
	// 전체 탐색해서
	for (int i = 0; i<n; i++) {
		// 0 인 경우, 왼쪽의 녀석을 먼저 뺏는다고 가정
		if (arr[i] == 0) {
			if (i - 1 >= 0 && arr[i - 1] == 2) {
				arr[i - 1] -= 1;
				arr[i] += 1;
			}
			// 왼쪽이 1개면 그때만 오른쪽을 뺏는다는 가정
			else if (i + 1<n && arr[i + 1] == 2) {
				arr[i + 1] -= 1;
				arr[i] += 1;
			}
		}
	}
	for (int i = 0; i<n; i++) if (arr[i] >= 1) answer++;
	return answer;
}