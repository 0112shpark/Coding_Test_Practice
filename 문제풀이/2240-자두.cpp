#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[3][1010][40];
int jadoo[1010];

int main() {
	int t, w;
	cin >> t >> w;
	for (int i = 1; i <= t; i++) {
		cin >> jadoo[i];
	}
	//j값이 1=0번 움직인거라 가정.
	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= w+1; j++) {
			if (jadoo[i] == 1) {
				dp[1][i][j] = max(dp[1][i - 1][j] + 1, dp[2][i - 1][j - 1] + 1);
				dp[2][i][j] = max(dp[2][i - 1][j], dp[1][i - 1][j - 1]);
			}
			else if(jadoo[i]==2){
				//처음에 2번에서 떨어지면 못먹음.
				if (i == 1 && j == 1) {
					continue;
				}
				dp[2][i][j] = max(dp[2][i - 1][j] + 1, dp[1][i - 1][j - 1] + 1);
				dp[1][i][j] = max(dp[1][i - 1][j], dp[2][i - 1][j - 1]);
			}
		}
	}
	int ans=0;
	for (int i = 1; i <= w+1; i++) {
		ans = max(ans, max(dp[1][t][i], dp[2][t][i]));
	}
	cout << ans;
}