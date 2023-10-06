#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n, k;
	
	//weight,value;
	int info[110][2] = { 0 };
	

	cin >> n >> k;

	int** dp = new int*[n+1];
	for (int i = 0; i <=n; i++) {
		dp[i] = new int[k+1];
	}
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> info[i][0] >> info[i][1];
	}
		
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			//내가 보는 물건의 무게가 허용 무게보다 많을 때
			if (info[i][0] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], info[i][1] + dp[i - 1][j - info[i][0]]);
			}
		}
	}
	cout << dp[n][k];
}