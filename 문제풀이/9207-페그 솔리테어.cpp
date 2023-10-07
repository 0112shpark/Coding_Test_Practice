#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//5*9
char map[10][12];
int n;
int cnt = 0;
int mov = 0;

int count_o(){
	int temp = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] == 'o') {
				temp++;
			}
		}
	}
	return temp;
}

void dfs(int idx) {
	

	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 9; y++) {

			if (map[x][y] == 'o') {
				// up
				if (x - 2 >= 0 && map[x - 2][y] == '.' && map[x - 1][y] == 'o' ) {
					//cout << "u";
					map[x - 2][y] = 'o';
					map[x - 1][y] = '.';
					map[x][y] = '.';
					dfs(idx + 1);
					map[x - 2][y] = '.';
					map[x - 1][y] = 'o';
					map[x][y] = 'o';
				}

				//down
				if (x + 2 < 5 && map[x + 2][y] == '.' && map[x + 1][y] == 'o') {
					map[x + 2][y] = 'o';
					map[x + 1][y] = '.';
					map[x][y] = '.';
					dfs(idx + 1);
					map[x + 2][y] = '.';
					map[x + 1][y] = 'o';
					map[x][y] = 'o';
				}
				//left
				if (y - 2 >= 0 && map[x][y - 2] == '.' && map[x][y - 1] == 'o' ) {
					//cout << "l";
					map[x][y - 2] = 'o';
					map[x][y - 1] = '.';
					map[x][y] = '.';
					dfs(idx + 1);
					map[x][y - 2] = '.';
					map[x][y - 1] = 'o';
					map[x][y] = 'o';
				}
				//right
				if (y + 2 < 9 && map[x][y + 2] == '.' && map[x][y + 1] == 'o' ) {
					
					map[x][y + 2] = 'o';
					map[x][y + 1] = '.';
					map[x][y] = '.';
					dfs(idx + 1);
					map[x][y + 2] = '.';
					map[x][y + 1] = 'o';
					map[x][y] = 'o';
				}
			}
		}
	}
	cnt = min(cnt,count_o());
	mov = max(idx, mov);
	return;
	
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<pair<int, int>> ans;

	cin >> n;
	for (int k = 0; k < n; k++) {

		cnt = 0;
		mov = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {

				cin >> map[i][j];
				if (map[i][j] == 'o') {
					cnt++;
					
				}
			}
		}

		dfs(0);
		ans.push_back({ cnt,mov });
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}


}