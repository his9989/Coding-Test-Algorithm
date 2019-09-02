#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
vector<pair<string, string>> mes;
//pair<string, string> name[100000];
map<string, string> name;

// recod는 1 이상 100,000이하
vector<string> solution(vector<string> record) {
	vector<string> answer;
	int cnt = 0;

	for (int i = 0; i<record.size(); i++) {
		string message1 = record[i];
		int che = 0;
		// 문자로 정리했다.
		string m1 = "", m2 = "", m3 = "";
		for (int j = 0; j<message1.size(); j++) {
			if (message1[j] != 32 && che == 0) m1 += message1[j];
			else if (message1[j] != 32 && che == 1) m2 += message1[j];
			else if (message1[j] != 32 && che == 2) m3 += message1[j];
			else if (message1[j] == 32) che += 1;
		}
		// 아이디와 동작 vector 생성
		mes.push_back(make_pair(m2, m1));
		if (m1 == "Enter") {
			// m2가 이미 존재하는 경우 찾아서 변경해주기
			if (name.find(m2) != name.end()) name.find(m2)->second = m3;
			// 존재하지 않는 경우 넣어주기
			else { name.insert(make_pair(m2, m3)); cnt++; }
		}
		else if (m1 == "Change") name.find(m2)->second = m3;
	}


	// mes에서 하나씩 뽑으면서 유저 아이디에 해당하는 최종 닉네임을 출력
	for (int i = 0; i<mes.size(); i++) {
		string m2 = mes[i].first;
		string m1 = mes[i].second;
		string printName = "";
		printName = name.find(m2)->second;
		if (m1 == "Enter") printName += "님이 들어왔습니다.";
		else if (m1 == "Leave") printName += "님이 나갔습니다.";
		else if (m1 == "Change") continue;
		answer.push_back(printName);
	}

	return answer;
}

/*
닉네임을 변경하는 방법 1. stack에서 나간 후 다시 들어오기
2. 채팅방 내에서 이름 바꾸기
-> 기존에 출력되어 있던 닉네임도 모두 바뀐다. (닉네임 중복 가능, 유저아이디 중복 불가능)
record에 의해 최종적으로 출력되는 결과를 완성하라
*/

/*
들어오고 나온 데이터를 유저아이디로 stack에 쌓는다.
알고리즘에 의해 닉네임 당 최종적으로 남은 닉네임을 stack에 쌓는다.

알고리즘 : enter할 때 혹은 change 할 때마다 유저 아이디에 대한 닉네임을 변경해준다.

유저아이디에 닉네임을 매칭시켜서 저장한다.
*/