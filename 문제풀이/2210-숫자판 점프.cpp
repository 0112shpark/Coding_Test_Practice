#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int map[5][5];
int cnt = 0;
vector<string> ans;
int four[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

int check(string a) {
	for (int i = 0; i < ans.size(); i++) {
		if (a == ans[i]) {
			return 0;
		}
	}
	return 1;
}

void dfs(int a,int b,int cnt,string str) {

	if (cnt == 5) {
		if (check(str)) {
			ans.push_back(str);
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int mov_x = a + four[i][0];
		int mov_y = b + four[i][1];
		if (mov_x < 0 || mov_y < 0 || mov_x >= 5 || mov_y >= 5) {
			continue;
		}
		//str += to_string(map[mov_x][mov_y]);
		dfs(mov_x, mov_y, cnt + 1, str + to_string(map[mov_x][mov_y]));
 	}

}

int main() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
	
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			string str;
			str += to_string(map[i][j]);
			cnt = 0;
			
			dfs(i,j,cnt,str);
		}
	}
	cout << ans.size();
}