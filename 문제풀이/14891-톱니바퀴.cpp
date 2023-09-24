#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int arr[4][8];
int k;
vector<pair<int, int>> spin;


// 시계방향 회전
void cw(int n) {
	
	int temp = arr[n][0];
	for (int i = 0; i < 8; i++) {
		int temp1 = arr[n][(i+1)%8];
		arr[n][(i + 1) % 8] = temp;
		temp = temp1;
	}
}

//시계 반대방향 회전
void ccw(int n) {

	int temp = arr[n][7];
	int zero = arr[n][0];
	for (int i = 7; i > 0; i--) {
		int temp1 = arr[n][(i - 1)];
		arr[n][i - 1] = temp;
		temp = temp1;
	}
	arr[n][7] = zero;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 4;i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < 8; j++) {
			if (temp[j] == '1') {
				arr[i][j] = 1;
			}
			else {
				arr[i][j] = 0;
			}
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int n, sp;
		cin >> n >> sp;
		spin.push_back({ n-1,sp });
	}
	
	for (int i = 0; i < spin.size(); i++) {
		int n = spin[i].first;
		int dir = spin[i].second;
		int stat[4];
		int stop_flag = 0;
		stat[n] = dir;
		int prev = n;
		int prev_d = dir;
		for (int j = n+1; j < 4; j++) {
			if (stop_flag) {
				stat[j] = 0;
				continue;
			}
			if (arr[prev][2] == arr[j][6]) {
				stat[j] = 0;
				stop_flag = 1;
			}
			else {
				stat[j] = prev_d * (-1);
			}
			prev = j;
			prev_d = stat[j];
		}
		stop_flag = 0;
		prev = n;
		prev_d = dir;
		for (int j = n - 1; j >= 0; j--) {
			if (stop_flag) {
				stat[j] = 0;
				continue;
			}
			if (arr[prev][6] == arr[j][2]) {
				stat[j] = 0;
				stop_flag = 1;
			}
			else {
				stat[j] = prev_d * (-1);
			}
			prev = j;
			prev_d = stat[j];

		}
		
		for (int k = 0; k < 4; k++) {
			if (stat[k] == 0) {
				continue;
			}
			if (stat[k] == 1) {
				cw(k);
			}
			else {
				ccw(k);
			}
		}
		/*for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cout << arr[i][j];
			}
			cout << endl;
		}
		cout << "<<" << endl;*/
	}
	int ans = 0;
	if (arr[0][0] == 1) {
		ans = +1;
	}
	if (arr[1][0] == 1) {
		ans += 2;
	}
	if (arr[2][0] == 1) {
		ans +=4;
	}
	if (arr[3][0] == 1) {
		ans += 8;
	}
	

	cout << ans;

}