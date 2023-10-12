#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int map[510][510];
int n, m;
int ans = 0;
//x,y
void check_1(int x, int y) {
	int sum = 0;
	if (x + 1 >= n || y + 1 >= m) {
		return;
	}
	else {
		sum = map[x][y] + map[x + 1][y + 1] + map[x + 1][y] + map[x][y + 1];
		ans = max(sum, ans);
	}
}

void check_2_1(int x, int y) {
	int sum = 0;
	if (x >= n - 3) {
		return;
	}
	else {
		sum = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 3][y];
		ans = max(sum, ans);
	}
}
void check_2_2(int x, int y) {
	int sum = 0;
	if (y >= m - 3) {
		return;
	}
	else {
		sum = map[x][y] + map[x][y+1] + map[x][y+2] + map[x][y+3];
		ans = max(sum, ans);
	}
}

void check_3_1(int x, int y) {
	int sum = 0;
	if (x>=n-2||y>=m-1) {
		return;
	}
	else {
		sum = map[x][y] + map[x+1][y] + map[x+2][y] + map[x][y + 1];
		ans = max(sum, ans);
		sum = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1];
		ans = max(sum, ans);
		sum = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 2][y + 1];
		ans = max(sum, ans);
		sum = map[x][y+1] + map[x + 1][y+1] + map[x + 2][y+1] + map[x][y];
		ans = max(sum, ans);
		sum = map[x][y + 1] + map[x + 1][y + 1] + map[x + 2][y + 1] + map[x+1][y];
		ans = max(sum, ans);
		sum = map[x][y + 1] + map[x + 1][y + 1] + map[x + 2][y + 1] + map[x+2][y];
		ans = max(sum, ans);
	}
}

void check_3_2(int x, int y) {
	int sum = 0;
	if (x >= n - 1 || y >= m - 2) {
		return;
	}
	else {
		sum = map[x][y] + map[x][y+1] + map[x][y+2] + map[x+1][y];
		ans = max(sum, ans);
		sum = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x+1][y+1];
		ans = max(sum, ans);
		sum = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y+2];
		ans = max(sum, ans);
		sum = map[x+1][y] + map[x+1][y + 1] + map[x+1][y + 2] + map[x][y];
		ans = max(sum, ans);
		sum = map[x + 1][y] + map[x + 1][y + 1] + map[x + 1][y + 2] + map[x][y+1];
		ans = max(sum, ans);
		sum = map[x + 1][y] + map[x + 1][y + 1] + map[x + 1][y + 2] + map[x][y+2];
		ans = max(sum, ans);
	}
}

void check_4_1(int x, int y) {
	int sum = 0; 
	if (x >= n - 2 || y >= m - 1) {
		return;
	}
	else {
		sum = map[x][y] + map[x + 1][y] + map[x + 1][y + 1] + map[x + 2][y + 1];
		ans = max(sum, ans);
		sum = map[x][y+1] + map[x+1][y+1] + map[x+1][y] + map[x + 2][y];
		ans = max(sum, ans);
	}
}

void check_4_2(int x, int y) {
	int sum = 0;
	if (x >= n - 1 || y >= m - 2) {
		return;
	}
	else {
		sum = map[x][y] + map[x][y+1] + map[x + 1][y + 1] + map[x + 1][y + 2];
		ans = max(sum, ans);
		sum = map[x+1][y] + map[x + 1][y + 1] + map[x][y+1] + map[x][y+2];
		ans = max(sum, ans);
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check_1(i, j);
			check_2_1(i, j);
			check_2_2(i, j);
			check_3_1(i, j);
			check_3_2(i, j);
			check_4_1(i, j);
			check_4_2(i, j);
		}
	}
	cout << ans;

}