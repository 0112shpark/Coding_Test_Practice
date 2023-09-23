#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int**> arr;
vector<int**> visited;
queue<pair<int, pair<int, int>>> q;
int day_cnt = 0;
int change_flag = 1;
int imp_flag = 0;
int six[6][3] = {{-1,0,0}, {1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};

int main() {

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, h;
	int** floor;
	cin >> m >> n >> h;
	for (int j = 0; j < h; j++) {

		floor = new int* [n];
		int **temp = new int* [n];
		for (int i = 0; i < n; i++) {
			floor[i] = new int[m];
			temp[i] = new int[m];
		}

		for (int k = 0; k < n; k++) {
			for (int c = 0; c < m; c++) {
				cin >> floor[k][c];
				if (floor[k][c] == 1) {
					//cout << k << c<<endl;
					q.push({ j,{k,c} });
				}
				temp[k][c] = 0;
			}
		}
		arr.push_back(floor);
		visited.push_back(temp);
	}
	//cout << q.front().first << q.front().second.first << q.front().second.second << endl;
	/*for (int j = 0; j < h; j++) {
		for (int k = 0; k < n; k++) {
			for (int c = 0; c < m; c++) {
				cout << arr[j][k][c] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}*/
	//q.push({ 0, { 0, 0 } });

	while(change_flag ==1){
		change_flag = 0;
		for (int j = 0; j < h; j++) {
			for (int k = 0; k < n; k++) {
				for (int c = 0; c < m; c++) {
					visited[j][k][c] = 0;
				}
				
			}
		}
		//visited = { 0 };
		while (!q.empty()) {
			int x, y, z;
			z = q.front().first;
			x = q.front().second.first;
			y = q.front().second.second;
			//cout << x << y << z<<endl;
			visited[z][x][y] = 1;
			q.pop();
			change_flag = 0;
			for (int i = 0; i < 6; i++) {
				int move_z = z + six[i][0];
				int move_x = x + six[i][1];
				int move_y = y + six[i][2];
				if (move_z < 0 || move_z >= h || move_x < 0 || move_x >= n || move_y < 0 || move_y >= m) {
					continue;
				}
				if (!visited[move_z][move_x][move_y]) {
					if (arr[move_z][move_x][move_y] == 0) {
						change_flag = 1;
						arr[move_z][move_x][move_y] = arr[z][x][y]+1;
						day_cnt = arr[z][x][y];
						visited[move_z][move_x][move_y] = 1;
						q.push({ move_z,{move_x,move_y} });
					}
				}
			}
		}
		
	}
	for (int j = 0; j < h; j++) {
		for (int k = 0; k < n; k++) {
			for (int c = 0; c < m; c++) {
				if (arr[j][k][c] == 0) {
					cout << -1;
					return 0;
				}
			}

		}
	}
	if (day_cnt == 0) {
		cout << 0;
	}
	else {
		cout << day_cnt;
	}
}
