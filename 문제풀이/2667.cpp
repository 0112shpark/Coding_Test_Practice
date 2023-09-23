#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

queue<pair<int, int>> q;
int** arr;
int** visited;
int four[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1} };
int ans = 1;
int flag = 0;

int found_flag = 0;
priority_queue<int, vector<int>, greater<int>> pq;


int main() {

	

	int n;

	scanf("%d", &n);
	arr = new int* [n];
	visited = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		visited[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
			visited[i][j] = 0;
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}*/
	while (ans != 0) {
		for (int k = 0; k < n; k++) {
			for (int c = 0; c < n; c++) {
				visited[k][c] = 0;
			}
		}
		
		found_flag = 0;
		
		ans = 0;
		q.push({ 0,0 });
		visited[0][0] = 1;
		int x, y;

		while (!q.empty()) {
			x = q.front().first;
			y = q.front().second;
			//cout << x << y << endl;
			q.pop();
			if (arr[x][y] == 1) {
				ans++;
				arr[x][y] = 0;
				found_flag = 1;
				visited[x][y] = 1;
				q = queue<pair<int, int>>();
			}
			flag = 0;
			
			for (int i = 0; i < 4; i++) {
				
				int move_x = x + four[i][0];
				int move_y = y + four[i][1];
				if (move_x < 0 || move_y < 0 || move_x >= n || move_y >= n) {
					continue;
				}
				
				if (visited[move_x][move_y] == 0&&!flag)
				{
					//cout << "move:" << move_x << move_y << endl;
					if (!found_flag) {
						q.push({ move_x, move_y });
					}
					if (found_flag == 0 && arr[move_x][move_y] == 1) {
						found_flag = 1;
						q = queue<pair<int, int>>();
						flag = 1;
						
					}
					if (arr[move_x][move_y] == 1 && found_flag == 1) {

						arr[move_x][move_y] = 0;
						
						q.push({ move_x, move_y });
						ans++;
					}

					visited[move_x][move_y] = 1;
				}

			}
		}
		pq.push(ans);
		/*cout << ans << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j];
			}
			cout << endl;
		}*/
		


	}
	printf("%d\n", pq.size()-1);
	pq.pop();
	int temp = pq.size();
	for (int i = 0; i < temp; i++) {
		printf("%d\n", pq.top()); 
			pq.pop();
	}

}	