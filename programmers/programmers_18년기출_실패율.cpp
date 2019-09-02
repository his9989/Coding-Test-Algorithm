#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int stageUser[501]; // n번째 stage까지 도달한 인원 기록. n+1원소는 모두를 클리어한 인원
vector<pair<double, int>>fin;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	while (!stages.empty()) {
		int stage = stages.back();
		stages.pop_back();
		for (int i = 1; i<stage + 1; i++) {
			// n번째 stage까지 도달한 인원 기록
			stageUser[i] += 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		int _pause = stageUser[i] - stageUser[i + 1];
		int _come = stageUser[i]; // 0 일 수 있다.
		double _cant = 0.0;
		if (_come != 0) _cant = double(_pause) / _come;
		// i, _cant를 갖고 있는 데이터에서 _cant에 따라 정렬한 뒤, 같은 _cant에 대해 i순으로 정렬하여 그 순서로 i를 출력해야한다.
		// 한번의 sorting으로 정렬하기 위해, 실패율로 내림차순인 조건을 성공률로 바꿔서 오름차순으로 정렬한다.
		fin.push_back(make_pair((1 - _cant), i));
	}
	sort(fin.begin(), fin.end());
	for (int i = 0; i<fin.size(); i++)
		answer.push_back(fin[i].second);
	return answer;
}

// N : 전체 스테이지 개수. 1~500
// stages : 게임 유저가 stages.size()만큼 있을 때, 각 유저가 멈춰있는 스테이지 수. 1~200,000
// stages[i] == N+1인 경우 : 모든 스테이지를 클리어한 사용자
// 스테이지에 도달한 유저가 없는 경우 실패율은 0
// answer는 실패율이 높은 순에 같은 실패율에 대해 오름차순으로 출력

/*
필요한 자료형 : 각 스테이지에 몇명이 방문했는지 기록하는 숫자
*/

/*
n번째 스테이지의 실패율 : n번째 스테이지에 도달했지만 클리어하지 못한 플레이어 수/ n번째 스테이지에 도달한 플레이어 수
*/