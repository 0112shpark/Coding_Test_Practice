#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int arr[110][110];
long long dp[110][110] = { 0 };
//int visited[110][110] = { 0 };
int n; 




int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 0) {
				//move right
				if (i + arr[i][j] < n) {
					dp[i + arr[i][j]][j] += dp[i][j];
				}
				//move down
				if (j + arr[i][j] < n) {
					dp[i][j + arr[i][j]] += dp[i][j];
				}
			}
		}
	}
		
	cout << dp[n - 1][n - 1];

}