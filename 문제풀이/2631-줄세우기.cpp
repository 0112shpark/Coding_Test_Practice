#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[210];
int dp[210];
int cnt = 0;

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {

				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		cnt = max(cnt, dp[i]);
	}
	cout << n-cnt;
}