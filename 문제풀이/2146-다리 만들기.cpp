#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n;
queue<pair<int, int>> q;
int map[110][110];
int visited[110][110];
int cnt = 2;
int four[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int ans = 999;

void bfs(int a, int b, int val, int opt) {

	visited[a][b] = 1;
	q.push({ a,b });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int mov_x = x + four[i][0];
			int mov_y = y + four[i][1];
			if (mov_x < 0 || mov_y < 0 || mov_x >= n || mov_y >= n) {
				continue;
			}
			if (visited[mov_x][mov_y] == 0 && map[mov_x][mov_y] == 1 && opt == 0) {
				map[mov_x][mov_y] = val;
				visited[mov_x][mov_y] = 1;
				q.push({ mov_x,mov_y });
			}
			if (visited[mov_x][mov_y] == 0 && opt == 1) {
				if (map[mov_x][mov_y] >= 2 && map[mov_x][mov_y] != val) {

					ans = min(ans, visited[x][y]-1);
				}
				visited[mov_x][mov_y] = visited[x][y] + 1;
				q.push({ mov_x,mov_y });
			}
		}
	}
}
void reset_visited() {
	for (int i = 0; i < 110; i++) {
		for (int j = 0; j < 110; j++) {
			visited[i][j] = 0;
		}
	}
}
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				reset_visited();
				map[i][j] = cnt;
				bfs(i, j, cnt,0);
				cnt++;
			}
		}
	}
	for (int k = 2; k < cnt; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == k) {
					reset_visited();
					bfs(i, j, k, 1);
					
				}
			}

		}
	}
	cout << ans;
}
