#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	// 참가자 정렬
	sort(participant.begin(), participant.end());
	// 완주자 정렬
	sort(completion.begin(), completion.end());
	// 참가자는 기본적으로 완주자보다 한 명 더 많다. 마지막 원소 비교 후, 완주자 개수만큼 비교할 예정
	if (participant.back() != completion.back()) answer = participant.back();
	// 완주자 개수만큼 비교하면서 다른 경우 그 참가자가 완주하지 못한 선수가 된다.
	else
		for (int i = 0; i < completion.size(); i++)
			if (participant[i] != completion[i]) {
				answer = participant[i];
				break;
			}
	return answer;
}