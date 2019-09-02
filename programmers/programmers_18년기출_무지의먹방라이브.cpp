#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<pair<long long, long long>> q;

// k가 2 x 10^13 이하의 자연수
// food_times의 원소는 100,000,000이하의 자연수
// food_times 원소 개수는 200,000이하의 자연수
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
N개의 음식
1번부터 음식 먹기 시작
회전판은 음식번호 오름차순
마지막 번호 음식 먹으면 1번 음식이 돌아온다. (Queue)

무지는 1초에 한가지의 음식만 먹는다.
즉, 1번 음식 1초 먹고, 2번 음식 1초 먹고, ... , n번 음식 1초 먹고, 1번 음식 1초 먹고, ...

시작한지 k초 후 네트워크 장애로 방송 중단.
정상화 후 다시 방송을 이어갈 때 몇 번 음식부터 섭취해야하는지 알고자한다.

ex)
1 2 3 1 3 -> 1
만약 food_times가 [2, 1, 2] 였다면 -> -1 출력이었을 것.

*/