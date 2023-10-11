#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int map[55][55];
int r, c;
int n, m;
int cnt = 0;
int dir;
int four[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int turn(int a) {

	if (a == 0) {	
		return 3;
	} 
	else {
		return a - 1;
	}
}
int check(int a, int b) {

	for (int i = 0; i < 4; i++) {
		int x = a + four[i][0];
		int y = b + four[i][1];
		if (map[x][y] == 0) {
			return 1;
		}
	}
	return 0;
}
pair<int,int> move_foward(int a) {
	if (a == 0) {
		return{ -1,0 };
	}
	else if (a == 1) {
		return{ 0,1 };
	}
	else if (a == 2) {
		return{ 1,0 };
	}
	else if (a == 3) {
		return { 0,-1 };
	}
}
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	cin >> r >> c>>dir;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		
		if (map[r][c] == 0) {
			
			map[r][c] = 2;
			cnt++;
		}

		if (check(r, c) == 0) {
			int temp_dir = turn(dir);
			temp_dir = turn(temp_dir);
			int mov_x = r+move_foward(temp_dir).first;
			int mov_y = c+move_foward(temp_dir).second;
			if (map[mov_x][mov_y] == 1) {
				break;
			}
			else {
				r = mov_x;
				c = mov_y;
				continue;
			}
		}
		else {
			dir = turn(dir);
			int mov_x = r+move_foward(dir).first;
			int mov_y = c+move_foward(dir).second;
			if (map[mov_x][mov_y] == 0) {
				r = mov_x;
				c = mov_y;
				
				continue;
			}

		}
		
	}
	cout << cnt;
}