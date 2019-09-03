#include <iostream>
#include <string>
#include <vector>

using namespace std;


// n번째 블락이 1, 2, 5, 8, 10, 11, 12 중 하나 모양이면 그 블락 위치로는 아무리 검정 블락을 내려도 없어지지 않으므로 체크할 필요가 없다. 즉, checkX[x]를 1로 체크한다. 
// 또한, x좌표에 더이상 블락이 없거나, 있는 블락의 block[n] == 1 인 경우, checkX[n]을 1로 체크한다.

int map[201][201];
vector<pair<int, int>>blockMap;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int checkCnt = 0;

void dfs(int y, int x, int _size) {
	blockMap.push_back(make_pair(y, x));
	for (int i = 0; i<4; i++) {
		if (y + dy[i] >= 0 && y + dy[i] < _size && x + dx[i] >= 0 && x + dx[i]<_size)
			if (map[y + dy[i]][x + dx[i]] == map[y][x]) {
				int check = 0;
				for (int k = 0; k<blockMap.size(); k++) if (blockMap[k].first == y + dy[i] && blockMap[k].second == x + dx[i])
					check = 1;
				if (!check) dfs(y + dy[i], x + dx[i], _size);
			}
	}
}

bool isPossible(int inputY) {
	int xSum = 0, ySum = 0;
	int minY = 201, minX = 201, maxY = 0, maxX = 0;
	// 4번 돌면서 4개 원소의 x축 값, y축 값을 저장한다. minY, minX, maxY, maxX를 저장한다.
	for (int i = 0; i<4; i++) {
		int y = blockMap[i].first; int x = blockMap[i].second;
		xSum += x; ySum += y;
		if (y > maxY) maxY = y; if (y < minY) minY = y;
		if (x > maxX) maxX = x; if (x < minX) minX = x;
	}
	// [minY, minX]부터 [maxY, maxX]까지 6번 돌면서 한번이라도 -1이 나오면 return false;
	for (int y = minY; y <= maxY; y++) for (int x = minX; x <= maxX; x++)
		if (map[y][x] == -1) { checkCnt = 1; return false; }
	// [minY, minX]부터 [maxY, maxX]까지 6번 돌면서 한번이라도 자기 값과 다른 녀석이 나타난다면
	for (int y = minY; y <= maxY; y++) for (int x = minX; x <= maxX; x++) {
		if (map[y][x] != map[blockMap[0].first][blockMap[0].second] && map[y][x] != 0) {
			if (inputY == maxY) checkCnt = 1; // 이게 마지막 탐색인 경우
			return false;
		}
	}
	/*
	int _check = 0;
	for(int y = minY; y<=maxY; y++) for(int x=minX; x<=maxX; x++)
	if(map[y][x] == map[blockMap[0].first][blockMap[0].second] || map[y][x] == 0)
	_check = 1;
	if(_check && minY>0 && inputY == maxY)
	for(int _y = minY-1; _y>=0; _y--)
	for(int _x = minX; _x<=maxX; _x++)
	if(map[_y][_x] != 0) {checkCnt = 1; return false;}
	*/

	// x축 같은게 3개이고, 오른쪽으로 뿔 단 형태
	if (double(xSum) / 4.0 == (double(minX) + 0.25)) {
		if (double(ySum) / 4.0 == (double(maxY) - 0.75)) return true;
		else { checkCnt = 1; return false; }
	}
	// x축 같은게 3개이고, 왼쪽으로 뿔 단 형태
	if (double(xSum) / 4.0 == (double(maxX) - 0.25)) {
		if (double(ySum) / 4.0 == (double(maxY) - 0.75)) return true;
		else { checkCnt = 1; return false; }
	}
	// 위로 뿔난 형태
	if (double(ySum) / 4.0 == double((maxY)-0.25)) return true;
	// 아래로 뿔난 형태
	if (double(ySum) / 4.0 == double((minY)+0.25)) { checkCnt = 1; return false; }
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	// board의 값을 map이라는 2차원 배열로 옮기기
	for (int y = 0; y<board.size(); y++)
		for (int x = 0; x<board[y].size(); x++)
			map[y][x] = board[y][x];

	// 가장 높은 y축부터 내려오면서 탐색
	for (int y = 0; y<board.size(); y++) {
		for (int x = 0; x<board[y].size(); x++) {
			// 아앗 0이 아닌 값을 찾아버렸다!
			if (map[y][x] > 0) {
				// blockMap을 초기화한 뒤 dfs를 통해 블럭 원소들의 좌표를 blockMap에 저장한다.
				while (!blockMap.empty()) blockMap.pop_back();
				dfs(y, x, board.size());
				checkCnt = 0;
				if (isPossible(y)) {
					// blockMap에 해당하는 map의 값을 0으로 모두 바꿔주고
					for (int i = 0; i<4; i++)
						map[blockMap[i].first][blockMap[i].second] = 0;
					answer++;
				}
				else {
					if (checkCnt) {
						// blockMap에 해당하는 모든 x축의 값에 대해 0을 -1로 바꾼다.
						for (int i = 0; i<4; i++)
							for (int _y = blockMap[i].first; _y<board[0].size(); _y++)
								if (map[_y][blockMap[i].second] == 0)
									map[_y][blockMap[i].second] = -1;
					}
				}
			}
		}
	}
	/*
	for(int y=0; y<board.size(); y++){
	for(int x=0; x<board[y].size(); x++)
	cout<<map[y][x]<<"  ";
	cout<<endl;
	}*/
	return answer;
}

/*    2 2
1 2
1 2
3 1 1 -1
3 3 3 -1
0도 없어질 수 있지만, 1에 의해 막혀있다. 이 후 1을 만나서 1을 없애지만, 이미 -1로 채워져버릴 수 있다. 이러면 에러 발생.
*/