#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int arr[1010][3];
	int dp[1010][3];

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		dp[0][i] = arr[0][i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			//choose 1
			if (j == 0) {
				dp[i][j] = min(dp[i-1][1] + arr[i][j], dp[i-1][2] + arr[i][j]);
			}
			else if (j == 1)
			{
				dp[i][j] = min(dp[i - 1][0] + arr[i][j], dp[i - 1][2] + arr[i][j]);
			}
			else if (j == 2) {
				dp[i][j] = min(dp[i - 1][0] + arr[i][j], dp[i - 1][1] + arr[i][j]);
			}
		}
	}
	int ans = 999999999;
	for (int i = 0; i < 3; i++) {
		if (dp[n - 1][i] < ans) {
			ans = dp[n - 1][i];
		}
	}
	cout << ans;
}