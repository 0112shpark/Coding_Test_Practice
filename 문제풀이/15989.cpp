#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> ans;

	int dp[10001][4] = { 0 };
	int N;
	int val;
	cin >> N;

	dp[1][1] = 1;
	dp[2][1] = dp[2][2] = 1;
	dp[3][1] = dp[3][2] = dp[3][3] = 1;

	for (int i = 4; i < 10001; i++) {
		dp[i][1] = 1;
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2]+ dp[i-3][3];
	}
	
	for (int i = 0; i < N; i++) {
		cin >> val;

		ans.push_back(dp[val][1] + dp[val][2] + dp[val][3]);
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << '\n';
	}
}