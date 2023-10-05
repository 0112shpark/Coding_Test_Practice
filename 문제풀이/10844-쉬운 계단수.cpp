#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long  dp[105][10];

int main() {

	int n; 
	cin >> n;
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
		dp[2][i] = 2;
	}
	dp[2][9] = 1;
	dp[2][0] = 1;
	for (int i = 3; i <=n; i++) {
		dp[i][0] = dp[i - 1][1];
		for (int j = 1; j < 10; j++) {
			if (j != 9) {
				
				dp[i][j] += dp[i - 1][j - 1]%1000000000;
				dp[i][j] += dp[i - 1][j + 1]%1000000000;
			}
			else if (j == 9) {
				//dp[i - 1][j - 1] = dp[i - 1][j - 1] % 1000000000;
				dp[i][j] += dp[i - 1][j - 1]%1000000000;
			}
		}
	}

	long long ans = 0;
	for (int i = 1; i < 10;i++) {
		//cout << dp[n][i]<<" ";
		ans += dp[n][i];
	}
	//cout << endl;
	cout << ans %1000000000;


}