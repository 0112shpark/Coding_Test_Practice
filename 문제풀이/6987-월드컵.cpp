#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int ans[4] = {0};

//6*3 배열이 4가지 있음 4*6*3
int arr[4][6][3];

vector<pair<int, int>> game = {
	{0,1},{0,2},{0,3},{0,4},{0,5},
	{1,2},{1,3},{1,4},{1,5},
	{2,3},{2,4},{2,5},
	{3,4},{3,5},
	{4,5}
};
int dfs(int idx, int cnt) {

	if (cnt == 15) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (arr[idx][i][j] != 0) {
					return 0;
				}
			}
		}
		ans[idx] = 1;
			

		return 0;
	}

	//A wins
	if (arr[idx][game[cnt].first][0]>0 && arr[idx][game[cnt].second][2]>0) {
		arr[idx][game[cnt].first][0]--;
		arr[idx][game[cnt].second][2]--;
		dfs(idx, cnt + 1);
		arr[idx][game[cnt].first][0]++;
		arr[idx][game[cnt].second][2]++;
	}

	//B wins
	if (arr[idx][game[cnt].second][0] > 0 && arr[idx][game[cnt].first][2] > 0) {
		arr[idx][game[cnt].second][0]--;
		arr[idx][game[cnt].first][2]--;
		dfs(idx, cnt + 1);
		arr[idx][game[cnt].second][0]++;
		arr[idx][game[cnt].first][2]++;
	}

	//draw
	if (arr[idx][game[cnt].first][1] > 0 && arr[idx][game[cnt].second][1] > 0) {
		arr[idx][game[cnt].first][1]--;
		arr[idx][game[cnt].second][1]--;
		dfs(idx, cnt + 1);
		arr[idx][game[cnt].first][1]++;
		arr[idx][game[cnt].second][1]++;
	}
	return 0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> arr[i][j][k];
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		int temp = dfs(i, 0);

		cout << ans[i] << " ";
	}
}