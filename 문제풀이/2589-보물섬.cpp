#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int map[55][55];
queue<pair<int, int>> q;
int visited[55][55];
int ans = 0;
int n, m;
int four[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

void reset_visit() {
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 55; j++) {
			visited[i][j] = 0;
		}
	}
}

void bfs(int start, int end) {

	q.push({ start,end });
	
	visited[start][end] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int mov_x = x + four[i][0];
			int mov_y = y + four[i][1];
			if (mov_x < 0 || mov_x >= n || mov_y < 0 || mov_y >= m) {
				continue;
			}
			if (visited[mov_x][mov_y] == 0 &&map[mov_x][mov_y]==1) {
				visited[mov_x][mov_y] = visited[x][y] + 1;
				q.push({ mov_x,mov_y });
				ans = max(ans, visited[mov_x][mov_y]);
			}
		}
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char temp;
			cin >> temp;
			if (temp == 'W') {
				map[i][j] = 0;
			}
			else {
				map[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				bfs(i, j);
				reset_visit();
			}
		}
	}
	
	cout << ans-1;
}