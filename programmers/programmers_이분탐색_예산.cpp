#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0, _max = 0;
	long long _sum = 0;
	int len = budgets.size();

	// 일단 예산을 정렬한다.
	sort(budgets.begin(), budgets.end());

	// 전체 합이 M보다 작은 경우 마지막 원소 리턴
	for (int i = 0; i<len; i++) _sum += budgets[i];
	if (_sum <= M) return budgets.back();

	// 최소부터 하나씩 제외시키고 평균 계산해서 최댓값 설정
	int t_sum = 0;
	vector<int>vec;
	for (int i = 0; i<len - 1; i++) {
		t_sum += budgets[i];
		if (t_sum>M) break;
		//vec.push_back(budgets[i]);
		if (_sum <= M) {
			vec.push_back((_sum - t_sum) / (len - i - 1));
			if (_max < (_sum - t_sum) / (len - i - 1)) _max = (_sum - t_sum) / (len - i - 1);
		}
		else {
			vec.push_back((M - t_sum) / (len - i - 1));
			if (_max < (M - t_sum) / (len - i - 1)) _max = (M - t_sum) / (len - i - 1);
		}
	}

	// 전체가 M보다 큰 경우 평균이 M이 된다.
	vec.push_back(M / len);
	if (_max < (M / len)) _max = (M / len);
	answer = _max;
	return answer;
}