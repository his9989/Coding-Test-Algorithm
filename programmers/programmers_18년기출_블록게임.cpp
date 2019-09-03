#include <iostream>
#include <string>
#include <vector>

using namespace std;


// n��° ����� 1, 2, 5, 8, 10, 11, 12 �� �ϳ� ����̸� �� ��� ��ġ�δ� �ƹ��� ���� ����� ������ �������� �����Ƿ� üũ�� �ʿ䰡 ����. ��, checkX[x]�� 1�� üũ�Ѵ�. 
// ����, x��ǥ�� ���̻� ����� ���ų�, �ִ� ����� block[n] == 1 �� ���, checkX[n]�� 1�� üũ�Ѵ�.

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
	// 4�� ���鼭 4�� ������ x�� ��, y�� ���� �����Ѵ�. minY, minX, maxY, maxX�� �����Ѵ�.
	for (int i = 0; i<4; i++) {
		int y = blockMap[i].first; int x = blockMap[i].second;
		xSum += x; ySum += y;
		if (y > maxY) maxY = y; if (y < minY) minY = y;
		if (x > maxX) maxX = x; if (x < minX) minX = x;
	}
	// [minY, minX]���� [maxY, maxX]���� 6�� ���鼭 �ѹ��̶� -1�� ������ return false;
	for (int y = minY; y <= maxY; y++) for (int x = minX; x <= maxX; x++)
		if (map[y][x] == -1) { checkCnt = 1; return false; }
	// [minY, minX]���� [maxY, maxX]���� 6�� ���鼭 �ѹ��̶� �ڱ� ���� �ٸ� �༮�� ��Ÿ���ٸ�
	for (int y = minY; y <= maxY; y++) for (int x = minX; x <= maxX; x++) {
		if (map[y][x] != map[blockMap[0].first][blockMap[0].second] && map[y][x] != 0) {
			if (inputY == maxY) checkCnt = 1; // �̰� ������ Ž���� ���
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

	// x�� ������ 3���̰�, ���������� �� �� ����
	if (double(xSum) / 4.0 == (double(minX) + 0.25)) {
		if (double(ySum) / 4.0 == (double(maxY) - 0.75)) return true;
		else { checkCnt = 1; return false; }
	}
	// x�� ������ 3���̰�, �������� �� �� ����
	if (double(xSum) / 4.0 == (double(maxX) - 0.25)) {
		if (double(ySum) / 4.0 == (double(maxY) - 0.75)) return true;
		else { checkCnt = 1; return false; }
	}
	// ���� �Գ� ����
	if (double(ySum) / 4.0 == double((maxY)-0.25)) return true;
	// �Ʒ��� �Գ� ����
	if (double(ySum) / 4.0 == double((minY)+0.25)) { checkCnt = 1; return false; }
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	// board�� ���� map�̶�� 2���� �迭�� �ű��
	for (int y = 0; y<board.size(); y++)
		for (int x = 0; x<board[y].size(); x++)
			map[y][x] = board[y][x];

	// ���� ���� y����� �������鼭 Ž��
	for (int y = 0; y<board.size(); y++) {
		for (int x = 0; x<board[y].size(); x++) {
			// �ƾ� 0�� �ƴ� ���� ã�ƹ��ȴ�!
			if (map[y][x] > 0) {
				// blockMap�� �ʱ�ȭ�� �� dfs�� ���� �� ���ҵ��� ��ǥ�� blockMap�� �����Ѵ�.
				while (!blockMap.empty()) blockMap.pop_back();
				dfs(y, x, board.size());
				checkCnt = 0;
				if (isPossible(y)) {
					// blockMap�� �ش��ϴ� map�� ���� 0���� ��� �ٲ��ְ�
					for (int i = 0; i<4; i++)
						map[blockMap[i].first][blockMap[i].second] = 0;
					answer++;
				}
				else {
					if (checkCnt) {
						// blockMap�� �ش��ϴ� ��� x���� ���� ���� 0�� -1�� �ٲ۴�.
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
0�� ������ �� ������, 1�� ���� �����ִ�. �� �� 1�� ������ 1�� ��������, �̹� -1�� ä�������� �� �ִ�. �̷��� ���� �߻�.
*/