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
		//üũ�� ������ = 1���� *4��
		{{0,1}},
		{{0,-1}},
		{{-1,0}},
		{{1,0}}
	},
	{//camera 2
		//üũ�� ������ = 2���� *2��
		{{0,1},{0,-1}},
		{{1,0},{-1,0}}
	},
	{//camera 3
		//üũ�� ������ = 2���� *4��
		{{-1,0},{0,1}},
		{{0,1},{1,0}},
		{{1,0},{0,-1}},
		{{0,-1},{-1,0}}
	},
	{//camera 4
		//üũ�� ������ = 3���� *4��
		{{-1,0},{0,1},{1,0}},
		{{0,1},{1,0},{0,-1}},
		{{1,0},{0,-1},{-1,0}},
		{{0,-1},{-1,0},{0,1}}
	},
	{//camera 5
		//üũ�� ������ = 4����*1��
		{{0,1},{1,0},{0,-1},{-1,0}}
	}
};

int map[10][10];
//���������� �����ɶ� ���� -1����. 
//��ġ�� �κ� �ι� ���� �ʱ� ����. 
//������ų�� +1 �ص� ��ġ�� �κ��� -1 �̸��̹Ƿ�
//�� ī�޶� ���Ž��ѵ� ���� 0���� �۱⶧���� ���� ���� �ִٰ� �Ǻ�.

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
	

	for (int i = 0; i < dir[typ].size(); i++) {//camera type��  ȸ�� Ƚ��
		vector<pair<int, int>>checked;
		for (int j = 0; j < dir[typ][i].size(); j++) {//�� ȸ���� üũ�� ���� ��
			int x = camera[idx].second.first;
			int y = camera[idx].second.second;
			while (1) {// ���ÿ��� üũ
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