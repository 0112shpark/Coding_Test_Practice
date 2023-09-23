#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n, m;
int map[110][110];
vector<pair<int, int>> chik;
vector<pair<int, int>> house;
vector<int>pick;
int check[13] = { 0 };
int ans = 99999999;

int cal(pair<int, int> a, pair<int, int> b) {

	int ax = a.first;
	int ay = a.second;
	int bx = b.first;
	int by = b.second;

	return (abs(ax - bx) + abs(ay - by));
}
void select(int idx, int cnt) {


	if (cnt == m) {
		
		int res = 0;
		for (int k = 0; k < house.size(); k++) {
			int mindist = 999999999;
			for (int j = 0; j < pick.size(); j++) {
				
				mindist = min(mindist, cal(house[k], chik[pick[j]]));
			}
			
			res += mindist;
		}
		ans = min(res, ans);
		return;
	}


	for (int i = idx; i < chik.size(); i++) {
		if (check[i] == 1) {
			continue;
		}
		check[i] = 1;
		pick.push_back(i);
		select(i, cnt + 1);
		check[i] = 0;
		pick.pop_back();
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				house.push_back({ i,j });
			}
			else if (map[i][j] == 2) {
				chik.push_back({ i,j });
			}
		}
	}

	select(0, 0);
	cout << ans;

}