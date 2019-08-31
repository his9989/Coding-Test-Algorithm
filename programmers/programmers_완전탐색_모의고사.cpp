#include <iostream>
#include <string>
#include <vector>

using namespace std;



vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int temp, cnt;
	int ans[3] = { 0, 0, 0 }; // 3���� �����ڰ� ���� ������ ����
	int fir[5] = { 5, 1, 2, 3, 4 }; // 1�� ������ ���
	int sec[8] = { 5, 2, 1, 2, 3, 2, 4, 2 }; // 2�� ������ ���
	int thi[10] = { 5, 3, 3, 1, 1, 2, 2, 4, 4, 5 }; // 3�� ������ ���

	// ��� ���信 ���� Ž��. �� vector�ϱ� ������ ��ȣ���� Ž��
	// �ڿ������� pop ������ answers.size()�� ������ ��ȣ�� �ȴ�.
	while (!answers.empty()) {
		cnt = answers.size();
		temp = answers.back();
		answers.pop_back();
		// �������� ������ �´� ��� ans�� ���������ش�.
		if (temp == fir[cnt % 5]) ans[0]++;
		if (temp == sec[cnt % 8]) ans[1]++;
		if (temp == thi[cnt % 10]) ans[2]++;
	}
	// �⺻������ ans[0]�� �ְ��� ����
	int max = ans[0];
	answer.push_back(1);
	// ans[1]�� ans[0]���� ū ���, ans[0]�� �������� ans[1] �ֱ�
	if (ans[1] > max) {
		answer.pop_back();
		answer.push_back(2);
		max = ans[1];
	}
	// ans[1] == ans[0]�� ���, ans[0], ans[1] ��� �����
	else if (ans[1] == max) {
		answer.push_back(2);
	}
	// ans[2]�� ans[0] & ans[1] �� ������ ũ�� ���� ���� ������� �� ��� ���� ū ���
	if (ans[2] > max) {
		// answer�� �ִ°� �� �������� ans[2]�� �ֱ�
		while (!answer.empty()) answer.pop_back();
		answer.push_back(3);
	}
	// ans[2]�� ans[0] & ans[1] �� ������ ũ�� ���� ���� ������� max�� ���� ��� ans[3] �־��ֱ�
	else if (ans[2] == max)
		answer.push_back(3);
	return answer;
}