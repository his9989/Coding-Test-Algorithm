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
		// 입력받은 문자열의 ,왼쪽 숫자를 정수형으로 형변환
		a = atoi(&str[0]);
		// 입력받은 문자열의 ,오른쪽 숫자를 정수형으로 형변환
		b = atoi(&str[2]);
		// 문제 조건이 a, b가 10 미만이므로 이와같이 간단히 구현 가능
		cout << a + b<<"\n";
	}
}
