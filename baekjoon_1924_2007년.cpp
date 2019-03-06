#include<iostream>
#include<string>
using namespace std;

int main() {
	int month, day;
	cin >> month >> day;
	int count = 0;
	string str;
	int arr[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0; i<month; i++) {
		count += arr[i];
	}
	count += day;
	count %= 7;

	switch (count) {
	case 1:
		str = "MON";
		break;
	case 2:
		str = "TUE";
		break;
	case 3:
		str = "WED";
		break;
	case 4:
		str = "THU";
		break;
	case 5:
		str = "FRI";
		break;
	case 6:
		str = "SAT";
		break;
	case 0:
		str = "SUN";
		break;
	default:
		cout << "who are you..?";
	}

	cout << str <<"\n";
}
