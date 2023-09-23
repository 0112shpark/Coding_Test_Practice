#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>

using namespace std;
int map[52][52] ;
int visited[52][52] ;
int dist[52][52];

int six[8][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };
int ans = 0;
int n, m;

int bfs(int i, int j) {
	queue < pair<int, int>> q;
	q.push({ i,j });
	memset(visited, 0, sizeof(visited));
	
	visited[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		for (int k = 0; k < 8; k++) {
			int mov_x = six[k][0] + x;
			int mov_y = six[k][1] + y;
			
			if (mov_x < 0 || mov_x >= n || mov_y < 0 || mov_y >= m ) {
				continue;
			}
			if (map[mov_x][mov_y] == 1) {
				
				return visited[x][y];
			}
			if (visited[mov_x][mov_y] == 0 || visited[mov_x][mov_y] > visited[x][y] + 1) {
				visited[mov_x][mov_y] = visited[x][y] + 1;
				
				q.push({ mov_x,mov_y });
			}
		}
	}
	
}


int main() {

	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < m; j++) {
			int temp1;
			cin >> temp1;
			map[i][j] = temp1;
			
		}
	
	}
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				
				ans = max(bfs(i,j),ans);
			}
		}
	}
	cout << ans;
}
