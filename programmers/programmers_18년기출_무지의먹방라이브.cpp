#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<pair<long long, long long>> q;

// k�� 2 x 10^13 ������ �ڿ���
// food_times�� ���Ҵ� 100,000,000������ �ڿ���
// food_times ���� ������ 200,000������ �ڿ���
int solution(vector<int> food_times, long long k) {
	int answer = 0;

	for (long long i = 0; i<food_times.size(); i++) {
		q.push(pair<long long, long long>(i + 1, food_times[i]));
	}

	while (!q.empty() && k != 0) {
		long long index = q.front().first;
		long long time = q.front().second;
		q.pop();
		k -= 1;
		if (time - 1 != 0) q.push(pair<long long, long long>(index, time - 1));
	}
	if (q.empty()) answer = -1;
	else answer = q.front().first;
	return answer;
}

/*
N���� ����
1������ ���� �Ա� ����
ȸ������ ���Ĺ�ȣ ��������
������ ��ȣ ���� ������ 1�� ������ ���ƿ´�. (Queue)

������ 1�ʿ� �Ѱ����� ���ĸ� �Դ´�.
��, 1�� ���� 1�� �԰�, 2�� ���� 1�� �԰�, ... , n�� ���� 1�� �԰�, 1�� ���� 1�� �԰�, ...

�������� k�� �� ��Ʈ��ũ ��ַ� ��� �ߴ�.
����ȭ �� �ٽ� ����� �̾ �� �� �� ���ĺ��� �����ؾ��ϴ��� �˰����Ѵ�.

ex)
1 2 3 1 3 -> 1
���� food_times�� [2, 1, 2] ���ٸ� -> -1 ����̾��� ��.

*/