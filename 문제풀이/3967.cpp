#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char map[5][9];
int sel[12];
vector <pair<int, int>> arr;
int x_cnt=0;
//순열 사용

int check()
{
	if ((map[0][4] - 'A' + 1) + (map[1][3] - 'A' + 1) + (map[2][2] - 'A' + 1) + (map[3][1] - 'A' + 1) != 26) 
		return 0;
	if ((map[0][4] - 'A' + 1) + (map[1][5] - 'A' + 1) + (map[2][6] - 'A' + 1) + (map[3][7] - 'A' + 1) != 26) 
		return 0;
	if ((map[1][1] - 'A' + 1) + (map[1][3] - 'A' + 1) + (map[1][5] - 'A' + 1) + (map[1][7] - 'A' + 1) != 26) 
		return 0;
	if ((map[3][1] - 'A' + 1) + (map[3][3] - 'A' + 1) + (map[3][5] - 'A' + 1) + (map[3][7] - 'A' + 1) != 26) 
		return 0;
	if ((map[4][4] - 'A' + 1) + (map[3][3] - 'A' + 1) + (map[2][2] - 'A' + 1) + (map[1][1] - 'A' + 1) != 26) 
		return 0;
	if ((map[4][4] - 'A' + 1) + (map[3][5] - 'A' + 1) + (map[2][6] - 'A' + 1) + (map[1][7] - 'A' + 1) != 26) 
		return 0;

	return 1;
}

int dfs(int idx, int cnt) {
	if (cnt == x_cnt) {

		if (check()) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 9; j++) {
					cout << map[i][j];
				}
				cout << endl;
			}
			exit(0);
		}
	}
	for (int i = 0; i < 12; i++) {
		if (sel[i] == 1) {
			continue;
		}
		sel[i] = 1;
		map[arr[idx].first][arr[idx].second] = i + 'A';
		dfs(idx+1, cnt + 1);
		map[arr[idx].first][arr[idx].second] = 'x';
		sel[i] = 0;
	}
}
int main() {

	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'x') {
				arr.push_back({ i,j });
				x_cnt++;
			}
			else if ('A' <= map[i][j] && map[i][j] <= 'L') {
				sel[map[i][j] - 'A'] = 1;
			}
		}
	}
	dfs(0, 0);
}