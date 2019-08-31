#include<iostream>
#include<algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> temp; // 3개의 원소로 이루어진 command 벡터를 저장하는 자료구조
	vector<int> answer; // 정답을 저장하는 주어진 자료구조.
	vector<int> tempAnswer; // 임시 답안을 저장하는 자료구조

	// 모든 commands를 확인
	while (!commands.empty()) {
		// 3개의 원소로 이루어진 command 벡터를 temp에 선언
		temp = commands.back();
		commands.pop_back();

		// 길이가 아래와 같은 동적배열 선언.
		int *arr = new int[temp[1] - temp[0] + 1];
		// 선언한 동적배열에 array의 temp에 의한 위치를 저장한다.
		int j = 0;
		for (int i = temp[0] - 1; i <= temp[1] - 1; i++) {
			arr[j] = array[i];
			j++;
		}
		// 저장한 arr배열을 정렬
		sort(arr, arr + temp[1] - temp[0] + 1);
		// 사실 여기서 바로 answer에 push해도 된다.
		// 다만 그냥 재정렬시키기 귀찮아서 이렇게함..ㅋㅋ
		tempAnswer.push_back(arr[temp[2] - 1]);
	}
	while (!tempAnswer.empty()) {
		int tem = tempAnswer.back();
		tempAnswer.pop_back();
		answer.push_back(tem);
	}
	return answer;
}