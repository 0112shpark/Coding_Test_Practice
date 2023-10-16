#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int dp[5010];
int arr[5010];
string n;

int main() {

	cin >> n;
	for (int i = 1; i <= n.length(); i++) {
		arr[i] = (int)n[i-1] - 48;
	}
	if (arr[1] == 0) {
		cout << 0;
		return 0;
	}
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n.length(); i++) {
		if (arr[i] != 0) {
			dp[i] = (dp[i - 1] + dp[i])%1000000;
		}
		if (arr[i - 1] * 10 + arr[i] < 27 && arr[i - 1] * 10 + arr[i]>9) {
			dp[i] = (dp[i - 2] + dp[i])%1000000;
		}
	}
	cout << dp[n.length()];
	return 0;
}