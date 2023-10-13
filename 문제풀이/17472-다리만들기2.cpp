#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int map[12][12];
int four[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int visited[12][12];
int mst_visited[10];
int n, m;
int ans = 0;
queue<pair<int, int>> q;
//from, to;
int node[10][10];
//to, cost;
vector<pair<int, int>> arr[10];
//cost, to
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;


void bfs(int a, int b, int num) {

	q.push({ a,b });
	visited[a][b] = 1;
	map[a][b] = num;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int mov_x = x + four[i][0];
			int mov_y = y + four[i][1];
			if (mov_x >= n || mov_x < 0 || mov_y >= m || mov_y < 0) {
				continue;
			}
			if (!visited[mov_x][mov_y] && map[mov_x][mov_y]==-1) {
				map[mov_x][mov_y] = num;
				visited[mov_x][mov_y] = 1;
				q.push({ mov_x,mov_y });
			}
		}
	}
}
void make_bridge() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			node[i][j] = 1000;
		}
	}
	for (int i = 0; i < n; i++) {
		int group_n = 0; 
		int cnt = 1;
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0) {
				if (cnt > 1) {
					node[group_n][map[i][j]] = min(node[group_n][map[i][j]], cnt);
				}
				group_n = map[i][j];
				for (int k = j + 1; k < m; k++) {
					if (map[i][k] !=group_n || k >= m) {
						j = k;
						cnt = 1;
						break;
					}
				}
			}
			else if (group_n != 0) {
				cnt++;
			}
		}

	}
	for (int i = 0; i < m; i++) {
		int group_n = 0;
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			if (map[j][i] != 0) {
				if (cnt > 1) {
					node[group_n][map[j][i]] = min(node[group_n][map[j][i]], cnt);
				}
				group_n = map[j][i];
				for (int k = j + 1; k < n; k++) {
					if (map[k][i] != group_n || k >= n) {
						j = k;
						cnt = 1;
						break;
					}
				}
			}
			else if (group_n != 0) {
				cnt++;
			}
		}

	}
}

void put_in_arr() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (node[i][j] != 1000) {
				
				arr[i].push_back({ j,node[i][j] });
				arr[j].push_back({ i,node[i][j] });
			}
		}
	}
}
void mst(int a) {
	mst_visited[a] = 1;
	for (int i = 0; i < arr[a].size(); i++) {
		pq.push({ arr[a][i].second,arr[a][i].first });
	}

	while (!pq.empty()) {
		int to = pq.top().second;
		int cost = pq.top().first;

		pq.pop();
		if (mst_visited[to]) {
			continue;
		}
		mst_visited[to] = 1;
		ans += cost;
		for (int i = 0; i < arr[to].size(); i++) {
			pq.push({ arr[to][i].second,arr[to][i].first });
			
		}

	}

}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				map[i][j] = -1;
			}
		}
	}
	int num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == -1) {
				bfs(i, j, num);
				num++;
			}
		}
	}
	cout << num;
	make_bridge();
	put_in_arr();
	
	mst(1);
	for (int i = 1; i < num; i++) {
		if (mst_visited[i] == 0) {
			cout << -1;
			return 0;
		}
	}
	
		cout << ans;

	
}