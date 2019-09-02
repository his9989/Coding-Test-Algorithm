#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int stageUser[501]; // n��° stage���� ������ �ο� ���. n+1���Ҵ� ��θ� Ŭ������ �ο�
vector<pair<double, int>>fin;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	while (!stages.empty()) {
		int stage = stages.back();
		stages.pop_back();
		for (int i = 1; i<stage + 1; i++) {
			// n��° stage���� ������ �ο� ���
			stageUser[i] += 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		int _pause = stageUser[i] - stageUser[i + 1];
		int _come = stageUser[i]; // 0 �� �� �ִ�.
		double _cant = 0.0;
		if (_come != 0) _cant = double(_pause) / _come;
		// i, _cant�� ���� �ִ� �����Ϳ��� _cant�� ���� ������ ��, ���� _cant�� ���� i������ �����Ͽ� �� ������ i�� ����ؾ��Ѵ�.
		// �ѹ��� sorting���� �����ϱ� ����, �������� ���������� ������ �������� �ٲ㼭 ������������ �����Ѵ�.
		fin.push_back(make_pair((1 - _cant), i));
	}
	sort(fin.begin(), fin.end());
	for (int i = 0; i<fin.size(); i++)
		answer.push_back(fin[i].second);
	return answer;
}

// N : ��ü �������� ����. 1~500
// stages : ���� ������ stages.size()��ŭ ���� ��, �� ������ �����ִ� �������� ��. 1~200,000
// stages[i] == N+1�� ��� : ��� ���������� Ŭ������ �����
// ���������� ������ ������ ���� ��� �������� 0
// answer�� �������� ���� ���� ���� �������� ���� ������������ ���

/*
�ʿ��� �ڷ��� : �� ���������� ����� �湮�ߴ��� ����ϴ� ����
*/

/*
n��° ���������� ������ : n��° ���������� ���������� Ŭ�������� ���� �÷��̾� ��/ n��° ���������� ������ �÷��̾� ��
*/