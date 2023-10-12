#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[50][2];

int main() {

	int t;
	cin >> t;
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	for (int i = 2; i < 41; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}
	for (int i = 0; i < t; i++) {
		int a;
		cin >> a;
		cout << dp[a][0] << " " << dp[a][1] << endl;
	}
}