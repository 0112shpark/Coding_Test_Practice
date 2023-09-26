#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int ans = 80;
//type, coord
vector < pair<int, pair<int, int>>> camera;
vector <vector<vector<pair<int, int>>>> dir = {
	
	{},

	{//camera 1
		//체크할 가짓수 = 1방향 *4번
		{{0,1}},
		{{0,-1}},
		{{-1,0}},
		{{1,0}}
	},
	{//camera 2
		//체크할 가짓수 = 2방향 *2번
		{{0,1},{0,-1}},
		{{1,0},{-1,0}}
	},
	{//camera 3
		//체크할 가짓수 = 2방향 *4번
		{{-1,0},{0,1}},
		{{0,1},{1,0}},
		{{1,0},{0,-1}},
		{{0,-1},{-1,0}}
	},
	{//camera 4
		//체크할 가짓수 = 3방향 *4번
		{{-1,0},{0,1},{1,0}},
		{{0,1},{1,0},{0,-1}},
		{{1,0},{0,-1},{-1,0}},
		{{0,-1},{-1,0},{0,1}}
	},
	{//camera 5
		//체크할 가짓수 = 4방향*1번
		{{0,1},{1,0},{0,-1},{-1,0}}
	}
};

int map[10][10];
//감시지역에 선정될때 마다 -1해줌. 
//겹치는 부분 두번 세지 않기 위함. 
//복구시킬때 +1 해도 겹치는 부분은 -1 미만이므로
//한 카메라 제거시켜도 값이 0보다 작기때문에 아직 보고 있다고 판별.

int check() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}


void dfs(int idx) {

	if (idx == camera.size()) {
		
		ans = min(ans, check());
		
		return;
	}
	int typ = camera[idx].first;
	

	for (int i = 0; i < dir[typ].size(); i++) {//camera type당  회전 횟수
		vector<pair<int, int>>checked;
		for (int j = 0; j < dir[typ][i].size(); j++) {//각 회전당 체크할 방향 수
			int x = camera[idx].second.first;
			int y = camera[idx].second.second;
			while (1) {// 감시영역 체크
				int tx = x + dir[typ][i][j].first;
				int ty = y + dir[typ][i][j].second;
				//cout << tx<<" "<< ty << endl;
				if (tx < 0 || ty < 0 || tx >= n || ty >= m) {
					break;
				}
				if (map[tx][ty] == 6) {
					break;
				}
				if (map[tx][ty] <= 0) {
					map[tx][ty]--;
					checked.push_back({ tx,ty });
				}
				x = tx;
				y = ty;
			}
		}
		dfs(idx + 1);

		for (int c = 0; c < checked.size(); c++) {
			map[checked[c].first][checked[c].second]++;
		}

	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6) {
				camera.push_back({ map[i][j],{i,j} });
			}
		}
	}
	dfs(0);
	cout << ans;
}