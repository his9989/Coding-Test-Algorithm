#include <string>
#include <vector>
using namespace std;

vector<string> vec[50];
vector<string> word;
int visited[52];
int ans = 0;
string _tar;

// 하나의 문자로 변경가능한지 비교 구현
int checkWord(string a, string b) {
	int cnt = 0;
	for (int i = 0; i<a.size(); i++) {
		if (a[i] == b[i]) cnt++;
	}
	if (cnt + 1 == a.size()) return 1;
	else return 0;
}

void dfs(int num) {
	while (!vec[num].empty()) {
		string beforeWord = vec[num].back();
		vec[num].pop_back();
		// 비교 기능은 정렬을 사용해도 될것같은데, 일단 이 방식도 시간초과는 안난다.
		for (int i = 0; i<word.size(); i++) {
			// i에 이미 방문한 경우 종료시키기
			if (visited[i] == 1) continue;
			// vec[num]로부터 하나의 문자만 바꿔서 변할 수 있는 노드를 찾으면
			if (checkWord(word[i], beforeWord)) {
				if (word[i] == _tar) {
					ans = num + 1;
					return;
				}
				else {
					vec[num + 1].push_back(word[i]);
					visited[i] = 1;
				}
			}
		}
	}
	dfs(num + 1);
	return;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	_tar = target;
	int t_check = 0; // target 문자가 words 후보로 있는지 여부를 확인하기 위한 변수
	for (int i = 0; i<words.size(); i++) {
		if (words[i] == target) t_check = 1;
		word.push_back(words[i]);
	}
	// t_check = 0인경우 볼 것도 없이 0으로 반환
	if (t_check == 0) return 0;

	// 어쨋든 도착은 가능한 경우
	vec[0].push_back(begin); // begin을 vector[0]에 넣는다.

	dfs(0);

	answer = ans;
	return answer;
}


/*
begin에서 하나의 문자만 바꿔서 변할 수 있는 노드를 vector[1]에 넣는다.
vector[1]에서 하나의 문자만 바꿔서 변할 수 있는 노드를 vector[2]에 넣는다. 단, vector[1]에 있는 단어는 넣지 않는다.
vector[2]에서 하나의 문자만 바꿔서 변할 수 있는 노드를 vector[3]에 넣는다. 단, vector[2]에 있는 단어는 넣지 않는다.
...
이런식으로
vector[i]에서 하나의 문자만 바꿔서 변할 수 있는 노드가 target인 경우, i+1을 return하고 종료한다.
...
단, 모든 words를 탐색했는데, target이 나오지 않은 경우 0을 return한다.
*/