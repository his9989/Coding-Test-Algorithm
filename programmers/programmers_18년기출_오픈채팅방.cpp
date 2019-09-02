#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
vector<pair<string, string>> mes;
//pair<string, string> name[100000];
map<string, string> name;

// recod�� 1 �̻� 100,000����
vector<string> solution(vector<string> record) {
	vector<string> answer;
	int cnt = 0;

	for (int i = 0; i<record.size(); i++) {
		string message1 = record[i];
		int che = 0;
		// ���ڷ� �����ߴ�.
		string m1 = "", m2 = "", m3 = "";
		for (int j = 0; j<message1.size(); j++) {
			if (message1[j] != 32 && che == 0) m1 += message1[j];
			else if (message1[j] != 32 && che == 1) m2 += message1[j];
			else if (message1[j] != 32 && che == 2) m3 += message1[j];
			else if (message1[j] == 32) che += 1;
		}
		// ���̵�� ���� vector ����
		mes.push_back(make_pair(m2, m1));
		if (m1 == "Enter") {
			// m2�� �̹� �����ϴ� ��� ã�Ƽ� �������ֱ�
			if (name.find(m2) != name.end()) name.find(m2)->second = m3;
			// �������� �ʴ� ��� �־��ֱ�
			else { name.insert(make_pair(m2, m3)); cnt++; }
		}
		else if (m1 == "Change") name.find(m2)->second = m3;
	}


	// mes���� �ϳ��� �����鼭 ���� ���̵� �ش��ϴ� ���� �г����� ���
	for (int i = 0; i<mes.size(); i++) {
		string m2 = mes[i].first;
		string m1 = mes[i].second;
		string printName = "";
		printName = name.find(m2)->second;
		if (m1 == "Enter") printName += "���� ���Խ��ϴ�.";
		else if (m1 == "Leave") printName += "���� �������ϴ�.";
		else if (m1 == "Change") continue;
		answer.push_back(printName);
	}

	return answer;
}

/*
�г����� �����ϴ� ��� 1. stack���� ���� �� �ٽ� ������
2. ä�ù� ������ �̸� �ٲٱ�
-> ������ ��µǾ� �ִ� �г��ӵ� ��� �ٲ��. (�г��� �ߺ� ����, �������̵� �ߺ� �Ұ���)
record�� ���� ���������� ��µǴ� ����� �ϼ��϶�
*/

/*
������ ���� �����͸� �������̵�� stack�� �״´�.
�˰��� ���� �г��� �� ���������� ���� �г����� stack�� �״´�.

�˰��� : enter�� �� Ȥ�� change �� ������ ���� ���̵� ���� �г����� �������ش�.

�������̵� �г����� ��Ī���Ѽ� �����Ѵ�.
*/