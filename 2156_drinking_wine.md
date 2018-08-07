## 백준 알고리즘 2156번. 포도주 시식

* 문제: n개의 포도주가 일렬로 정렬되어 있다. 와인잔에 들어있는 와인의 양은 각각마다 들어있는 양이 다르다. <br>
       연속으로 3개의 와인을 마실 수 없을 때, 최대로 많은 양을 마실수 있는 포도주의 양을 출력하시오.
       
* 입력: 첫 줄에는 포도주 잔의 개수 n이 주어진다.(1<=n<=10,000) <br>
        둘째 줄부터 n개의 포도주 잔의 와인 양이 순서대로 입력된다.
        
* 출력: 최대로 마실 수 있는 포도주의 양을 출력한다.

<code>

    #include<iostream>
    using namespace std;

    int Max(int a, int b, int c) {      // 3개의 매개 변수 중 최대 값을 반환하는 함수
      if (b > a) {	                    //b, c 비교 필요
        if (b > c)  return b;
        else	    return c;
      }
      else {			                      //a, c 비교 필요
        if (a > c)	return a;
        else        return c;
      }
    }

    int main() {
      int num = 0, i = 0;
      cin >> num;

      int * arr = NULL;                 // 포도주의 양이 저장되는 동적 배열
      arr = new int[num];

      int * max = NULL;                 // 1번째부터 n번째까지 각 경우에서의 포도주 최대값을 저장하는 동적 배열
      max = new int[num];               // 다이나믹 프로그래밍을 사용한다.

      for (i = 0; i<num; i++) { cin >> arr[i]; }  // 포도주의 양 입력

      max[0] = arr[0];                  // 1번째 와인잔에 대해서는 그냥 먹는게 최대값

      if (num>0) {
        max[1] = arr[0] + arr[1];       // 2번째 와인잔에 대해서도 연속으로 그냥 둘 다 먹는게 최댓값
        if (num>1) {
          max[2] = Max(max[1], arr[0] + arr[2], arr[1] + arr[2]);   // 3번째 와인잔에 대해서는 3가지 경우가 있다.
                                                                    // (1st+2nd) or (1st+3rd) or (2nd+3rd)
                                                                    // 이 개념은 4번째 이상에서도 사용된다.
          for (i = 2; i<num; i++) {
            max[i] = Max(max[i - 3] + arr[i - 1] + arr[i], max[i - 2] + arr[i], max[i - 1]);
          }
        }
      }
      cout << max[num - 1];             // 결과 출력
    }
 
 </code>
