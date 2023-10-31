#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char map[15][15];
int r, c;
int four[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
vector<pair<int, int>> chan;

int main() {

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
	for(int i = 0;i<r;i++){
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'X') {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int x = i + four[k][0];
					int y = j + four[k][1];
					if (x < 0 || y < 0 || x >= r || y >= c) {
						cnt++;
						continue;
					}
					if (map[x][y] == '.') {
						cnt++;
					}
				}
				if (cnt >= 3) {
					chan.push_back({ i,j });
				}
			}
		}
	}
	for (int i = 0; i < chan.size(); i++) {
		map[chan[i].first][chan[i].second] = '.';
	}

	int x_min = 100;
	int x_max = 0;
	int y_min = 100;
	int y_max = 0;
	for (int i = 0; i < r; i++) {
		int min_set = 0;
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'X'&&min_set==0) {
				y_min = min(y_min, j);
				x_min = min(x_min, i);
				min_set = 1;
			}
			if (map[i][j] == 'X' && min_set == 1) {
				y_max = max(y_max, j);
				x_max = max(x_max, i);
			}
		}
		min_set = 0;
		
	}
	
	for (int i = x_min; i <= x_max; i++) {
		for (int j = y_min; j <= y_max; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}