#include<iostream>
#include<stack>
#include<string>

using namespace std;

string pare, ans;

int main() {
	int num;
	int length;

	int left = 0;
	int right = 0;

	cin >> num;

	for (int i = 0; i < num; i++) {
		stack<char> stack1;
		left = 0; right = 0;

		cin >> pare;
		int j = 0;
		for (j = 0; j < pare.size(); j++) {
			if (pare.at(j) == '(') {
				stack1.push('(');
				left++;
			}
			else if (pare.at(j) == ')') {
				if (j==0 || right >= left) {
					cout << "NO\n";
					break;
				}
				stack1.push(')');
				right++;
			}
		}
		if (j==pare.size() && (stack1.top() == '(' || left != right)) {
			cout << "NO\n";
		}
		else if(j==pare.size()) {
			cout << "YES\n";
		}

	}
}
