#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[310][310];
int visited[310][310] = { 0 };
int four[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
queue <pair<int, pair<int, int>>> zero_c;
queue <pair<int, int>> q;
int n, m;


void reset_visit() {

	for (int i = 0; i < 310; i++) {
		for (int j = 0; j < 310; j++) {
			visited[i][j] = 0;
		}
	}
}
void bfs(int s, int e) {
	visited[s][e] = 1;
	q.push({ s, e });
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		int cnt = 0;
			for (int i = 0; i < 4; i++) {
				int mov_x = x + four[i][0];
				int mov_y = y + four[i][1];
				if (mov_x < 0 || mov_y < 0 || mov_x >= n || mov_y >= m) {
					continue;
				}
				if (arr[mov_x][mov_y] == 0) {
					cnt ++ ;
				}
				if (arr[mov_x][mov_y] != 0 && visited[mov_x][mov_y] ==0 ) {
					visited[mov_x][mov_y] = 1;
					q.push({ mov_x,mov_y });
				}
			}
			zero_c.push({ cnt,{x,y} });
		
	}
}
void update() {
	while (!zero_c.empty()) {

		int amt = zero_c.front().first;
		int x = zero_c.front().second.first;
		int y = zero_c.front().second.second;
		arr[x][y] -= amt;
		if (arr[x][y] < 0) {
			arr[x][y] = 0;
		}
		zero_c.pop();
	}
}
int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int year = 0;
	while (1) {
		int wh = 0;
		reset_visit();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0 && visited[i][j] == 0) {
					wh++;
					bfs(i, j);
					update();


				}
			}
		}

		/*cout << wh << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << arr[i][j];
			}
			cout << endl;
		}*/
		if (wh > 1) {
			cout << year;
			exit(0);
		}
		else if (wh == 0) {
			cout << 0;
			exit(0);
		}
		year++;
	}

}