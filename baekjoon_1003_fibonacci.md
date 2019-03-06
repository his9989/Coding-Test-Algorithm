## 백준 알고리즘 1003번 피보나치 수열 찾기

**fibonacci 수열을 Dynamic programming으로 해결할 때, fib(0)과 fib(1)이 각각 몇 번 씩 사용되는지 출력하는 코드.**

이는 규칙적인 모양을 보인다. <br>

<code>

	ex)	fib(n)		0 횟수	      1 횟수		    (value)
		0		1		0			0
		1		0		1			1
		2		1		1			1
		3		1		2			2
		4		2		3			3
		5		3		5			5
		6		5		8			8
		...
	
</code>
	

즉, **n의 fib(0), fib(1) 사용횟수**는 **n-1과 n-2의 fib(0), fib(1) 사용횟수 들의 각각의 합**과 같다.


<code>

	#include<iostream>
	using namespace std;

	int a, b;							// a는 fib(0) 사용횟수, b는 fib(1) 사용횟수를 저장하는 전역변수이다.

	int fib(int);							// 밑에 구현할 피보나치 함수 선언

	int main() {
		int count, i;						// 몇 번 계산할지 입력받는 변수
		cin >> count;

		int *nums = NULL;					// 변수 입력을 먼저 일괄적으로 받고, 한번에 출력하기 위한 동적 배열 선언
		nums = new int[count+1];

		for (i = 0; i < count; i++) cin >> nums[i];		// 몇 번째 피보나치 수열 원소를 구하고자 하는지 먼저 일괄 입력 받는다.

		for (i = 0; i < count; i++) {
			a = 0; b = 0;					// fib(0) 사용횟수와 fib(1) 사용횟수를 0으로 초기화한다..
			fib(nums[i]);
			cout << a << " " << b << endl;			// fib(num[i])에서 fib(0) 사용횟수와 fib(1) 사용횟수를 출력한다.
		}
	}

	int fib(int num) {
		int i;

		int *arr = NULL;					// n번 째 피보나치 수열의 값을 Dynamic programming으로 구하기 위해
		arr = new int[num+1];					// 0 번째부터 n 번째 까지 차근차근 피보나치 수열 값을 저장할 동적배열 선언

		int *num1 = NULL;					// x 번째 피보나치 수열 원소에서 fib(0)과 fib(1)의 사용횟수를 각각 저장하는 동적 배열 선언
		int *num2 = NULL;					// fib(0)의 사용횟수를 저장하는 배열: num1, fib(1)의 사용횟수를 저장하는 배열: num2
		num1 = new int[num+1];
		num2 = new int[num+1];

		arr[0] = 0; num1[0] = 1; num2[0] = 0;			// 0번 째 피보나치 수열에 해당하는 값을 선언한다. (최상단에 나열된 숫자 배열 참고)
		if (num > 0) {
			arr[1] = 1;					// num이 0보다 큰 경우 1번 째 피보나치 수열에 해당하는 값을 선언한다. (최상다넹 나열된 숫자 배열 참고)
			num1[1] = 0; num2[1] = 1;
			for (i = 2; i <= num; i++) {			// num이 1보다 큰 경우, 2부터 num까지 피보나치 규칙을 반복한다.
				arr[i] = arr[i - 1] + arr[i - 2];	// i번 째 피보나치 수열 값은 i-1번째 값과 i-2번째 값의 합과 같다.
				num1[i] = num1[i - 1] + num1[i - 2];	// i번 째 fib(0)의 사용횟수의 값은 i-1번째와 i-2번째의 값의 합과 같다.
				num2[i] = num2[i - 1] + num2[i - 2];	// i번 쨰 fib(1)의 사용횟수의 값은 i-1번째와 i-2번째의 값의 합과 같다.
			}
		}
		a = num1[num];						// num1[num]이 구하고자 하는 값의 fib(0)의 사용횟수.
		b = num2[num];						// num2[num]이 구하고자 하는 값의 fib(1)의 사용횟수. 전역변수이므로, 추가적인 작업 필요없다.
		return arr[num];					// 반환값은 무의미하다. 0으로 해도 무방함.
	}

</code>
