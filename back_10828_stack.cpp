#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<int> stack1;

int main() {
	// push, pop, top, empty, size
	int num = 0;
	cin >> num;
	string commend;
	int check=0;
	
	for (int i = 0; i < num; i++) {
		cin >> commend;
		if (commend == "push") {
			cin >> check;
			stack1.push(check);
		}
		else if (commend == "pop") {
			if (stack1.empty()) cout << -1 << "\n";
			else {
				cout<<stack1.top()<<"\n";
				stack1.pop();
			}
		}
		else if (commend == "top") {
			if (stack1.empty()) cout << -1 << "\n";
			else cout<<stack1.top()<<"\n";
		}
		else if (commend == "empty") {
			if (stack1.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (commend == "size") {
			cout << stack1.size()<<"\n";
		}
		else {
			cout << "error\n";
		}
	}
}