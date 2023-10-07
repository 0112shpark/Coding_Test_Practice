#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int map[110][110];
int visited[110][110];
int n, m;
int melt = 0;
int ans = 0;
queue<pair<int, int>> q;
int four[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };


void reset_visit() {
	for (int i = 0; i < 110; i++) {
		for (int j = 0; j < 110; j++) {
			visited[i][j] = 0;
		}
	}
}

void bfs(int a,int b) {
	
	q.push({ a,b });
	visited[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int mov_x = x + four[i][0];
			int mov_y = y + four[i][1];
			if (mov_x < 0 || mov_y < 0 || mov_x >= n || mov_y >= m) {
				continue;
			}
			if (visited[mov_x][mov_y] != 1 && map[mov_x][mov_y] == 0) {
				visited[mov_x][mov_y] = 1;
				
				for (int j = 0; j < 4; j++) {
					int mov_x1 = mov_x + four[j][0];
					int mov_y1 = mov_y + four[j][1];
					if (mov_x1 < 0 || mov_y1 < 0 || mov_x1 >= n || mov_y1 >= m) {
						continue;
					}
					if (map[mov_x1][mov_y1] == 1) {
						map[mov_x1][mov_y1] = 2;
						melt++;
					}
				}
				q.push({ mov_x,mov_y });
			}
		}
	}

}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int time = 0;
	while (1) {
		melt = 0;
		reset_visit();
		bfs(0, 0);
		time++;
		if (melt > 0) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (map[i][j] == 2) {
						map[i][j] = 0;
					}
				}
			}
		}
		if (melt == 0) {
			cout << time - 1 << endl;
			cout << ans;
			break;
		}
		ans = melt;
	}
		
}