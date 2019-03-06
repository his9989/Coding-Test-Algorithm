## 백준 알고리즘 1463번. 1로 만들기

**x에 대한 답을 구하기 위해서 1부터 차근차근 답을 구합니다.**

즉, 5를 구하고 싶은 경우에는 1, 2, 3, 4에 대한 답을 먼저 구합니다.
그리고, 그 답을 이용하여 5에 대한 답을 구하게 됩니다.

1부터 차근차근 구한 답은 배열의 원소로 저장한다.

즉, **x에 대한 답은 arr[x]에 저장**하게 된다.


<code>

	#include<iostream>
	using namespace std;

	int min(int a, int b) {							// a, b를 입력하면 작은 값을 반환하는 함수입니다.
		if (a > b) return b;
		else return a;
	}

	int main(void) {
		int input, i;							// input : 1을 만들고자 하는 입력값
		cin >> input;
		int length = input + 2;						// 직관성을 위해서, x에 대한 답은 arr[x]에 저장합니다. 그래서 length=input+1;입니다.
										// 동적 배열 크기에 의한 런타임 에러 발생으로, length의 크기를 하나 더 키웠습니다.

		int *num = NULL;						// 크기가 length인 동적 배열 선언
		num = new int[length];

		num[1] = 0;							// 입력이 1인 경우, 답은 0입니다. (입력이 0인 경우는 무의미합니다.)
		for (i = 2; i <= input; i++) {					// 2인 경우 부터, 구하고자 하는 입력값까지 연산을 반복하여 답을 구합니다.

			num[i] = num[i - 1] + 1;				// num[i]에 1을 빼는 경우를 먼저 넣어둔다. 이건 어느 경우라도 비교해야하는 기본 값이므로
			if (i % 2 == 0) num[i] = min(num[i], num[i / 2] + 1);	// 2의 배수인 경우에는, 2로 나누는 경우와 1을 빼는 경우 중 무엇이 더 효율적인지 비교한다.
			if (i % 3 == 0) num[i] = min(num[i], num[i / 3] + 1);	// 3의 배수인 경우, num[i]에는 이미 2로 나누는 경우와 1을 빼는 경우 중의 작은 값이 있으므로, 이와 3으로 나눈 경우 중 최소값 비교
		}
		cout << num[input];						// input에 해당하는 답을 출력합니다.
		return 0;
	}

</code>
