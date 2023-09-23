#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxv = -1000000000;
int minv = 1000000000;
//순서 상관있음 = 순열 사용
int arr[15];
int op[4] = { 0 }; //+,-,*,/
int cnt = 0;
int n;
int sum = 0;
void dfs(int sum, int cnt) {
	if (cnt == n - 1) {
		if (sum < minv) {
			minv = sum;
		}
		if (sum > maxv) {
			maxv = sum;
		}
	}
	else {
		if (op[0] > 0) {
			op[0] -= 1;
			dfs(sum + arr[cnt + 1],cnt+1);
			op[0] += 1;
		}
		if (op[1] > 0) {
			op[1] -= 1;
			dfs(sum - arr[cnt + 1], cnt + 1);
			op[1] += 1;
		}
		if (op[2] > 0) {
			op[2] -= 1;
			dfs(sum * arr[cnt + 1], cnt + 1);
			op[2] += 1;
		}
		if (op[3] > 0) {
			op[3] -= 1;
			dfs(sum / arr[cnt + 1], cnt + 1);
			op[3] += 1;
		}
	}
}

int main() {

	

	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	dfs(arr[0], 0);
	cout << maxv << endl << minv;
}