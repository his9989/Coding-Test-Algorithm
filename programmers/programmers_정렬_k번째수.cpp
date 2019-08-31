#include<iostream>
#include<algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> temp; // 3���� ���ҷ� �̷���� command ���͸� �����ϴ� �ڷᱸ��
	vector<int> answer; // ������ �����ϴ� �־��� �ڷᱸ��.
	vector<int> tempAnswer; // �ӽ� ����� �����ϴ� �ڷᱸ��

	// ��� commands�� Ȯ��
	while (!commands.empty()) {
		// 3���� ���ҷ� �̷���� command ���͸� temp�� ����
		temp = commands.back();
		commands.pop_back();

		// ���̰� �Ʒ��� ���� �����迭 ����.
		int *arr = new int[temp[1] - temp[0] + 1];
		// ������ �����迭�� array�� temp�� ���� ��ġ�� �����Ѵ�.
		int j = 0;
		for (int i = temp[0] - 1; i <= temp[1] - 1; i++) {
			arr[j] = array[i];
			j++;
		}
		// ������ arr�迭�� ����
		sort(arr, arr + temp[1] - temp[0] + 1);
		// ��� ���⼭ �ٷ� answer�� push�ص� �ȴ�.
		// �ٸ� �׳� �����Ľ�Ű�� �����Ƽ� �̷�����..����
		tempAnswer.push_back(arr[temp[2] - 1]);
	}
	while (!tempAnswer.empty()) {
		int tem = tempAnswer.back();
		tempAnswer.pop_back();
		answer.push_back(tem);
	}
	return answer;
}