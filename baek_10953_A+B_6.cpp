#include<iostream>
#include<string>
using namespace std;

int main() {
	int num;
	string str;
	int a, b;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> str;
		// �Է¹��� ���ڿ��� ,���� ���ڸ� ���������� ����ȯ
		a = atoi(&str[0]);
		// �Է¹��� ���ڿ��� ,������ ���ڸ� ���������� ����ȯ
		b = atoi(&str[2]);
		// ���� ������ a, b�� 10 �̸��̹Ƿ� �̿Ͱ��� ������ ���� ����
		cout << a + b<<"\n";
	}
}