#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int  arr[30];
	int answer = 0;
	// �⺻������ ��� �ϳ��� ���� �ִٰ� ����
	for (int i = 0; i<n; i++) arr[i] = 1;
	// 2�� ������ �ֵ��� �ϳ��� �߰����ֱ�
	for (int i = 0; i<reserve.size(); i++) arr[reserve[i] - 1] += 1;
	// ����� �ֵ��� �ϳ��� ���ֱ�
	for (int i = 0; i<lost.size(); i++) arr[lost[i] - 1] -= 1;
	// ��ü Ž���ؼ�
	for (int i = 0; i<n; i++) {
		// 0 �� ���, ������ �༮�� ���� ���´ٰ� ����
		if (arr[i] == 0) {
			if (i - 1 >= 0 && arr[i - 1] == 2) {
				arr[i - 1] -= 1;
				arr[i] += 1;
			}
			// ������ 1���� �׶��� �������� ���´ٴ� ����
			else if (i + 1<n && arr[i + 1] == 2) {
				arr[i + 1] -= 1;
				arr[i] += 1;
			}
		}
	}
	for (int i = 0; i<n; i++) if (arr[i] >= 1) answer++;
	return answer;
}