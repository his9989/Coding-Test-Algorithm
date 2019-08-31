#include <iostream>
#include <string>
#include <vector>

using namespace std;



vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int temp, cnt;
	int ans[3] = { 0, 0, 0 }; // 3명의 수포자가 맞춘 정답을 저장
	int fir[5] = { 5, 1, 2, 3, 4 }; // 1번 수포자 방식
	int sec[8] = { 5, 2, 1, 2, 3, 2, 4, 2 }; // 2번 수포자 방식
	int thi[10] = { 5, 3, 3, 1, 1, 2, 2, 4, 4, 5 }; // 3번 수포자 방식

	// 모든 정답에 대해 탐색. 단 vector니까 마지막 번호부터 탐색
	// 자연스럽게 pop 이전의 answers.size()가 문제의 번호가 된다.
	while (!answers.empty()) {
		cnt = answers.size();
		temp = answers.back();
		answers.pop_back();
		// 수포자의 정답이 맞는 경우 ans를 증가시켜준다.
		if (temp == fir[cnt % 5]) ans[0]++;
		if (temp == sec[cnt % 8]) ans[1]++;
		if (temp == thi[cnt % 10]) ans[2]++;
	}
	// 기본적으로 ans[0]가 최고라고 가정
	int max = ans[0];
	answer.push_back(1);
	// ans[1]이 ans[0]보다 큰 경우, ans[0]을 빼버리고 ans[1] 넣기
	if (ans[1] > max) {
		answer.pop_back();
		answer.push_back(2);
		max = ans[1];
	}
	// ans[1] == ans[0]인 경우, ans[0], ans[1] 모두 저장됨
	else if (ans[1] == max) {
		answer.push_back(2);
	}
	// ans[2]가 ans[0] & ans[1] 중 무엇이 크든 둘이 같든 상관없이 둘 모두 보다 큰 경우
	if (ans[2] > max) {
		// answer에 있는거 다 빼버리고 ans[2]만 넣기
		while (!answer.empty()) answer.pop_back();
		answer.push_back(3);
	}
	// ans[2]가 ans[0] & ans[1] 중 무엇이 크든 둘이 같든 상관없이 max와 같은 경우 ans[3] 넣어주기
	else if (ans[2] == max)
		answer.push_back(3);
	return answer;
}