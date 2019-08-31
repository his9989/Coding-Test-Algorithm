#include <string>
#include <vector>
using namespace std;

vector<string> vec[50];
vector<string> word;
int visited[52];
int ans = 0;
string _tar;

// �ϳ��� ���ڷ� ���氡������ �� ����
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
		// �� ����� ������ ����ص� �ɰͰ�����, �ϴ� �� ��ĵ� �ð��ʰ��� �ȳ���.
		for (int i = 0; i<word.size(); i++) {
			// i�� �̹� �湮�� ��� �����Ű��
			if (visited[i] == 1) continue;
			// vec[num]�κ��� �ϳ��� ���ڸ� �ٲ㼭 ���� �� �ִ� ��带 ã����
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
	int t_check = 0; // target ���ڰ� words �ĺ��� �ִ��� ���θ� Ȯ���ϱ� ���� ����
	for (int i = 0; i<words.size(); i++) {
		if (words[i] == target) t_check = 1;
		word.push_back(words[i]);
	}
	// t_check = 0�ΰ�� �� �͵� ���� 0���� ��ȯ
	if (t_check == 0) return 0;

	// ��¶�� ������ ������ ���
	vec[0].push_back(begin); // begin�� vector[0]�� �ִ´�.

	dfs(0);

	answer = ans;
	return answer;
}


/*
begin���� �ϳ��� ���ڸ� �ٲ㼭 ���� �� �ִ� ��带 vector[1]�� �ִ´�.
vector[1]���� �ϳ��� ���ڸ� �ٲ㼭 ���� �� �ִ� ��带 vector[2]�� �ִ´�. ��, vector[1]�� �ִ� �ܾ�� ���� �ʴ´�.
vector[2]���� �ϳ��� ���ڸ� �ٲ㼭 ���� �� �ִ� ��带 vector[3]�� �ִ´�. ��, vector[2]�� �ִ� �ܾ�� ���� �ʴ´�.
...
�̷�������
vector[i]���� �ϳ��� ���ڸ� �ٲ㼭 ���� �� �ִ� ��尡 target�� ���, i+1�� return�ϰ� �����Ѵ�.
...
��, ��� words�� Ž���ߴµ�, target�� ������ ���� ��� 0�� return�Ѵ�.
*/