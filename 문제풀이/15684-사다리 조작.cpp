#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, h;
// i�� ������ j�� �����ٿ��� ���δٸ��� ���� ��
// map[1][2] = 1 =>1�� ������ 2�� ������ ���� 1������ �����. 
// �� 2������ 1������ ���� �ٸ��� 1�� �����ٿ� ����.
// ������ �� �����ٿ� �������� �ٸ��� �̾ ���� �� ������ �ϳ��� ����
int map[35][15];
int cnt = 0;
int ans = 99999999;

int check_down(int a) {
	int val = a;
	for (int i = 1; i <= h; i++) {
		if (map[i][val] != 0) {
			val = map[i][val];
		}
	}
	return val==a;
}

void dfs(int col,int idx) {

	if (idx <= 3) {
		int flag = 0;
		//cout << idx << endl;
		for (int i = 1; i <= n; i++) {
			if (!check_down(i)) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			ans = min(ans, idx);
			return;
		}
	}
	else {
		return;
	}
	for (int i = col; i < n; i++) {
		for (int j = 1; j <= h; j++) {
			if (map[j][i] == 0 && map[j][i+1]==0) {
				map[j][i] = i + 1;
				map[j][i + 1] = i;
				//cout << j << i << endl;
				dfs(i, idx + 1);
				//cout << "return" << endl;
				map[j][i] = 0;
				map[j][i + 1] = 0;
			}
		}
	}
}

int main() {
	
	cin >> n >> m >> h;
	//n�� ���μ� h�� ���μ�
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = b + 1;
		map[a][b + 1] = b;
	}

	dfs(1, 0);
	if (ans > 3) {
		ans = -1;
	}
	cout << ans;
}