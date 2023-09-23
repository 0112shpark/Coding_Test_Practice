#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int map[310][310];
int visited[310][310];
int mov[8][2] = { {1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1} };
int m;

void bfs(int i, int j) {

	queue<pair<int,int>> q;
	q.push({ i, j });
	visited[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 8; k++) {
			int mov_x = x + mov[k][0];
			int mov_y = y + mov[k][1];
			if (mov_x < 0 || mov_x >= m || mov_y < 0 || mov_y >= m) {
				continue;
			}
			if (visited[mov_x][mov_y] == 0) {
				visited[mov_x][mov_y] = visited[x][y] + 1;
				//cout << mov_x << "" << mov_y << endl;
				//cout << visited[mov_x][mov_y] << endl;
				q.push({ mov_x,mov_y });
			}

		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int i, j;
	int end1, end2;
	vector<int>ans;
	cin >> n;

	for (int k = 0; k < n; k++) {
		cin >> m;
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		cin >> i >> j;
		cin >> end1 >> end2;
		bfs(i, j);	
		ans.push_back(visited[end1][end2]-1);
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}
}