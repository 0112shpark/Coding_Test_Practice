#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	int n; 
	int dp[10010];
	int arr[10010];
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	

	for (int i = 1; i < n; i++) {
		if (i == 1) {
			dp[1] = dp[0] + arr[1];
		}
		else if (i == 2) { dp[2] = dp[0] + arr[2]; }
		else {
			dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << dp[i] << endl;
	}
	sort(dp, dp+n, greater<>());
	cout << dp[0];

}