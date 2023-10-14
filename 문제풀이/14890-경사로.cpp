#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[110][110];
int stair[110][110]; 
int stair_row[110][110];
int n,l;
int ans = 0;
int check_col_avail(int x, int y, int h,int pos) {

	if (pos) {
		if (x - l >= 0) {
			for (int i = x - l; i < x; i++) {
				if (map[i][y] != h || stair[i][y] != 0) {
					return 0;
				}
			}
			return 1;
		}
	}
	else{
		if (x + l -1 <n ) {
			for (int i = x ; i < x+l; i++) {
				if (map[i][y] != h || stair[i][y] != 0) {
					return 0;
				}
			}
			return 1;
		}
	}
	return 0;
}
int check_row_avail(int x, int y, int h, int pos) {

	if (pos) {
		if (y - l >= 0) {
			for (int i = y - l; i < y; i++) {
				if (map[x][i] != h || stair_row[x][i] != 0) {
					return 0;
				}
			}
			return 1;
		}
	}
	else {
		if (y + l - 1 < n) {
			for (int i = y; i < y + l; i++) {
				if (map[x][i] != h || stair_row[x][i] != 0) {
					return 0;
				}
			}
			return 1;
		}
	}
	return 0;
}
void check_col() {

	for (int i = 0; i < n; i++) {
		int height = map[0][i];
		int fail_flag = 0;
		for (int j = 0; j < n; j++) {
			if (map[j][i] == height + 1) {
				//한칸 올라가면
				//cout << check_col_avail(j, i, height, 1) << " " << j << " " << i << endl;;
				
				if (check_col_avail(j, i, height, 1)) {
					for (int k =  j - l; k < j; k++) {
						stair[k][i]= 1;
					}
					height = map[j][i];
				}
				else {
					fail_flag = 1;
					break;
				}
			}
			else if (map[j][i] == height - 1) {
				//한칸 내려가면
				height = map[j][i];
				//cout << check_col_avail(j, i, height, 0) << " " << j << " " << i << endl;;
				if (check_col_avail(j, i, height, 0)) {
					for (int k = j; k < j + l; k++) {
						stair[k][i]=1;
					}
				}
				else {
					fail_flag = 1;
					break;
				}
			}
			else if (map[j][i] > height + 1 || map[j][i] < height - 1) {
				fail_flag = 1;
				break;
			}
		}
		if (!fail_flag) {
			
			
			ans++;
		}
		else {
			for (int j = 0; j < n; j++) {
				
					stair[j][i] = 0;
				
			}
		}
	}
}
void check_row() {

	for (int i = 0; i < n; i++) {
		int height = map[i][0];
		int fail_flag = 0;
		for (int j = 0; j < n; j++) {
			if (map[i][j] == height + 1) {
				//한칸 올라가면
				//cout << check_col_avail(j, i, height, 1) << " " << j << " " << i << endl;;
				
				if (check_row_avail(i, j, height, 1)) {
					for (int k = j - l; k < j; k++) {
						stair_row[i][k]=1;
					}
					height = map[i][j];
				}
				else {
					fail_flag = 1;
					break;
				}
			}
			else if (map[i][j] == height - 1) {
				//한칸 내려가면
				height = map[i][j];
				//cout << check_col_avail(j, i, height, 0) << " " << j << " " << i << endl;;
				if (check_row_avail(i, j, height, 0)) {
					for (int k = j; k < j + l; k++) {
						stair_row[i][k]=1;
					}
				}
				else {
					fail_flag = 1;
					break;
				}
			}
			else if (map[i][j] > height + 1 || map[i][j] < height - 1) {
				fail_flag = 1;
				break;
			}
		}
		if (!fail_flag) {
			
			ans++;
		}
		else {
			for (int j = 0; j < n; j++) {
				
					stair_row[i][j] = 0;
				
			}
		}
	}
}

int main() {

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	check_col();
	check_row();
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << stair[i][j];
		}
		cout << endl;
	}*/
	cout << ans;
	
}