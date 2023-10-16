#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[10][10];
int four[4][2] = { {-1,0},{1,0} ,{0,1},{0,-1} };
int visited[10][10];
int n, m;
vector<pair<int, int>> virus;
int ans = 0;
int zero_cnt = 0;
queue<pair<int, int>> q;

void bfs(int a, int b) {

	q.push({ a,b });
	visited[a][b] = 1;

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
			if (visited[mov_x][mov_y] == 0 && map[mov_x][mov_y] == 0) {
				visited[mov_x][mov_y] = 1;
				map[mov_x][mov_y] = 3;
				q.push({ mov_x,mov_y });
			}
		}
	}
}
void check_zero() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				zero_cnt++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 3) {
				map[i][j] = 0;
			}
		}
	}
}
void reset_visited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
	
}

void dfs(int a, int b, int cnt) {

	if (cnt == 3) {
		reset_visited();
		zero_cnt = 0;
		for (int i = 0; i < virus.size(); i++) {
			int x = virus[i].first;
			int y = virus[i].second;
			bfs(x, y);
		}
		check_zero();
		ans = max(zero_cnt, ans);
		return;
	}
	for (int i = a; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				dfs(i, j, cnt + 1);
				map[i][j] = 0;
			}
		}
	}

}


int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}

	dfs(0,0,0);
	cout << ans;

}