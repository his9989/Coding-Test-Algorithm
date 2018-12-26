#include<iostream>
#include<string>
using namespace std;

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main() {
	int stair_count = 0;
	cin >> stair_count;
	int *arr = NULL;
	int *dp = NULL;
	arr = new int[stair_count];
	dp = new int[stair_count];
	for (int i = 0; i < stair_count; i++) {
		cin >> arr[i];
		dp[i] = 0;
	}
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	for (int i = 2; i < stair_count; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}
	cout << dp[stair_count - 1];
	return 0;
}