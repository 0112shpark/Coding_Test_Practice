#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[1010][1010] = { 0 };
vector <pair<int, int>> queen;
vector<pair<int, int>> kig;
int cnt = 0;
int kight[8][2] = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2} };
//1 = k; 2 = q; 3= p;  -1 = not safe;

int main() {

	int n, m;
	cin >> n >> m;

	int q, k, p;
	
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		cnt++;
		x--;
		y--;
		map[x][y] = 1;
		queen.push_back({ x,y});

	}


	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		map[x][y] = 2;
		kig.push_back({ x,y });
		cnt++;
		
	}

	cin >> p;
	for (int i = 0; i < p; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		
		map[x][y] = 3;
		cnt++;
	}
	for (int i = 0; i < kig.size(); i++){
		int x = kig[i].first;
		int y = kig[i].second;
		for (int j = 0; j < 8; j++) {
			int mov_x = x + kight[j][0];
			int mov_y = y + kight[j][1];

			if (mov_x >= 0 && mov_x < n && mov_y >= 0 && mov_y < m) {
				if (map[mov_x][mov_y] == 0) {
					cnt++;
					map[mov_x][mov_y] = -1;
				}
			}
		}
	}
	for (int i = 0; i < queen.size(); i++) {

		int x = queen[i].first;
		int y = queen[i].second;
		//¾Æ·¡
		while (x >= 0 && x < n && y >= 0 && y < m) {
			x += 1;
			if (x < 0 || x >= n || y < 0 || y >= m) {
				break;
			}
			if (map[x][y] == 0) {
				map[x][y] = -1;
				cnt++;
			}
			else if (map[x][y] == -1) {
				continue;
			}
			else {
				break;
			}
		}
		x = queen[i].first;
		y = queen[i].second;
		//cout << cnt;
		//À§
		while (x >= 0 && x < n && y >= 0 && y < m) {
			x -= 1;
			if (x < 0 || x >= n || y < 0 || y >= m) {
				break;
			}
			if (map[x][y] == 0) {
				map[x][y] = -1;
				cnt++;
			}
			else if (map[x][y] == -1) {
				continue;
			}
			else {
				break;
			}
		}
		//cout << 3;
		x = queen[i].first;
		y = queen[i].second;
		//¿À¸¥
		while (x >= 0 && x < n && y >= 0 && y < m) {
			y += 1;
			if (x < 0 || x >= n || y < 0 || y >= m) {
				break;
			}
			if (map[x][y] == 0) {
				map[x][y] = -1;
				cnt++;
			}
			else if (map[x][y] == -1) {
				continue;
			}
			else {
				break;
			}
		}
		x = queen[i].first;
		y = queen[i].second;
		//¿Þ
		while (x >= 0 && x < n && y >= 0 && y < m) {
			y -= 1;
			if (x < 0 || x >= n || y < 0 || y >= m) {
				break;
			}
			if (map[x][y] == 0) {
				map[x][y] = -1;
				cnt++;
			}
			else if (map[x][y] == -1) {
				continue;
			}
			else {
				break;
			}
		}
		x = queen[i].first;
		y = queen[i].second;
		
		//À­ ¿À¸¥ ´ë°¢
		while (x >= 0 && x < n && y >= 0 && y < m) {
			x -= 1;
			y += 1;
			if (x < 0 || x >= n || y < 0 || y >= m) {
				break;
			}
			if (map[x][y] == 0) {
				map[x][y] = -1;
				cnt++;
			}
			else if (map[x][y] == -1) {
				continue;
			}
			else {
				break;
			}
		}
		x = queen[i].first;
		y = queen[i].second;
		//À­ ¿Þ ´ë°¢
		while (x >= 0 && x < n && y >= 0 && y < m) {
			x -= 1;
			y -= 1;
			if (x < 0 || x >= n || y < 0 || y >= m) {
				break;
			}
			if (map[x][y] == 0) {
				map[x][y] = -1;
				cnt++;
			}
			else if (map[x][y] == -1) {
				continue;
			}
			else {
				break;
			}
		}
		x = queen[i].first;
		y = queen[i].second;
		//¾Æ·¡ ¿À¸¥ ´ë°¢
		while (x >= 0 && x < n && y >= 0 && y < m) {
			x += 1;
			y += 1;
			if (x < 0 || x >= n || y < 0 || y >= m) {
				break;
			}
			if (map[x][y] == 0) {
				map[x][y] = -1;
				cnt++;
			}
			else if (map[x][y] == -1) {
				continue;
			}
			else {
				break;
			}
		}
		x = queen[i].first;
		y = queen[i].second;
		//¾Æ·¡ ¿Þ ´ë°¢
		while (x >= 0 && x < n && y >= 0 && y < m) {
			x += 1;
			y -= 1;
			if (x < 0 || x >= n || y < 0 || y >= m) {
				break;
			}
			if (map[x][y] == 0) {
				map[x][y] = -1;
				cnt++;
			}
			else if (map[x][y] == -1) {
				continue;
			}
			else {
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << n * m - cnt;
}