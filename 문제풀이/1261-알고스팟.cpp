#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

char map[110][110];
deque<pair<int, int>> dq;
int dist[110][110];
int visited[110][110];
int four[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int n, m;

void bfs(int a, int b) {
	dq.push_front({ a,b });
	dist[a][b] = 0;
	visited[a][b] = 1;
	while (!dq.empty()) {
		int x = dq.front().first;
		int y = dq.front().second;
		dq.pop_front();
		for (int i = 0; i < 4; i++) {
			int mov_x = x + four[i][0];
			int mov_y = y + four[i][1];
			if (mov_x < 0 || mov_y < 0 || mov_x >= n || mov_y >= m||visited[mov_x][mov_y]) {
				continue;
			}
			if (map[mov_x][mov_y] == '0') {
				dist[mov_x][mov_y] = dist[x][y];
				visited[mov_x][mov_y] = 1;
				dq.push_front({ mov_x,mov_y });
			}
			if(map[mov_x][mov_y]=='1') {
				visited[mov_x][mov_y] = 1;
				dist[mov_x][mov_y] = dist[x][y] + 1;
				dq.push_back({ mov_x,mov_y });
			}
		}
	}
}

int main() {

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char a;
			cin >> a;
			map[i][j] = a;
		}
	}

	bfs(0, 0);
	cout << dist[n - 1][m - 1];
}
